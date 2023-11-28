#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// PSID: 2053907
// Submission ID: d0713022-c2e3-4c7d-b9b8-4347f6ff36e6

class Graph {
public:
    Graph(int n) : n_(n), adj_(n), visited_(n), in_stack_(n) {}

    void addEdge(int u, int v) {
        adj_[u].push_back(v);
    }

    int countSatisfiableNodes() {
        for (int i = 0; i < n_; ++i) {
            if (!visited_[i]) {
                if (hasCycle(i)) {
                    // Mark nodes in the current cycle as unsatisfiable
                    for (int node : cycle_nodes_) {
                        satisfiable_nodes_.erase(node);
                    }
                }
            }
        }

        return satisfiable_nodes_.size();
    }

private:
    int n_;
    vector<vector<int>> adj_;
    vector<bool> visited_;
    vector<bool> in_stack_;
    unordered_set<int> satisfiable_nodes_;
    vector<int> cycle_nodes_;

    bool hasCycle(int node) {
        visited_[node] = true;
        in_stack_[node] = true;

        for (int neighbor : adj_[node]) {
            if (!visited_[neighbor]) {
                if (hasCycle(neighbor)) {
                    cycle_nodes_.push_back(node);
                    return true;
                }
            } else if (in_stack_[neighbor]) {
                cycle_nodes_.push_back(neighbor);
                cycle_nodes_.push_back(node);
                return true;
            }
        }

        in_stack_[node] = false;
        satisfiable_nodes_.insert(node);
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int satisfiable_nodes = graph.countSatisfiableNodes();

    cout << satisfiable_nodes << endl;

    return 0;
}
