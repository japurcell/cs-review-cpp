#include <vector>

using namespace std;

void duplicateZeroes(vector<int>& arr)
{
    int len = arr.size();

    if (len <= 1)
    {
        return;
    }

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = len - 1; j > i; j--)
            {
                arr[j] = arr[j-1];
            }

            i++;
        }        
    }
}

void duplicateZeroesV2(vector<int>& arr)
{
    int zeroCount = 0, n = arr.size();

    for (int i:arr)
    {
        if (i == 0)
        {
            ++zeroCount;
        }
    }

    for (int i = n - 1, j = n - 1 + zeroCount; i >= 0; --i, --j)
    {
        if (arr[i] == 0)
        {
            if (j < n)
            {
                arr[j] = 0;
            }

            --j;
        }

        if (j < n)
        {
            arr[j] = arr[i];
        }
    }
}