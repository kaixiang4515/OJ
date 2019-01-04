//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
#include <bits/stdc++.h>
using namespace std;
bool a[101][101];
int f[101][101],cnt[101][101];
int n,m;
int dp(int x, int y){
    if(f[x][y]) return f[x][y];
    int maxn=0;
    bool ok=0;
    for(int j=y+1;j<=m;++j)
        if(a[x][j]){
            maxn=max(maxn,dp(x,j));
            ok=1;
            break;
        }
    for(int i=x+1;i<=n;++i){
        for(int j=y;j<=m;++j)
            if(a[i][j]){
                maxn=max(maxn,dp(i,j));
                ok=1;
                break;
            }
    }
    f[x][y]=a[x][y]?maxn+1:maxn;
    if(ok){
        for(int j=y+1;j<=m;++j)
            if(a[x][j]){
                if(f[x][j]==f[x][y]-1) cnt[x][y]+=cnt[x][j];
                break;
            }
        for(int i=x+1;i<=n;++i)
            for(int j=y;j<=m;++j)
                if(a[i][j]){
                    if(f[i][j]==f[x][y]-1) cnt[x][y]+=cnt[i][j];
                    break;
                }
    }
    else cnt[x][y]=1;
    return f[x][y];
}
void Print(int k, int x, int y){
    if(k==0) return;
    for(int i=x;i<=n;++i)
        for(int j=y;j<=m;++j)
            if(a[i][j] && f[i][j]==k){
                printf(" %d",(i-1)*m+j);
                Print(k-1,i,j);
                return;
            }
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int C=0,x,y,k;
    while(~scanf("%d%d",&n,&m) && n!=-1){
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        while(~scanf("%d%d",&x,&y) && x) a[x][y]=1;
        int maxn=dp(1,1);
        printf("CASE#%d: %d",++C,maxn);
        if(a[1][1]) printf(" %d",cnt[1][1]);
        else{
            int s=0;
            for(int i=0;i<=n;++i)
                for(int j=0;j<=m;++j)
                    if(a[i][j]){
                        if(f[i][j]==maxn) s+=cnt[i][j];
                        break;
                    }
            printf(" %d",s);
        }
        Print(maxn,1,1);
        printf("\n");
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

