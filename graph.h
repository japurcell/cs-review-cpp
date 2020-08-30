#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct edgenode
{
    int y;
    int weight;
    edgenode *next;

    edgenode() : next(NULL) { }
};

struct graph
{
    map<int, edgenode*> edges;
    bool directed;

    vector<bool> discovered;
    vector<int> parents;
    vector<bool> processed;

    graph() = delete;
    graph(const graph& other) = delete;
    graph(const vector<vector<int>>& grid, bool directed)
    {
        int edge_count = 0;

        for (auto y = grid.size()-1; y > 0; y--)
        {
            for (auto x = 0; x < grid[y].size(); x++, edge_count++)
                insert_edge(x, y, grid[y][x], directed);
        }

        discovered.resize(edge_count, false);
        parents.resize(edge_count, -1);
        processed.resize(edge_count, false);
    }

    template <typename PVEFn, typename PEFn, typename PVLFn>
    graph& bfs(int start, PVEFn&& processVertexEarly, PEFn&& processEdge, PVLFn&& processVertexLate);
    graph& insert_edge(int x, int y, int weight, bool directed);
    graph& print();

    private:
        void initialize_search();
};

void graph::initialize_search()
{
    fill(discovered.begin(), discovered.end(), false);
    fill(parents.begin(), parents.end(), -1);
    fill(processed.begin(), processed.end(), false);
}

template <typename PVEFn, typename PEFn, typename PVLFn>
graph& graph::bfs(int start, PVEFn&& processVertexEarly, PEFn&& processEdge, PVLFn&& processVertexLate)
{
    queue<int> q;
    int v, y;
    edgenode *e;

    q.push(start);
    discovered[start]=true;

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        processVertexEarly(v);
        processed[v] = true;

        e = edges[v];
        while (e != NULL)
        {
            y = e->y;

            if (!processed[y] || directed) processEdge(v, y, e->weight);
            if (!discovered[y])
            {
                q.push(y);
                discovered[y] = true;
                parents[y] = v;
            }

            e = e->next;
        }

        processVertexLate(v);
    }

    return *this;
}

graph& graph::insert_edge(int x, int y, int weight, bool directed)
{
    auto en = new edgenode();
    en->y = y;
    en->weight = weight;
    en->next = edges[x];
    edges[x] = en;

    if (!directed)
        insert_edge(y, x, weight, true);

    return *this;
}

graph& graph::print()
{
    for (auto& kv : edges)
    {
        cout << kv.first << " ";

        auto e = kv.second;
        while (e != NULL)
        {
            cout << e->y << ", ";
            e = e->next;
        }
        cout << endl;
    }

    return *this;
}