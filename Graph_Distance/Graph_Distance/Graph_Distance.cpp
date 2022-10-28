#include <iostream>
#include <queue>
#include <vector>


class Graph {
    std::vector<std::vector<int>> adj;

public:
    Graph(int n) : adj(n, std::vector<int>()) {}

    void add_edges(const int m) {
        for (int j = 0; j < m; ++j) {
            int s, t;
            std::cin >> s >> t;
            
            this->adj[s - 1].push_back(t - 1);
            this->adj[t - 1].push_back(s - 1);
        }
    }

    int distance(const int s, const int t) {
        
        std::vector<int> dist(adj.size());
       
        for (auto& node : dist) {
            node = -1;
        }
        dist[s] = 0;

       
        std::queue<int> q;
        q.push(s);

        while (not q.empty()) {
            auto curr = q.front();
            q.pop();
           
            for (auto n : adj[curr]) {
                if (dist[n] == -1) {
                    q.push(n);
                   
                    dist[n] = dist[curr] + 1;
                }
            }
        }

        return dist[t];
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
   
    Graph graph(n);
    
    graph.add_edges(m);

    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << graph.distance(s, t) << std::endl;
}