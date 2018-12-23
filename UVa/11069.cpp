#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
//using namespace std;
int f[77]={1,1,2};
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    for(int i=3;i<=76;++i) f[i]=f[i-2]+f[i-3];
    int n;
    while(~scanf("%d",&n)) printf("%d\n",f[n]);
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}


/*
	f(n) = f(n-2) + f(n-3)
	       包含n    不含n => f(n-1)中含(n-1) = f(n-1-2) = f(n-3)
*/