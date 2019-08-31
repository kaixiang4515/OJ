#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int f[12];
int c[12][12];
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    for(int i=1;i<=11;++i){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;++j)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    f[0]=1;
    for(int i=1;i<=11;++i){
        for(int j=1;j<=i;++j)
            f[i]+=c[i][j]*f[i-j];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}

