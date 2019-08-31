#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int cnt[10];
bool h[10][10],v[10][10];
bool is_square(int x, int y, int len){
    for(int j=y,i=x+len;j<y+len;++j){
        if(!h[x][j] || !h[i][j]) return 0;
    }
    for(int i=x,j=y+len;i<x+len;++i){
        if(!v[i][y] || !v[i][j]) return 0;
    }
    return 1;
}
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ca=0;
    while(cin >> n){
        memset(h,0,sizeof(h));
        memset(v,0,sizeof(v));
        memset(cnt,0,sizeof(cnt));
        int t;
        bool is_find=0;
        cin >> t;
        while(t--){
            char ch;
            int x,y;
            cin >> ch >> x >> y;
            if(ch=='H') h[x][y]=1;
            else v[y][x]=1;
        }
        for(int len=1;len<n;++len)
            for(int i=1;i<=n-len;++i)
                for(int j=1;j<=n-len;++j)
                    if(is_square(i,j,len))
                        ++cnt[len],is_find=1;
        if(ca) cout << "\n**********************************\n\n";
        cout << "Problem #" << ++ca << "\n\n";
        if(is_find){
            for(int i=1;i<n;++i)
                if(cnt[i])
                    cout << cnt[i] << " square (s) of size " << i << "\n";
        }
        else cout << "No completed squares can be found.\n";
    }
    return 0;
}

