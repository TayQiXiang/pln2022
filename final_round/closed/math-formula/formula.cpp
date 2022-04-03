#include <bits/stdc++.h>
using namespace std;
#define MAXN 51
typedef long long int lli;
lli f[MAXN][MAXN][MAXN];
int nums[MAXN],sum[MAXN];
int i,j,k,m,n,r,t,p,q;
int main(){

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",nums+i);
	}
	sum[0]=0;
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+nums[i];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++) f[i][j][0]=sum[j]-sum[i-1];
	for(p=1;p<=m;p++){
		for(r=p+1;r<=n;r++){
			for(i=1;i+r-1<=n;i++){
				j=i+r-1;
				for(k=i;k<j;k++){
					for(q=max(p-(j-k),0);q<=min(k-i,p);q++){
						f[i][j][p]=max(f[i][j][p],f[i][k][q]*f[k+1][j][p-q-1]);
						if(p-q<j-k) f[i][j][p]=max(f[i][j][p],f[i][k][q]+f[k+1][j][p-q]);
					}
				}
			}
		}
	}
	printf("%lld\n",f[1][n][m]);
	return 0;
}