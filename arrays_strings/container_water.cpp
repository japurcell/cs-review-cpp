    #include <algorithm>
    #include <vector>

    using namespace std;
    
    int maxArea(vector<int>& height)
    {
        int n = height.size() - 1;
        int left = 0;
        int right = (n > 0 ? n : 1) - 1;
        int currentMax = 0;

        while (left != right)
        {
            int diff = right - left;
            int limit = 0;

            if (height[left] > height[right])
            {
                limit = height[right];
                right--;
            }
            else
            {
                limit = height[left];
                left++;
            }
            
            int max = limit * diff;

            if (max > currentMax)
            {
                currentMax = max;
            }
        }

        return currentMax;
    }