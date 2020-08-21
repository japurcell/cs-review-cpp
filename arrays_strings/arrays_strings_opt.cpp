#include <cctype>
#include <climits>
#include <iostream>
#include <string>

using namespace std;

int myAtoi_opt(const string& str)
{
    int i = 0;

    while (str[i] == ' ')
    {
        i++;
    }

    int sign = 1;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    int number = 0;
    string digits;

    while (isdigit(str[i]))
    {
        digits.push_back(str[i]);
        i++;
    }

    try
    {
        number = stoi(digits) * sign;
    }
    catch(const invalid_argument& e)
    {
        return 0;
    }
    catch(const out_of_range& e)
    {
        number = sign == -1 ? INT_MIN : INT_MAX;
    }

    return number;
}