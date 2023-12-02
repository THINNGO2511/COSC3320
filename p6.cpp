
#include <iostream>
#include <vector>
#include <functional> 
using namespace std;

// PSID: 2053907
// Submission ID: b52ab9ac-fcb7-49cf-bd5b-62f0ca9199aa 

int numIslands(vector<vector<int>>& grid, int n) {
    int ans = 0;

    function<void(int, int)> dfs = [&](int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dfs(i, j);// call DFS function
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << numIslands(grid, n);
    return 0;
}
