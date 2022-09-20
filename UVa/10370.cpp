//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

int a[1005];

int main(){
    #ifdef LOCAL
        //freopen("./file/in.txt","r",stdin);
        //freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cout << fixed << setprecision(3);
    int c;
    cin >> c;
    while(c--){
        int n, cnt=0;
        cin >> n;
        double avg = 0;
        REP(i,n){
            cin >> a[i];
            avg += a[i];
        }
        avg /= n;

        REP(i,n)
            if(a[i] > avg) ++cnt;

        cout << 100.0*cnt/n << "%\n";
    }
    return 0;
}
