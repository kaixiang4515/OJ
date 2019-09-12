#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
long long rooks[35][35]={0};

int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    for(int n=1;n<=30;++n){
        rooks[n][0]=1;
        rooks[n][1]=n*n;
        for(int i=2;i<=n;++i)
            rooks[n][i]=rooks[n-1][i-1]*(2*n-i)+rooks[n-1][i];
    }

    int T,ca=0;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        cout << "Case " << ++ca << ": " << rooks[n][k] << "\n";
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

