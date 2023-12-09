#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define MAX_NODES 10000
#define INF INT_MAX

using namespace std;

struct Edge {
    int to;
    int weight;

    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

class DijkstraAlgorithm {
private:
    vector<vector<Edge>> adjacencyList;
    vector<int> distances;
    vector<bool> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

public:
    DijkstraAlgorithm(int n) {
        adjacencyList.resize(n);
        distances.resize(n, INF);
        visited.resize(n, false);
    }

    void addEdge(int u, int v, int w) {
        adjacencyList[u].push_back(Edge(v, w));
    }

    int shortestPath(int start, int end) {
        distances[start] = 0;
        minHeap.push(make_pair(0, start));

        while (!minHeap.empty()) 
        {
            int currentVertex = minHeap.top().second;
            minHeap.pop();

            if (visited[currentVertex]) continue;
            visited[currentVertex] = true;

            for (const auto& edge : adjacencyList[currentVertex]) 
            {
                int newDist = distances[currentVertex] + edge.weight;
                if (newDist < distances[edge.to]) 
                {
                    distances[edge.to] = newDist;
                    minHeap.push(make_pair(newDist, edge.to));
                }
            }
        }

        return distances[end] == INF ? -1 : distances[end];
    }
};

int main() 
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--; 

    DijkstraAlgorithm dijkstra(n);

    for (int i = 0; i < m; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dijkstra.addEdge(u, v, w);
    }

    cout << dijkstra.shortestPath(s, t) << endl;

    return 0;
}