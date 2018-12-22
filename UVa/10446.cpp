#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
//using namespace std;
typedef unsigned long long ULL;
ULL f[62][61];
ULL trib(int n, int b){
    if(n<0 || b<=0) return 1;
    if(f[n][b]) return f[n][b];
    if(n<=1) return f[n][b]=1;
    for(int i=1;i<=b;++i)
        f[n][b]+=trib(n-i,b);
    return ++f[n][b];
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int Case=0,n,b;
    while(~scanf("%d%d",&n,&b) && n<=60)
        printf("Case %d: %llu\n",++Case,trib(n,b));
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

