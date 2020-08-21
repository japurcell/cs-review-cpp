#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

string mostCommonWord_opt(string paragraph, vector<string>& banned)
{
    unordered_map<string, int> count_words;
    unordered_set<string> banned_set (banned.begin(), banned.end());

    for (auto& c : paragraph)
    {
        c = isalpha(c) ? tolower(c) : ' ';
    }

    string word;
    istringstream stream(paragraph);
    pair<string, int> most_common ("", 0);

    while (stream >> word)
    {
        if (banned_set.find(word) == banned_set.end() && ++count_words[word] > most_common.second)
        {
            most_common = make_pair(word, count_words[word]);
        }
    }

    return most_common.first;
}