#include <core/hpp/model/BoardTile.hpp>

namespace MarsCore {

void CellManager::init(int width, int height, Cell (&tile)[MAX_SIZE][MAX_SIZE]) {
    remain = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            available[i][j] = not tile[i][j].reserved;
            remain += available[i][j];
        }
    }
}

void CellManager::disable(int x, int y) {
    remain -= available[x][y];
    available[x][y] = false;
}

bool CellManager::placeable() {
    return remain > 0;
}

void Board::init(int w, int h) {
    width = w;
    height = h;
    for (int i = 0; i < numOfPlayers; i++) {
        cities[i].init(width, height, tile);
        greens[i].init(width, height, tile);
    }
}

bool Board::city_placeable(int player) {
    return cities[player].placeable();
}

bool Board::tile_placeable(int player) {
    return greens[player].placeable();
}

bool Board::placeable(int player, TileArche *tiletype) {
    return tiletype->placeable(player);
}

std::vector<Board::Coordinate> Board::candidate(int player, TileArche *tiletype) {
    std::vector<Board::Coordinate> ret;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tiletype->placeablexy(player, i, j)) {
                ret.emplace_back(i, j);
            }
        }
    }

    return ret;
}

static int dr[6] = {1, -1, 1, -1, 0, 0};
static int dc[6] = {0, 0, -1, 1, 1, -1};

void Board::place(int player, TileArche *tiletype, int r, int c) {
    Tile *n = new Tile {tiletype, player};
    tile[r][c].occupied = n;
}