//#include <bits/stdc++.h>
#include <iostream>
#include <string>
//#include <iomanip>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

string s;
int border[400005];

void failure_build(const string& p, int *fail){
    for(int i=1,j=fail[0]=-1;i<s.size();++i){
        while(j>=0&&p[j+1]!=p[i]) j=fail[j];
        if(p[j+1]==p[i]) ++j;
        fail[i]=j;
    }
}

void find_prefix_suffix(int n){
    if(n==-1) return;
    find_prefix_suffix(border[n]);
    cout << n+1 << " ";
}

int main(){
    #ifdef LOCAL
        freopen("./file/in.txt","r",stdin);
        //freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(3);
    while(cin >> s){
        failure_build(s,border);
        find_prefix_suffix(s.size()-1);
        cout << "\n";
    }
    return 0;
}

