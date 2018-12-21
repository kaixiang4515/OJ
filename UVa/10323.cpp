#include <cstdio>
//#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
long long f[15]={1};
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    for(int i=1;i<=13;++i) f[i]=f[i-1]*i;
    int n;
    while(~scanf("%d",&n)){
        if(n>=0){
            if(n>=8 && n<=13) printf("%lld\n",f[n]);
            else if(n<8) printf("Underflow!\n");
            else printf("Overflow!\n");
        }
        else{
            if(n*-1%2) printf("Overflow!\n");
            else printf("Underflow!\n");
        }
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

