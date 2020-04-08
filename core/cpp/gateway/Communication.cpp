#include <random>
#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <shared_mutex>

#include <core/hpp/gateway/Communication.hpp>

using namespace Gateway;
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> uniform(0, 1e9);

shared_mutex critical;
mutex outmutex;

template<typename T>
struct SynchronizedQueue {
    void push(T &&item) {
        mutex_.lock();
        q.push(forward(item));
        mutex_.unlock();

        cv.notify_one();
    }

    T pop() {
        cv.wait(mutex_, []{q.size() > 0;});
        T ret = q.front();
        q.pop();
        mutex_.unlock();

        return ret;
    }
private:
    queue<T> q;
    mutex mutex_;
    condition_variable cv;
};

SynchronizedQueue<json> responseQueue; // response for action; client -> server; i.e. select 4th card from suggestion
SynchronizedQueue<json> requestQueue;  // request  for information; client -> server; i.e. how much megacredits player 4 have?

void reader();
void responsor();

void initGateway(int reponseThreadCount) {
    critical.lock();
    thread t1(reader);

    t1.detach();

    for (int i = 0; i < reponseThreadCount; i++) {
        thread t(responsor);
        t.detach();
    }
}

// server -> client
json command(int player, const json &content) {
    int id = uniform(gen);
    queue<int> a;

    json request = {
        {"player", player},
        {"id", id},
        {"type", "command"},
        {"content", content}
    };

    outmutex.lock();
    cout << request << endl;
    outmutex.unlock();

    critical.unlock();
    json ret = responseQueue.pop();
    critical.lock();

    return ret;
}

void command(int size, int *player, json *req, json *res) {
    int ids[10];

    outmutex.lock();
    for (int i = 0; i < size; i++) {
        ids[i] = uniform(gen);
        json request = {
            {"player", player[i]},
            {"id", ids[i]},
            {"type", "command"},
            {"content", req[i]}
        };

        cout << request << endl;
    }
    outmutex.unlock();

    critical.unlock();
    for (int i = 0; i < size; i++) {
        json ret = responseQueue.pop();
        int _pl = ret["player"];
        int _id = ret["id"];

        for (int j = 0; j < size; j++) {
            if (player[j] == _pl and ids[j] == _id) {
                res[j] = ret;
                break;
            }
        }
    }
    critical.lock();
}

void notify(int player, const json &msg) {
    outmutex.lock();
    json req = {
        {"player", player},
        {"type", "notify"},
        {"content", msg}
    };
    cout << req << endl;
    outmutex.unlock();
}

void reader() {
    while(true) {
        json j; cin >> j;

        if (j["type"] == "response") {
            responseQueue.push(move(j));
        } else {
            requestQueue.push(move(j));
        }
    }
}

void responsor() {
    while(true) {
        json req = requestQueue.pop();
        critical.lock_shared();

        // handle request

        critical.unlock_shared();
    }
}