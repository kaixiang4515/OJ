//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
bool a[101][101];
int width[101][101];
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n,m;
    while(~scanf("%d%d",&n,&m) && n){
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%d",&a[i][j]);
        memset(width,0,sizeof(width));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(!a[i][j]) width[i][j]=width[i][j-1]+1;
        int maxn=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                for(int k=i,w=width[k][j];k<=n;++k){
                    if(a[k][j]) break;
                    w=min(w,width[k][j]);
                    maxn=max(maxn,w*(k-i+1));
                }
        printf("%d\n",maxn);
    }
    return 0;
}

