#include <iostream>
#include <vector>

using namespace std;

template <class T>
void swap(vector<T>& s, int i, int j)
{
    auto temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

template <class T>
void print(const vector<T>& arr)
{
    for (T i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
}

template <class T>
void printPermutations(vector<T> s)
{
    int n = s.size();
    vector<int> c(n, 0);

    print(s);

    int i = 0;
    while (i < n)
    {
        if (c[i] < i)
        {
            if (i % 2 == 0)
            {
                swap(s, 0, i);
            }
            else
            {
                swap(s, c[i], i);
            }
            
            print(s);

            c[i]++;

            i = 0;
        }
        else
        {
            c[i] = 0;
            i++;
        }
    }
}