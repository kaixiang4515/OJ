#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cmath>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned n;
    while(cin >> n && n){
        int t=floor(sqrt(1.0*n));
        if(t*t==n) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}

