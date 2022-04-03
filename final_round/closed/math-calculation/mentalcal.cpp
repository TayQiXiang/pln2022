#include<iostream>
#include<cstdio>
using namespace std;
int t[200005],g[200005];//t[i] is how many times the number have been added, g[i]is whether the number exists:1 = exists; 0 = not exists
int n,a[105],ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];/
        g[a[i]]=1;//assign 1 to store there is such number
    }
    for (int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++){
            t[a[i]+a[j]]++;//we can get this number, store it(we dont care if this number is in our list at this point, will check below)
        }
    }
    for (int i=1;i<=200002;i++){
        if (t[i]>0&&g[i]) ans++;//check whether our list have that number, if so, ans++
    }
    cout<<ans<<endl;
    return 0;
}