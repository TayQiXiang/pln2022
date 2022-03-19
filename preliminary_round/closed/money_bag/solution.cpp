#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int main() {
    int v; cin >> v;
    int n; cin >> n;
    int a[40];
    int f[200001];
  
    forn(i, n) cin >> a[i];
    
    forn(i, n) {
        for (int j = v; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }

    cout << v-f[v] << endl;
}
