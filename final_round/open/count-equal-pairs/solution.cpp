#include <iostream>

using namespace std;

int a[100010], b[100010];

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];

        long long ans = 0;
        int aIdx = 0, aCount = 1;
        for(int bIdx = 0; bIdx < m; bIdx++) {
            // count how many a first
            while(aIdx+1 < n && a[aIdx+1] <= b[bIdx]) {
                if(a[aIdx] != a[aIdx+1]) {
                    aCount = 0;
                }
                aCount++;
                aIdx++;
            }
            if(a[aIdx] == b[bIdx]) {
                ans += aCount;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
