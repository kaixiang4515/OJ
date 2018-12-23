#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
typedef long long LL;
int n;
LL a[20][20];
LL f(int i, int j){
    if(a[i][j]!=-1) return a[i][j];
    LL maxn=0,t=0;
    if(i<j){
        for(int k=i;k<j;++k)
            maxn=max(maxn,f(i,k)+f(k+1,j));
        return a[i][j]=maxn;
    }
    if(i<n){
        for(int k=i+1;k<=n;++k)
            maxn=max(maxn,f(k,1)+f(k,j));
        t+=maxn; maxn=0;
    }
    if(j>0){
        for(int k=1;k<j;++k)
            maxn=max(maxn,f(i,k)+f(n,k));
        t+=maxn;
    }
    return a[i][j]=t;
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int in;
    while(~scanf("%d%d",&n,&in)){
        memset(a,-1,sizeof(a));
        a[n][1]=in;
        printf("%lld\n",f(1,n));
        /*for(int i=0;i<=n;++i){
            printf("i = %d: ",i);
            for(int j=0;j<=n;++j) printf("%d ",a[i][j]);
            printf("\n");
        }*/
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

