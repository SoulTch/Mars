#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
void Swap(T &a, T &b) {
    auto c(move(a));
    a = move(b);
    b = move(c);
}

template<typename T>
struct Vector {
    int _size;
    int _reserved;

    T *ptr;

    Vector() {
        _reserved = 10;
        _size = 0;
        ptr = new T[_reserved];
    }

    Vector(const Vector<T> &a) {
        ptr = new T[a._reserved];
        _size = a._size;
        for (int i = 0; i < a._size; i++) {
            ptr[i] = a[i];
        }
    }

    Vector(Vector<T> &&a) {
        cout << "MOVE" << endl;
        delete ptr;

        ptr = a.ptr;
        _size = a._size;
        _reserved = a._reserved;
        a.ptr = nullptr;
    }

    ~Vector() {
        delete ptr;
    }

    void push_back(const T& item) {
        if (_reserved == _size) {
            T *x = new T[_reserved*2];
            for (int i = 0; i < _reserved; i++) {
                x[i] = ptr[i];
            }
            delete ptr;
            _reserved *= 2;
            ptr = x;
        }

        ptr[_size++] = item;
    }

    T& operator[](int idx) const {
        return ptr[idx];
    }

    Vector<T>& operator=(const Vector<T> &a) {
        delete ptr;

        ptr = new T[a._reserved];
        _size = a._size;
        for (int i = 0; i < a._size; i++) {
            ptr[i] = a[i];
        }
        return *this;
    }

    Vector<T> &operator=(Vector<T> &&a) {
        cout << "MOVE ASSIGN" << endl;
        delete ptr;

        ptr = a.ptr;
        _size = a._size;
        _reserved = a._reserved;
        a.ptr = nullptr;
        return *this;
    }
    

    using iterator = T*;

    iterator begin() {
        return ptr;
    }

    iterator end() {
        return ptr+_size;
    }
};



int main(void) {
    Vector<int> a;
    a.push_back(3);
    a.push_back(5);

    Vector<int> b;
    b = a;
    a[1] = 7;

    swap(a, b);
    return 0;
    cout << "A : ";
    for (int &t : a) {
        cout << t << ' ';
    }
    cout << endl;

    cout << "B : ";
    for (int &t : b) {
        cout << t << ' ';
    }
    cout << endl;

}

