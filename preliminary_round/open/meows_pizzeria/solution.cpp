#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    int n, x, y;
    cin >> n >> x >> y;
 
    vector<int> a(n), b(n);
    vector<pair<int, int>> diff(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
 
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        diff[i].first = abs(a[i]-b[i]);
        diff[i].second = i;
    }
 
    sort(diff.rbegin(), diff.rend());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int idx = diff[i].second;
        if(x == 0) {
            ans += b[idx];
            continue;
        }
        if(y == 0) {
            ans += a[idx];
            continue;
        }
 
        if(a[idx] > b[idx]) {
            x--;
            ans += a[idx];
        }
        else {
            y--;
            ans += b[idx];
        }
    }
 
    cout << ans << endl;
 
    return 0;
}