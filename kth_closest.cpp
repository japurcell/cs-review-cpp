#include <cmath>
#include <map>
#include <vector>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
{
    // d = sqrt((q1 - p1)^2 + (q2 - p2)^2)
    
    int n = points.size();
    vector<vector<int>> result;
    map<double, vector<int>> distance_points;
    
    if (K < 1) return result;
    
    for (int i = 0; i < n; i++)
    {
        double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
        distance_points[distance].push_back(i);
    }
    
    int added = 0;
    for (auto const& kvp : distance_points)
    {
        for (auto const& point : kvp.second)
        {
            result.push_back({ points[point] });

            if (++added == K)
                break;
        }
    }
    
    return result;
}