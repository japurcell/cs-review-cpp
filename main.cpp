#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "bst.h"
#include "graph.h"
#include "merge_sort.h"
#include "number_of_islands.h"
#include "permutations.h"
#include "trees_graphs/bst_zigzap.h"

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

bool isPalindrone(string s);
string longest_palindrome(string s);

vector<vector<int>> kClosest(vector<vector<int>>& points, int K);

int main()
{
    vector<vector<int>> points;
    points.push_back({ 3, 3 });
    points.push_back({ 5, -1});
    points.push_back({ -2, 4 });

    auto result = kClosest(points, 2);

    for (auto const& point: result)
    {
        print(point);
    }

    // cout << isPalindrone("ab") << " ";
    // cout << isPalindrone("bab") << " ";
    // cout << isPalindrone("cbbd") << " ";
    // cout << isPalindrone("a") << " ";
    // cout << isPalindrone("ababa") << endl;

    // string longest = longest_palindrome("cbbd");
    // cout << longest << " ";
    // longest = longest_palindrome("babad");
    // cout << longest << " ";
    // longest = longest_palindrome("");
    // cout << longest << " ";
    // longest = longest_palindrome("abcdbbfcba");
    // cout << longest << endl;

    // vector<vector<char>> grid({
    //     { '1','1','0','0','0' },
    //     { '1','1','0','0','0' },
    //     { '0','0','1','0','0' },
    //     { '0','0','0','1','1' }
    // });

    // cout << numIslands(grid) << endl;

    // int nums[] = { 8, 4, 2, 0, 58, 292, 1, 23, 478 };
    // mergesort(nums, 0, sizeof(nums)/sizeof(int));
    // vector<int> v(nums, nums + sizeof(nums)/sizeof(int));
    // print(v);

    // auto numbers = new tree<int>(5);
    // insert(&numbers, 2);
    // insert(&numbers, 7);
    // insert(&numbers, 1);
    // insert(&numbers, 3);
    // insert(&numbers, 4);
    // insert(&numbers, 6);
    // insert(&numbers, 8);
    // auto result = breadth_first_search(numbers, 4);
    // cout << result->item << endl;

    // traverse(numbers, [numbers](const auto& tree, const int& level) { print(tree, level); });
    // cout << endl;
    // remove_item(numbers, 4);
    // remove_item(numbers, 8);
    // remove_item(numbers, 5);
    // traverse(numbers, [numbers](const auto& tree, const int& level) { print(tree, level); });

    // tree<unsigned int> numbers(1960278308);
    // insert(&numbers, (unsigned int)1960278309);

    // auto rand = random_device();

    // for (int i = 0; i < 20; i++)
    // {
    //     insert(&numbers, rand());
    // }

    // traverse(&numbers, [&numbers](const auto& tree, const int& level) { print(tree, level); });

    // auto min = minimum(&numbers);
    // cout << min->item << endl;
    // auto max = maximum(&numbers);
    // cout << max->item << endl;

    // vector<string> logs {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art can"};
    // auto output = reorderLogFiles_opt(logs);
    // print(output);

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