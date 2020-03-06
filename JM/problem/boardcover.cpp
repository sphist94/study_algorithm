// NOTE: Book(Algorithmic Problem Solving Strategies 1, 6.4)
// NOTE: https://algospot.com/judge/problem/read/BOARDCOVER
// NOTE: Solver: Han(sphist94@gmail.com)
// NOTE: * Algorithm(Brute Force)

#include <iostream>
#include <string>
#include <vector>

const int dx[4][2] = {{0, 1}, {-1, -1}, {0, 1}, {1, 1}};
const int dy[4][2] = {{1, 1}, {0, 1}, {-1, -1}, {0, 1}};

int C;
int H, W;
std::vector<std::vector<char>> board;

void readInput() {
    std::cin >> H >> W;
    board.resize(H, std::vector<char>(W));
    for (int i = 0; i < H; ++i) {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < W; ++j) {
            board[i][j] = str.at(j);
        }
    }
}

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= H || col < 0 || col >= W) {
        return true;
    }
    return false;
}

bool canCovered(int type, int row, int col) {
    for (int i = 0; i < 2; ++i) {
        int _row = dx[type][i];
        int _col = dy[type][i];
        if (isOutOfRange(_row, _col) || board[_row][_col] == '#') {
            return false;
        }
    }
    return true;
}

bool cover(bool covering, int type, int row, int col) {
    for (int i = 0; i < 2; ++i) {
        int _row = dx[type][i];
        int _col = dy[type][i];
        board[_row][_col] = covering ? '#' : '.';
    }
}

bool isCoveredAll() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

int coverBoard(int row, int col) {
    if (isOutOfRange(row, col)) {
        return 0;
    }

    if (isCoveredAll()) {
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        if (canCovered(i, row, col)) {
            cover(true, i, row, col);
            ret += coverBoard(row, col);
            cover(false, i, row, col);
        }
    }
    return ret;
}

int main() {
    std::cin >> C;
    while (C--) {
        readInput();
        int ans = coverBoard(0, 0);
        std::cout << ans << std::endl;
    }
}
