//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

char a[1005], b[1005];

int main(){
    #ifdef LOCAL
        freopen("./file/in.txt","r",stdin);
        freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    ios::sync_with_stdio(0);
    //cin.tie(0);
    while(cin.getline(a,1005)){
        cin.getline(b,1005);
        int ca[26]={0}, cb[26]={0};
        for(int i=0;a[i];++i) ++ca[ a[i]-'a' ];
        for(int i=0;b[i];++i) ++cb[ b[i]-'a' ];

        REP(i,26){
            for(int j=min(ca[i],cb[i]);j;--j)
                cout << (char)('a'+i);
        }
        cout << "\n";
    }
    return 0;
}

