#include <cstdio>
//#include <ctime>
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t s,e;
    s=clock();*/
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
        printf("%d\n",a+b);
    /*e=clock();
    printf("Use %.0lf ms\n", (((double)(e-s))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}
