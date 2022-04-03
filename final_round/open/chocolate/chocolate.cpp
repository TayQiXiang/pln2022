#include<iostream>
#define LL long long
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int ans=0;LL l,r;cin>>l>>r;
        while((l|(l+1))<=r)l|=l+1;
        while(l)ans+=l&1,l>>=1;
        cout<<ans<<endl;
    }
}