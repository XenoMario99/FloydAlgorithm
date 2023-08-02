#include <iostream>
#include <vector>

namespace floyd {

void floyd(std::vector<std::vector<int>>& vec, std::vector<std::vector<int>>& distances);
void path(std::vector<std::vector<int>>& distances, int vBeg, int vEnd);

}