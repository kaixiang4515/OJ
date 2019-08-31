#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define Mod 10056
using namespace std;
int f[1001];
int c[1001][1001];
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    for(int i=1;i<=1000;++i){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;++j)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%Mod;
    }
    f[0]=1;
    for(int i=1;i<=1000;++i){
        for(int j=1;j<=i;++j)
            f[i]=(f[i]+c[i][j]*f[i-j]%Mod)%Mod;
    }
    int t;
    cin >> t;
    for(int ca=1;ca<=t;++ca){
        int n;
        cin >> n;
        cout << "Case " << ca << ": " << f[n] << "\n";
    }
    return 0;
}

