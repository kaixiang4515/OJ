#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int a[1005][15];
bool is_zero(int n){
    int i=1;
    bool z=1;
    for(int j=0;j<n && z;++j) if(a[0][j]!=0) z=0;
    if(z) return 1;

    while(1){
        z=1;
        for(int j=0;j<n;++j){
            a[i][j]=abs(a[i-1][j]-a[i-1][(j+1)%n]);
            if(a[i][j]!=0) z=0;
        }

        if(z) return 1;

        for(int k=0;k<i;++k){
            bool l=1;
            for(int j=0;j<n && l;++j){
                if(a[i][j]!=a[k][j]) l=0;
            }
            if(l) return 0;
        }
        ++i;
    }
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(a,-1,sizeof(a));
        for(int i=0;i<n;++i)
            cin >> a[0][i];

        if(is_zero(n)) cout << "ZERO\n";
        else cout << "LOOP\n";
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

