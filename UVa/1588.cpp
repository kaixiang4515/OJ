//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
//#include <iomanip>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

string a,b;

int sol(){
    int ans = a.length() + b.length(), ia = a.length()-1, ib = 0;

    //cout << 1 << ":\n";
    for(int i=0;i<a.length();++i){
        bool ok = true;
        for(int j=0;j<=i;++j){
            if(a[ia-j]-'0' + b[ib+i-j]-'0' > 3){
                ok=false;
                break;
            }
        }
        if(ok) ans = min(ans, (int)(a.length() + b.length() - (i+1)));
        //cout << ok << "\n";
    }
    //cout << 2 << ":\n";
    for(int i=0;i<b.length() - a.length();++i){
        bool ok = true;
        for(int j=0;j<a.length();++j){
            if(a[j]-'0'+b[j+i+1]-'0' > 3){
                ok=false;
                break;
            }
        }
        if(ok) ans = min(ans, (int)b.length());
        //cout << ok << "\n";
    }
    //cout << 3 << ":\n";
    ia = 0, ib = b.length()-1;
    for(int i=a.length()-1;i;--i){
        bool ok = true;
        for(int k=0;k<i;++k){
            if(a[k]-'0'+b[ib-i+k+1]-'0' > 3){
                ok=false;
                break;
            }
        }
        if(ok) ans = min(ans, (int)(a.length() + b.length() - i));
        //cout << ok << "\n";
    }
    return ans;
}

int main(){
    #ifdef LOCAL
        freopen("./file/in.txt","r",stdin);
        //freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(3);
    while(getline(cin, a)){
        getline(cin, b);
        if(a.length() > b.length()) swap(a,b);
        //cout << a << "\n" << b << "\n";

        cout << sol() << "\n";
        //cout << "=============\n";
    }
    return 0;
}

