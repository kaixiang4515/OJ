#include <cstdio>
//#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
long long a[20000];
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i!=n;++i) scanf("%lld",a+i);
    sort(a,a+n);
    for(int k=n;k!=1;--k){
        int i=n-k+1;
        a[i]+=a[i-1];
        ans+=a[i];
        for(;i!=n-1 && a[i]>a[i+1];++i) swap(a[i],a[i+1]);
    }
    printf("%lld",ans);
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}
