#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cstring>
#define Inf 0x3f3f3f3f
#define Neinf 0xc0c0c0c0

using namespace std;

char s[105];
bool f[105];

int getidx(int i, int j, int l){
    return (i+j)%l;
}

int main()
{
    //freopen("./in.txt", "r", stdin);
    //freopen("./out.txt", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        int len = strlen(s);
        for(int i=0;i<len;++i) f[i] = 1;

        int cnt = len;
        for(int l=1;l<=len;++l){
            int minn = -1;
            for(int i=0;i<len;++i){
                if(f[i]){
                    int nidx = getidx(i,l-1,len);
                    if(minn == -1 || s[nidx] < s[getidx(minn,l-1,len)]) minn = i;
                }
            }
            for(int i=0;i<len;++i){
                if(f[i] && s[getidx(i,l-1,len)] > s[getidx(minn,l-1,len)]) f[i] = 0, --cnt;
            }
            if(cnt == 1) break;
        }
        int idx;
        for(idx=0;idx<len;++idx)
            if(f[idx]){ printf("%c",s[idx]); break; }
        for(int i=(idx+1)%len;i!=idx;i = (i+1)%len)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}

