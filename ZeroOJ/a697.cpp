//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
#include <bits/stdc++.h>
#define mod 1000007
using namespace std;
int f[101]={1},b[101]={1};
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int n,m,a,*p,*q;
    scanf("%d%d",&n,&m);
    p=f,q=b;
    for(int i=0;i!=n;++i){
        scanf("%d",&a);
        for(int j=1;j<=m;++j){
            p[j]=(p[j-1]+q[j])%mod;
            if(j-a-1>=0) p[j]=(p[j]-q[j-a-1]+mod)%mod;
        }
        swap(p,q);
    }
    printf("%d",q[m]);
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

