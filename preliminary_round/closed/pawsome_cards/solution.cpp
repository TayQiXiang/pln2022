#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    int a[200] = {0};
    forn(i, s1.length()) a[s1[i]]++;
    
    forn(i, s2.length()) {
        a[s2[i]]--;
        if(a[s2[i]]<0){
            cout << "not possible" << endl;
            return 0;
        }  
    }
    cout<<"possible"<<endl;  
}
