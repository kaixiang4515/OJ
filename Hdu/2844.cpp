#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
int a[100001],v[100];
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int n,m,c;
    while(~scanf("%d%d",&n,&m) && n){
        memset(a,0,sizeof(a));
        for(int i=0;i!=n;++i) scanf("%d",v+i);
        for(int i=0;i!=n;++i){
            scanf("%d",&c);
            if(c*v[i]>=m){ //無限背包
                for(int j=v[i];j<=m;++j)
                    a[j]=max(a[j],a[j-v[i]]+v[i]);
            }
            else{ //有限背包
                int k=1;
                while(k<=c){
                    int V=k*v[i];
                    for(int j=m;j>=V;--j)
                        a[j]=max(a[j],a[j-V]+V);
                    c-=k;
                    k=k<<1;
                }
                if(c){
                    int V=c*v[i];
                    for(int j=m;j>=V;--j)
                        a[j]=max(a[j],a[j-V]+V);
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=m;++i) if(a[i]==i) ++cnt;
        printf("%d\n",cnt);
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

