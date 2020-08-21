#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> extractWords(const string& s)
{
    size_t size = s.length();
    vector<string> words;
    char symbols[] = {'!', '?', '\'', ',', ';', '.', ' '};
    string currentWord;

    for (size_t i = 0; i < size; ++i)
    {
        char c = s[i];

        while (none_of(begin(symbols), end(symbols), [c](char sym) { return c == sym; }) && i < size)
        {
            currentWord.push_back(tolower(c));
            c = s[++i];
        }

        if (!currentWord.empty())
        {
            words.push_back(currentWord);
            currentWord.clear();
        }
    }

    return words;
}

string mostCommonWord(string paragraph, vector<string>& banned)
{
    unordered_map<string, int> countWords;
    auto words = extractWords(paragraph);

    for (auto it = words.begin(); it != words.end(); ++it)
    {
        if (none_of(banned.begin(), banned.end(), [it](string bad_word) { return *it == bad_word; }))
        {
            countWords[*it]++;
        }
    }

    auto max_el =
        *max_element(
            countWords.begin(),
            countWords.end(),
            [](const pair<string, int>& p1, const pair<string, int>& p2) { return p1.second < p2.second; });

    return max_el.first;
}