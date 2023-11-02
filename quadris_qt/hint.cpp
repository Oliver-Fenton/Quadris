#include "hint.h"

#include <iostream>
#include <set>
#include <queue>
#include <map>


struct QuadrisBlocks {
    static const std::vector<std::vector<std::pair<int, int>>> I;
    static const std::vector<std::vector<std::pair<int, int>>> J;
    static const std::vector<std::vector<std::pair<int, int>>> L;
    static const std::vector<std::vector<std::pair<int, int>>> O;
    static const std::vector<std::vector<std::pair<int, int>>> T;
    static const std::vector<std::vector<std::pair<int, int>>> S;
    static const std::vector<std::vector<std::pair<int, int>>> Z;
};

const std::vector<std::vector<std::pair<int, int>>> QuadrisBlocks::I = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}
};

const std::vector<std::vector<std::pair<int, int>>> QuadrisBlocks::J = {
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}}
};

const std::vector<std::vector<std::pair<int, int>>> QuadrisBlocks::L = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}}
};

const std::vector<std::vector<std::pair<int, int>>> QuadrisBlocks::O = {
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}
};

const std::vector<std::vector<std::pair<int, int>>> QuadrisBlocks::T = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}}
};

const std::vector<std::vector<std::pair<int, int>>> QuadrisBlocks::S = {
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}
};

const std::vector<std::vector<std::pair<int, int>>> QuadrisBlocks::Z = {
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {0, 1}, {1, 1}, {2, 0}}
};

Hint::Hint() {}

bool Hint::isReachable(const std::vector<std::vector<char>> &board,
                       const std::vector<std::pair<int, int>> &block,
                       int x, int y)
{
    std::queue<std::pair<int, int>> q;
    std::set<std::pair<int, int>> visited;

    q.push({0, y});
    visited.insert({0, y});

    std::vector<std::pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        auto [currX, currY] = q.front();
        q.pop();

        if (currX == x && currY == y) return true;

        for (auto [dx, dy] : dirs) {
            int newX = currX + dx;
            int newY = currY + dy;

            if (visited.find({newX, newY}) != visited.end()) continue;

            bool canMove = true;
            for (auto [bx, by] : block) {
                int boardX = newX + bx;
                int boardY = newY + by;

                if (boardX < 0 || boardX >= board.size() || boardY < 0 || boardY >= board[0].size()) {
                    canMove = false;
                    break;
                }

                if (board[boardX][boardY] != ' ' && board[boardX][boardY] != '?') {
                    canMove = false;
                    break;
                }
            }

            if (canMove) {
                q.push({newX, newY});
                visited.insert({newX, newY});
            }
        }
    }
    return false;
}

bool Hint::canPlace(const std::vector<std::vector<char>> &board,
                    const std::vector<std::pair<int, int>> &block,
                    int x, int y)
{
    for (const auto& coord : block) {
        int newX = x + coord.first;
        int newY = y + coord.second;

        if (newX < 0 || newX >= board.size() || newY < 0 || newY >= board[0].size() || board[newX][newY] != ' ') {
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && board[newX][newY] == '?') continue;
            return false;
        }
    }

    return isReachable(board, block, x, y);
}

int Hint::countHolesBelow(const std::vector<std::vector<char>> &board,
                          const std::vector<std::pair<int, int>> &placement)
{
    int holes = 0;

    std::set<int> occupiedColumns;
    for (const auto &coord : placement) {
        occupiedColumns.insert(coord.second);
    }

    for (int col : occupiedColumns) {
        int maxRowInColumn = -1;
        for (const auto &coord : placement) {
            if (coord.second == col) {
                maxRowInColumn = std::max(maxRowInColumn, coord.first);
            }
        }

        for (int row = maxRowInColumn + 1; row < board.size(); ++row) {
            if (board[row][col] == ' ') {
                holes++;
            } else {
                break;
            }
        }
    }

    return holes;
}

int Hint::adjacencyBonus(const std::vector<std::vector<char>>& board,
                         const std::vector<std::pair<int, int>>& placement)
{
    int bonus = 0;
    std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (const auto& coord : placement) {
        for (const auto& dir : directions) {
            int newX = coord.first + dir[0];
            int newY = coord.second + dir[1];
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()) {
                if (board[newX][newY] != ' ' && board[newX][newY] != '?') {
                    bonus += 1;
                }
            }
        }

        if (coord.first == board.size() - 1) {
            bonus += 2;
        }
    }

    return bonus;
}

int Hint::computeScore(const std::vector<std::vector<char>>& board,
                       const std::vector<std::pair<int, int>>& placement)
{
    int score = 0;
    std::vector<int> rowsFilled(board.size(), 0);

    for (const auto& coord : placement) {
        rowsFilled[coord.first]++;
    }

    for (int filled : rowsFilled) {
        if (filled == board[0].size()) {
            score += 250;
        }
    }

    for (const auto& coord : placement) {
        score += coord.first * 10;
    }

    score += adjacencyBonus(board, placement) * 10;

    int holes = countHolesBelow(board, placement);
    score -= holes * 50;

    return score;
}

std::vector<std::pair<int, int>> Hint::getBestPlacement(const std::vector<std::vector<char>> &board,
                                                        const std::vector<std::vector<std::pair<int, int>>> &rotations)
{
    std::vector<std::pair<int, int>> bestPlacement;
    int bestScore = INT_MIN;

    for (int x = board.size() - 1; x >= 0; x--) {
        for (int y = 0; y < board[0].size(); y++) {
            for (const auto& rotation : rotations) {
                if (canPlace(board, rotation, x, y)) {
                    std::vector<std::pair<int, int>> currentPlacement;
                    for (const auto& coord : rotation) {
                        int newX = x + coord.first;
                        int newY = y + coord.second;
                        currentPlacement.push_back({newX, newY});
                    }
                    int currentScore = computeScore(board, currentPlacement);

                    if (currentScore > bestScore) {
                        bestScore = currentScore;
                        bestPlacement = currentPlacement;
                    }
                }
            }
        }
    }

    return bestPlacement;
}

std::vector<std::pair<int, int>> Hint::getHint(const std::vector<std::vector<char>> &board,
                                               const char blockType)
{
    switch (blockType) {
    case 'I': return getBestPlacement(board, QuadrisBlocks::I);
    case 'J': return getBestPlacement(board, QuadrisBlocks::J);
    case 'L': return getBestPlacement(board, QuadrisBlocks::L);
    case 'O': return getBestPlacement(board, QuadrisBlocks::O);
    case 'T': return getBestPlacement(board, QuadrisBlocks::T);
    case 'S': return getBestPlacement(board, QuadrisBlocks::S);
    case 'Z': return getBestPlacement(board, QuadrisBlocks::Z);
    default: return {};  // shouldn't reach here for valid block types
    }
}

