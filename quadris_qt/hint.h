#ifndef HINT_H
#define HINT_H

#include <vector>
#include <utility>


class Hint {
private:
    bool isReachable(const std::vector<std::vector<char>>& board,
                     const std::vector<std::pair<int, int>>& block,
                     int x, int y);

    bool canPlace(const std::vector<std::vector<char>>& board,
                  const std::vector<std::pair<int, int>>& block,
                  int x, int y);

    int adjacencyBonus(const std::vector<std::vector<char>>& board,
                       const std::vector<std::pair<int, int>>& placement);

    int countHolesBelow(const std::vector<std::vector<char>>& board,
                        const std::vector<std::pair<int, int>>& placement);

    int computeScore(const std::vector<std::vector<char>>& board,
                     const std::vector<std::pair<int, int>>& placement);

    std::vector<std::pair<int, int>> getBestPlacement(const std::vector<std::vector<char>>& board,
                                                      const std::vector<std::vector<std::pair<int, int>>>& rotations);

public:
    Hint();

    std::vector<std::pair<int, int>> getHint(const std::vector<std::vector<char>>& board,
                                             const char blockType);
};

#endif // HINT_H
