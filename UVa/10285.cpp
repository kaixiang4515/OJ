#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
char s[20];
int a[102][102],f[101][101],maxn;
int dfs(int i, int j){
    if(f[i][j]) return f[i][j];
    if(a[i][j]==-1) return 0;
    if(a[i][j]>a[i-1][j]) f[i][j]=max(f[i][j],dfs(i-1,j)+1);
    if(a[i][j]>a[i+1][j]) f[i][j]=max(f[i][j],dfs(i+1,j)+1);
    if(a[i][j]>a[i][j-1]) f[i][j]=max(f[i][j],dfs(i,j-1)+1);
    if(a[i][j]>a[i][j+1]) f[i][j]=max(f[i][j],dfs(i,j+1)+1);
    maxn=max(maxn,f[i][j]);
    return f[i][j]=max(f[i][j],1);
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int T,r,c;
    scanf("%d",&T);
    while(T--){
        scanf("%s%d%d",s,&r,&c);
        memset(a,-1,sizeof(a));
        memset(f,0,sizeof(f));
        maxn=1;
        for(int i=1;i<=r;++i)
            for(int j=1;j<=c;++j)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=r;++i)
            for(int j=1;j<=c;++j)
                if(!f[i][j]) dfs(i,j);
        printf("%s: %d\n",s,maxn);
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

