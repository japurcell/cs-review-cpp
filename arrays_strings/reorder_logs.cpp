#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> reorderLogFiles(vector<string>& logs)
{
    // letter logs first, order by lex, identifier only on ties
    // digit logs original order

    set<string> letter_logs;
    vector<string> result;

    for (int i = 0; i < logs.size(); i++)
    {
        istringstream stream(logs[i]);
        string id;
        stream >> id >> ws;
        
        if (isdigit(stream.peek()))
        {
            string log(id);
            while (stream >> id)
            {
                log.append(" " + id);
            }

            result.push_back(log);
        }
        else
        {
            string word(stream.str().substr(stream.tellg()));
            letter_logs.insert(word + " " + id);
        }
    }

    vector<string> reconstructed;

    for (auto it = letter_logs.begin(); it != letter_logs.end(); ++it)
    {
        string log = *it;
        istringstream stream({ log.rbegin(), log.rend() });

        string id;
        stream >> id >> ws;
        id = { id.rbegin(), id.rend() };

        string entry(stream.str().substr(stream.tellg()));
        entry = { entry.rbegin(), entry.rend() };

        reconstructed.push_back(id + " " + entry);
    }

    reconstructed.insert(reconstructed.end(), result.begin(), result.end());

    return reconstructed;
}