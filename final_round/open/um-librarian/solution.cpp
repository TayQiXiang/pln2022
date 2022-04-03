#include <iostream>

using namespace std;

int idx[100050], a[100050][20];
//merge sort
long long merge(int lo, int hi, int l = 0) {
    if(hi-lo == 1) {
        return 0;
    }

    int mid = lo + (hi-lo)/2;
    for(int i = lo; i < hi; i++) {
        a[i][l+1] = a[i][l];
    }

    long long ans = 0;
    ans += merge(lo, mid, l+1);
    ans += merge(mid, hi, l+1);

    int i = lo, j = mid, k = lo;
    while(i < mid && j < hi) {
        if(a[i][l+1] <= a[j][l+1]) {
            // no swap
            a[k++][l] = a[i++][l+1];
        }
        else {
            // swap
            a[k++][l] = a[j++][l+1];
            ans += mid-i;
        }
    }

    while(i < mid) {
        a[k++][l] = a[i++][l+1];
    }
    while(j < hi) {
        a[k++][l] = a[j++][l+1];
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, x;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> x;
            idx[x] = i;
        }

        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> x;
            a[i][0] = idx[x];
        }

        cout << merge(0, m) << endl; 
    }

    return 0;
}
