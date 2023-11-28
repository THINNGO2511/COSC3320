#include <vector>
#include<iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// PSID: 2053907
// Submission ID: efb2e56d-174f-4db6-88d4-5d57dbf7c4b8

const int N = 10;
char grid[N][N];
bool col[N];
int n, k, ans;

void solve(int i, int cnt) {
    if (cnt == k) {
        ans++;
        return;
    }
    if (i == n) return;
    for (int j = 0; j < n; j++) {
        if (grid[i][j] == '#' && !col[j]) {
            col[j] = true;
            solve(i + 1, cnt + 1); // place a chess piece at this cell
            col[j] = false;
        }
    }
    solve(i + 1, cnt); // skip this row
}

int main() {
    while (cin >> n >> k && n != -1 && k != -1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        memset(col, false, sizeof(col));
        ans = 0;
        solve(0, 0);
        cout << ans << endl;
    }
    return 0;
}