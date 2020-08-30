#include <vector>
#include <queue>
using namespace std;

// track x,y coordinates and match on intersections to determine distinct

int numIslands(vector<vector<char>>& grid)
{
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int island_count = 0;

    for (auto r = 0; r < nr; r++)
    {
        for (auto c = 0; c < nc; c++)
        {
            if (grid[r][c] == '1')
            {
                ++island_count;
                grid[r][c] = '0';
                queue<pair<int, int>> neighbors;
                neighbors.push({r, c});

                while (!neighbors.empty())
                {
                    auto next = neighbors.front();
                    neighbors.pop();

                    int row = next.first, col = next.second;
                    if (row - 1 >= 0 && grid[row-1][col] == '1')
                    {
                        neighbors.push({row-1, col});
                        grid[row-1][col] = '0';
                    }
                    if (row + 1 < nr && grid[row+1][col] == '1')
                    {
                        neighbors.push({row+1, col});
                        grid[row+1][col] = '0';
                    }
                    if (col - 1 >= 0 && grid[row][col-1] == '1')
                    {
                        neighbors.push({row, col-1});
                        grid[row][col-1] = '0';
                    }
                    if (col + 1 < nc && grid[row][col+1] == '1')
                    {
                        neighbors.push({row, col+1});
                        grid[row][col+1] = '0';
                    }
                }
            }
        }
    }

    return island_count;
}