#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> map;

    for (auto i = 0; i < nums.size(); i++)
    {
        int temp = target - nums[i];
        if (map.find(temp) != map.end())
        {
            return { i, map[temp] };
        }

        map[nums[i]] = i;
    }

    return { };
}

int lengthOfLongestSubstring(string s)
{
    size_t size = s.size();
    int total = 0;

    for (size_t i = 0; i < size; i++)
    {
        int current_total = 0;
        int chars[128]={0};
        int j = i;
        char c = s[j];

        while (++chars[c] == 1 && j < size)
        {
            current_total++;
            c = s[++j];
        }

        if (current_total > total)
        {
            total = current_total;
        }
    }

    return total;
}

int myAtoi(const string& str)
{
    int i = 0;

    while (isspace(str[i]))
    {
        i++;
    }

    bool hasMinus = false;

    if (isalpha(str[i]))
    {
        return 0;
    }
    else if (ispunct(str[i]))
    {
        if (str[i] == '-')
        {
            hasMinus = true;
            i++;
        }
        else if(str[i] == '+')
        {
            i++;
        }
    }

    int number = 0;
    string digits;

    while (isdigit(str[i]))
    {
        digits.push_back(str[i]);
        i++;
    }

    bool outOfRange = false;
    try
    {
        number = stoi(digits);
    }
    catch( const invalid_argument& e)
    {
        return 0;
    }
    catch(const out_of_range& e)
    {
        number = hasMinus ? INT_MIN : INT_MAX;
        outOfRange = true;
    }

    if (hasMinus && !outOfRange)
    {
        number *= -1;
    }

    return number;
}