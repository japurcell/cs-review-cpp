#include <iostream>
#include <vector>
#include <string>
#include "permutations.h"

using namespace std;

void duplicateZeroes(vector<int>& arr);
void duplicateZeroesV2(vector<int>& arr);

// leetcode: arrays and strings
vector<int> twoSum(vector<int>& nums, int target);
int lengthOfLongestSubstring(string s);
int myAtoi(const string& str);
int myAtoi_opt(const string& str);
int maxArea(vector<int>& height);
string mostCommonWord_opt(string paragraph, vector<string>& banned);
vector<string> reorderLogFiles_opt(vector<string>& logs);

int main()
{
    vector<string> logs {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art can"};
    auto output = reorderLogFiles_opt(logs);
    print(output);

    // string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    // vector<string> banned {"hit"};
    // string most_common = mostCommonWord_opt(paragraph, banned);

    // cout << most_common << endl;

    // vector<int> nums{ 1,0,2,3,0,4,5,0 };

    // duplicateZeroesV2(nums);

    // print(nums);

    // vector<int> s{0,1,2,3,4};
    // vector<char> c{'a','b','c'};

    // printPermutations(c);

    // vector<int> nums{3,2,4};
    // auto indices = twoSum(nums, 6);
    // print(indices);

    //int len = lengthOfLongestSubstring("pwwkew");

    // vector<int> lines {1,8,9,4,11,15,3,5};
    // int num = maxArea(lines);
    // cout << num << endl;

    return 0;
}