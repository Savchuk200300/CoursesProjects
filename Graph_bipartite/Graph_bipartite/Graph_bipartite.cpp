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

    bool is_bipartite() {
        std::vector<int> color(adj.size());
     
        for (auto& node : color) {
            node = -1;
        }
        
        color[0] = 0;

        
        std::queue<int> q;
        q.push(0);

        while (not q.empty()) {
            auto curr = q.front();
            q.pop();
           
            for (auto n : adj[curr]) {
                if (color[n] == -1) {
                    q.push(n);
                    
                    color[n] = !color[curr];
                }
                else if (color[n] == color[curr]) {
                    return false;
                }
            }
        }
       
        return true;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    Graph graph(n);
  
    graph.add_edges(m);

    std::cout << graph.is_bipartite() << std::endl;
}