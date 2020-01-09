#include <iostream>
//#include <cstdio>
//#include <bits/stdc++.h>
#include <cmath>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    double p;
    while(cin >> n >> p){
        int L = 1, R = (int)1e9;
        while(L < R){
            int mid = (L+R)/2; // printf("mid = %d\n",mid);
            if(abs( log(p) / n - log(mid) ) <= 1e-9) break;
            else if( log(p) / n > log(mid) ) L = mid+1;
            else R = mid-1;
        }
        int k = (L+R)/2;
        cout << k << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

