#include <iostream>
 
using namespace std;
 
int main() {
    int t, n, x;
    cin >> t;
 
    while(t--) {
        cin >> n;
        int ans = 0, owe = 0;
        while(n--) {
            cin >> x;
            owe += x;
            ans += abs(owe);
        }
 
        cout << ans << "\n";
    }
 
    return 0;
}
