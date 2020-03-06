// NOTE: Book(Algorithmic Problem Solving Strategies 1, 6.2)
// NOTE: https://algospot.com/judge/problem/read/BOGGLE
// NOTE: Solver: Han(sphist94@gmail.com)
// NOTE: * Algorithm(Brute Force)
// NOTE: 1. is the element out of range from matrix?
// NOTE: 1-1. if yes, exit
// NOTE: 1-2. if no, continue 2
// NOTE: 2. is equal the first character of word with the element of matrix?
// NOTE: 2-1. if no, exit
// NOTE: 2-2. if yes, continue 3
// NOTE: 3. is equal the length of word 1?
// NOTE: 3-1. if yes, return true.
// NOTE: 3-2. if no, go one step from element and put substring starting from 1 to end. continue to 1.
// NOTE: * Time Complexity: 8^n

// REVIEW: Cannot Solve this problme in time limit
// REVIEW: We should choose another algorithm strategies

#include <iostream>
// #include <fstream>
#include <string>
#include <vector>

const int cMAX_ROW = 5;
const int cMAX_COL = 5;

int C, len;
char matrix[cMAX_ROW][cMAX_COL];
std::vector<std::string> word;

// NOTE: index '0' : North, '1': North-East, '2': East, '3': South-East
// NOTE: index '4' : South, '5': South-West, '6': West, '7': North-West
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void readInput() {
    std::cin >> C;
    std::string line;
    for (int i = 0; i < 5; ++i) {
        std::cin >> line;
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = line.at(j);
        }
    }

    std::cin >> len;
    for (int i = 0; i < len; ++i) {
        std::cin >> line;
        word.push_back(line);
    }
}

void checkInput() {
    std::cout << C << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << len << std::endl;
    for (int i = 0; i < len; ++i) {
        std::cout << word[i] << std::endl;
    }
}

// NOTE: function, check the out of range
bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= cMAX_ROW || col < 0 || col >= cMAX_COL) {
        return true;
    }
    return false;
}

bool findWord(const std::string &word, int row, int col) {
    // NOTE: 1. is the element out of range from matrix?
    // NOTE: 1-1. if yes, exit
    if (isOutOfRange(row, col)) {
        return false;
    }

    // NOTE: 1-2. if no, continue 2
    // NOTE: 2. is equal the first character of word with the element of matrix?
    // NOTE: 2-1. if no, exit
    if (matrix[row][col] != word.at(0)) {
        return false;
    }

    // NOTE: 2-2. if yes, continue 3
    // NOTE: 3. is equal the length of word 1?
    // NOTE: 3-1. if yes, return true.
    if (word.length() == 1) {
        return true;
    }

    // NOTE: 3-2. if no, go one step from element and put substring starting from 1 to end. continue to 1.
    bool ret = false;
    for (int i = 0; i < 8 && !ret; ++i) {
        int _row = row + dy[i];
        int _col = col + dx[i];
        ret = findWord(word.substr(1), _row, _col);
    }
    return ret;
}

int main() {
    readInput();

    std::vector<bool> ans;
    for (int i = 0; i < len; ++i) {
        bool _ans = false;
        for (int row = 0; row < 5 && !_ans; ++row) {
            for (int col = 0; col < 5 && !_ans; ++col) {
                _ans = findWord(word[i], row, col);
            }
        }
        ans.push_back(_ans);
    }

    for (int i = 0; i < len; ++i) {
        std::cout << word[i] << " " << (ans[i] ? "YES" : "NO") << std::endl;
    }
    return 0;
}