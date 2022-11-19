//#include <bits/stdc++.h>
#include <iostream>
#include <string>
//#include <iomanip>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

string w,t;
int border[10005];

void failure_build(const string& p, int *fail){
    for(int i=1,j=fail[0]=-1;i<p.size();++i){
        while(j>=0&&p[j+1]!=p[i]) j=fail[j];
        if(p[j+1]==p[i]) ++j;
        fail[i]=j;
    }
}

int KMP(const string& t, const string& p, int *fail){
    int cnt=0;
    failure_build(p,fail);
    for(int i=0,j=-1;i<t.size();++i){
        while(j>=0&&p[j+1]!=t[i]) j=fail[j];
        if(p[j+1]==t[i]) ++j;
        if(j==p.size()-1){
            ++cnt;
            j=fail[j];
        }
    }
    return cnt;
}

int main(){
    #ifdef LOCAL
        freopen("./file/in.txt","r",stdin);
        //freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(3);
    int times;
    cin >> times;
    while(times--){
        cin >> w >> t;
        cout << KMP(t,w,border) << "\n";
    }
    return 0;
}

