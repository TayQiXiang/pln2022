#include <iostream>

using namespace std;

int a[1000010];

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, h;
        cin >> n >> h;

        int lo = 1, hi = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            hi = max(hi, a[i]);
        }

        while(lo < hi) {//binary search
            int mid = lo + (hi-lo)/2; 

            int timeTaken = 0;
            for(int i = 0; i < n; i++) {
                timeTaken += (a[i]-1)/mid + 1;
            }

            if(timeTaken <= h) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }

        cout << lo << endl;
    }

    return 0;
}
