#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
int s[2600];
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int n,k;
    while(~scanf("%d",&n)){
        printf("%d!\n",n);
        memset(s,0,sizeof(s));
        s[k=0]=1;
        if(!n || n==1){
            printf("1\n");
            continue;
        }
        for(int i=2;i<=n;++i){
            for(int j=0;j<=k;++j) s[j]*=i;
            for(int j=0,t=0;;++j){
                s[j]+=t;
                t=s[j]/10;
                s[j]%=10;
                if(!t && j>=k){
                    k=max(k,j);
                    break;
                }
            }
        }
        for(;k>=0;--k) printf("%d",s[k]);
        printf("\n");
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

