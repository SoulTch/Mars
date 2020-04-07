#pragma once

#include <vector>
#include <string>
#include <functional>
#include <map>

#define MAX_SIZE 15
#define MAX_PLAYER 5

namespace MarsCore {

enum class TileType {
//  default
    Greenary,
    City,
    Ocean,

//  Original

};

class TileArche {
public:
    std::function<bool(int)> placeable;
    std::function<bool(int, int, int)> placeablexy;
    std::function<void(int)> place;

    std::function<Point(int)> getPoint;
};



class Tile {
public:
    TileArche *type;
    int owner;
};

class Cell {
public:
    std::string name;
    bool reserved;
    Tile *occupied = nullptr;
};

class CellManager {
public:
    void init(int width, int height, Cell (&tile)[MAX_SIZE][MAX_SIZE]);
    void disable(int x, int y);
    bool placeable();
    
    int remain;
    bool available[MAX_SIZE][MAX_SIZE];
};

class Board {
public:
    int width, height;
    Cell tile[MAX_SIZE][MAX_SIZE];
    CellManager cities[MAX_PLAYER];
    CellManager greens[MAX_PLAYER];

    void init(int, int);

    bool city_placeable(int);
    bool tile_placeable(int);

    bool placeable(int player, TileArche *tiletype);

    class Coordinate {
    public:
        int r, c;    
    };

    std::vector<Coordinate> candidate(int player, TileArche *tiletype);
    
    void place(int player, TileArche *tiletype, int x, int y);
};



}