//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
//#include <iomanip>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

char s[105];
int len;

bool Less(int a, int b){
    REP(i,len){
        int na = (a+i)%len, nb = (b+i)%len;
        if(s[na] < s[nb]) return true;
        if(s[na] > s[nb]) return false;
    }
    return false;
}

int main(){
    #ifdef LOCAL
        freopen("./file/in.txt","r",stdin);
        freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(3);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        len = strlen(s);
        int ans = 0;
        for(int i = 1;i<len;++i)
            if(Less(i,ans))
                ans = i;

        REP(i,len)
            printf("%c",s[(ans+i)%len]);
        printf("\n");
    }
    return 0;
}
