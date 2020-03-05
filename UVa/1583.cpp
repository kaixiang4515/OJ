#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define Neinf 0xc0c0c0c0

using namespace std;

int t[100005]={0};

int main()
{
    //freopen("./in.txt", "r", stdin);
    //freopen("./out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=100000;++i){
        int s = i, tmp = i;
        while(tmp){
            s += tmp%10;
            tmp /= 10;
        }
        if(!t[s]) t[s] = i;
    }
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        cout << t[a] << "\n";
    }
    return 0;
}
