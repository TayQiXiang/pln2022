#include<iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
 
        long long last_digit = n % 9;
        long long x = (n - last_digit) / 9;
        if(last_digit == 0) {
            cout << (x - 1) * 10 + 9 << ' ' << x * 10 << '\n';
        }
        else {
            cout << x * 10 + last_digit << '\n';
        }
 
    }
    return 0;
}