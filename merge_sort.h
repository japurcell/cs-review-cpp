#include <queue>
using namespace std;

template <class T>
void merge(T t[], int low, int middle, int high)
{
    queue<T> q1, q2;

    int i = 0;
    for (i = low; i <= middle; i++) q1.push(t[i]);
    for (i = middle + 1; i <= high; i++) q2.push(t[i]);

    i = low;
    while (!(q1.empty() || q2.empty()))
    {
        if (q1.front() < q2.front())
        {
            t[i++] = q1.front();
            q1.pop();
        }
        else
        {
            t[i++] = q2.front();
            q2.pop();
        }
    }

    while (!q1.empty())
    {
        t[i++] = q1.front();
        q1.pop();
    }

    while (!q2.empty())
    {
        t[i++] = q2.front();
        q2.pop();
    }
}

template <class T>
void mergesort(T t[], int low, int high)
{
    if (low < high)
    {
        int middle = (low+high)/2;
        mergesort(t, low, middle);
        mergesort(t, middle+1, high);
        merge(t, low, middle, high);
    }
}