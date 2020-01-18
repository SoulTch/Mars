#pragma once

#include <string>
#include <map>

using namespace std;

enum class TileType {
//  default
    Greenary,
    City,
    Ocean,

//  Original

};

class Tile {
public:
    bool isCity;
    int owner;
    TileType type;
};

class BoardTile {
public:
    int x, y;
    map<string, int> properties;

    Tile *tile;
    function<void(int)> bonus;
};

class Board {
public:
    int width, height;
    BoardTile tile[15][15];

    int greenary_count, city_count;

    bool placeable();
    bool city_placeable();

    void place(int, int, Tile *, int);
};