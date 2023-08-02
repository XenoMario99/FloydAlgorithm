#include "floyd.h"

void floyd::floyd(std::vector<std::vector<int>>& input, std::vector<std::vector<int>>& distances) {
    int size = input.size();

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (input[i][j] != 0) {
                    if (input[i][k] != -1 && input[k][j] != -1) {
                        if (input[i][j] == -1 || (input[i][j] != -1 && input[i][j] > (input[i][k] + input[k][j]))) {
                            input[i][j] = input[i][k] + input[k][j];
                            distances[i][j] = k + 1;
                        }
                    }
                }
            }
        }
    }
}

void floyd::path(std::vector<std::vector<int>>& distances, int vBeg, int vEnd) {
    if (distances.at(vBeg).at(vEnd) != 0) {
        path(distances, vBeg, distances[vBeg][vEnd] - 1);
        std::cout << "v" << distances[vBeg][vEnd] << " ";
        path(distances, distances[vBeg][vEnd] - 1, vEnd);
    }
}