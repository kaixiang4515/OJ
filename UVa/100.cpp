//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

int a[1000005];

int cnt(int k){// cout << "In k = " << k << "\n";
    if(a[k]) return a[k];

    int c = 1;
    int t = k;
    while(k!=1){//    cout << k << " ";
        if(k<1000005 && a[k]) return a[t] = a[k] + c - 1;
        ++c;
        if(k%2) k = k*3+1;
        else k = k>>1;
    }//   cout << "\n";
    return a[t] = c;
}

int main(){
    #ifdef LOCAL
        freopen("./file/in.txt","r",stdin);
        freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int i,j;
    while(cin >> i >> j){
        cout << i << " " << j << " ";
        if(i>j) swap(i,j);
        int maxn = cnt(i);
        for(int x=i+1;x<=j;++x)
            if(cnt(x) > maxn) maxn = cnt(x);
        cout << maxn << '\n';
    }
    //for(int i=0;i<1000005;++i) if(a[i]) cout << i;
    return 0;
}

