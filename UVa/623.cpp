//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <vector>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<int(n);++i)

using namespace std;
using LL = long long;
vector<int> v[1005];

int main(){
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(3);
    //freopen("../file/in.txt","r",stdin);
    //freopen("../file/out.txt","w",stdout);
    int n;
    const int Base = 100000000, Width = 8;

    v[0].push_back(1);
    for(int i = 1; i <= 1000; ++i) {
        int t = 0;
        for(int j = 0; j < v[i-1].size(); ++j) {
            LL x = 1LL * v[i-1][j] * i + t;
            t = x / Base;
            v[i].push_back(x % Base);
        }
        if(t) v[i].push_back(t);
    }

    while(cin >> n) {
        cout << n << "!\n";
        int i = v[n].size()-1;
        cout << v[n][i--];
        while(i >= 0) cout << setw(8) << setfill('0') << v[n][i--];
        cout << "\n";
    }
    return 0;
}
