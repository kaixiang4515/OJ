#include <cstdio>
#include <cstring>
//#include <algorithm>
//#include <ctime>
#include <cmath>
using namespace std;
int f[180],a[180];
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int n,A,k;
    while(~scanf("%d%d",&n,&A)){
        if(!A){ printf("0\n");continue; }
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        k=-1;
        int tmp=A;
        while(tmp){
            a[++k]=tmp%10;
            f[k]=a[k];
            tmp/=10;
        }
        for(int i=2;i<=n;++i){
            for(int j=0;j<=k;++j) a[j]*=A;
            for(int j=0,t=0;;++j){
                t=(a[j]+=t)/10;
                a[j]%=10;
                if(!t && j>=k){ k=j;break; }
            }
            for(int j=0;j<=k;++j) f[j]+=a[j]*i;
            for(int j=0,t=0;j<180;++j){
                t=(f[j]+=t)/10;
                f[j]%=10;
            }
        }
        int x=180;
        while(!f[x-1]) --x;
        for(--x;x>=0;--x) printf("%d",f[x]);
        printf("\n");
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

