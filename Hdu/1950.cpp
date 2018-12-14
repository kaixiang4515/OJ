#include <cstdio>
//#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
int dp[40000];
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int T,a;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        fill(dp,dp+n,2147483647);
        for(int i=0;i!=n;++i){
            scanf("%d",&a);
            *upper_bound(dp,dp+n,a)=a;
        }
        printf("%d\n",lower_bound(dp,dp+n,2147483647)-dp);
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}
