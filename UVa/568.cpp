#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
long long f[10001]={1};
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int n;
    for(int i=1;i!=10001;++i){
        f[i]=f[i-1]*i;
        while(f[i]%10==0) f[i]/=10;
        f[i]%=1000000;
    }
    while(~scanf("%d",&n)){
        printf("%5d -> %lld\n",n,f[n]%10);
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}
