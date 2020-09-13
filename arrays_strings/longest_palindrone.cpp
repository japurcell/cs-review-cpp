#include <algorithm>
#include <string>
#include <set>

using namespace std;

int expand(int left, int right, const string& s)
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }

    return right - left - 1;
}

string longest_palindrome(string s)
{
    int n = s.length();
    if (n <= 1) return s;

    int start = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        int odd = expand(i, i, s);
        int even = expand(i, i + 1, s);

        int len = max(odd, even);

        if (len > count)
        {
            count = len;
            start = i - (len - 1) / 2;
        }
    }

    return s.substr(start, count);
}

string longestPalindrome(string s)
{
    int size = s.length();

    if (s.empty()) return "";

    int table[size][size];
    memset(table, 0 , sizeof(table));

    int maxLength = 1;

    for (int i = 0; i < size; ++i)
        table[i][i] = true;

    int start = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= size; ++k)
    {
        for (int i = 0; i < size - k + 1; ++i)
        {
            int j = i + k - 1;

            if (table[i + 1][j - 1] && s[i] == s[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    return s.substr(start, maxLength);
}