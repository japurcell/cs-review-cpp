#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> reorderLogFiles_opt(vector<string>& logs)
{
    // letter logs first, order by lex, identifier only on ties
    // digit logs original order

    vector<pair<string, string>> letter_logs;
    vector<string> digit_logs;

    for (int i = 0; i < logs.size(); i++)
    {
        istringstream stream(logs[i]);
        string id;
        stream >> id >> ws;
        
        if (isdigit(stream.peek()))
        {
            digit_logs.push_back(logs[i]);
        }
        else
        {   
            letter_logs.push_back(make_pair(logs[i].substr(id.size()), id));
        }
    }

    sort(letter_logs.begin(), letter_logs.end());
    
    vector<string> results;

    for (auto& id_log : letter_logs)
    {
        results.push_back(id_log.second + id_log.first);
    }

    results.insert(results.end(), digit_logs.begin(), digit_logs.end());

    return results;
}