#include <cstdio>
//#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
int f[2600]={1},a[1001]={1};
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int n,k=0;
    for(int i=1;i!=1001;++i){
        for(int j=0;j<=k;++j) f[j]*=i;
        for(int j=0,t=0;;++j){
            t=(f[j]+=t)/10;
            f[j]%=10;
            a[i]+=f[j];
            if(!t && j>=k){
                k=j;
                break;
            }
        }
    }
    while(~scanf("%d",&n)){
        printf("%d\n",a[n]);
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

