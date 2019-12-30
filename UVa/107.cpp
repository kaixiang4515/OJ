#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cmath>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int n,e;

void Find(int a, int b){
    n = 1, e = 1;
    int L = 1, R = b;

    while(L < R){
        int mid = (L+R)/2;
        if( abs( log(mid+1) / log(mid) - log(a) / log(b) ) <= 1e-7 ) break;
        else if(log(mid+1) / log(mid) > log(a) / log(b)) L = mid + 1;
        else if(log(mid+1) / log(mid) < log(a) / log(b)) R = mid - 1;
    }
    n = (L+R)/2;
    e = log(a) / log(n+1) + 1e-7;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int a,b;
    while(cin >> a >> b && a){
        Find(a,b);
        if(n == 1){
            cout << (int)log2(a) << " " << 2*a-1 << "\n";
        }
        else{
            cout << (b-1)/(n-1) << " ";
            int s = 0;
            for(int i=a,j=1;i>=1;i/=(n+1),j*=n){
                s += i*j;
            }
            cout << s << "\n";
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

