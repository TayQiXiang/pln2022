#include <iostream>
#include <vector>
 
using namespace std;
 
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
 
int dfs(int r, int c, vector<vector<int>>& a) {
    int ans = 1, symbol = a[r][c];
    a[r][c] = 0;
 
    for(int i = 0; i < 4; i++) {
        if(a[r+dr[i]][c+dc[i]] == symbol) {
            ans += dfs(r+dr[i], c+dc[i], a);
        }
    }
 
    return ans;
}
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
 
        vector<vector<int>> a(n+2, vector<int>(n+2, 0));
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
 
        int sizeA = 0, sizeB = 0;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
            if(a[i][j] == 1) {
                sizeA = max(sizeA, dfs(i, j, a));
            }
            if(a[i][j] == 2) {
                sizeB = max(sizeB, dfs(i, j, a));
            }
        }
 
        if(sizeB >= sizeA) {
            cout << "MOH should focus on Omicron" << endl;
        }
        else {
            cout << "MOH should focus on Covid-19" << endl;
        }
    }
 
    return 0;
}