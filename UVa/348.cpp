//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int r[12],c[12];
int dp[12][12],p[12][12];

int matrix_mult(int a, int b){
    if(dp[a][b]!=Inf) return dp[a][b];

    for(int i=a;i<b;++i){
        int t=matrix_mult(a,i)+matrix_mult(i+1,b)+r[a]*c[i]*c[b];
        if(t < dp[a][b]){
            dp[a][b]=t;
            p[a][b]=i;
        }
    }

    return dp[a][b];
}

void printpath(int a, int b){
    if(a==b) cout << "A" << a+1;
    else{
        cout << "(";
        printpath(a,p[a][b]);
        cout << " x ";
        printpath(p[a][b]+1,b);
        cout << ")";
    }
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ca=0;
    while(cin >> n && n){
        for(int i=0;i<n;++i) cin >> r[i] >> c[i];
        memset(dp,Inf,sizeof(dp));
        memset(p,-1,sizeof(p));
        for(int i=0;i<n;++i) dp[i][i]=0;

        cout << "Case " << ++ca << ": ";
        matrix_mult(0,n-1);
        printpath(0,n-1);
        cout << "\n";
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

