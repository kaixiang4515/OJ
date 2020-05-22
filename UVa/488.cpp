#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define Neinf 0xc0c0c0c0

using namespace std;

int main()
{
    //freopen("./in.txt", "r", stdin);
    //freopen("./out.txt", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int ca;
    bool first = 1;
    cin >> ca;
    while(ca--){
        int a,f;
        cin >> a >> f;
        while(f--){
            if(first) first = 0;
            else cout << "\n";
            for(int i=1;i<a;++i){
                for(int j=0;j<i;++j) cout << i;
                cout << "\n";
            }
            for(int i=a;i>=1;--i){
                for(int j=0;j<i;++j) cout << i;
                cout << "\n";
            }
        }
    }
    return 0;
}

