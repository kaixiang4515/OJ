//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
//#include <iomanip>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

int R,n;
int a[1005];

int main(){
    #ifdef LOCAL
        freopen("./file/in.txt","r",stdin);
        //freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(3);
    while(cin >> R >> n && R!=-1){
        REP(i,n) cin >> a[i];
        sort(a,a+n);
        int cnt=0;
        REP(i,n){
            int t=a[i];
            while(i+1<n && a[i+1]-t<=R) ++i;
            ++cnt;
            t=a[i];
            while(i+1<n && a[i+1]-t<=R) ++i;
        }
        cout << cnt << "\n";
    }
    return 0;
}
