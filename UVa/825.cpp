//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
#include <bits/stdc++.h>
using namespace std;
int a[100];
bool b[100];
char s[300];
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int T,n,m;
    bool f;
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        a[1]=1;
        scanf("%d%d ",&n,&m);
        for(int i=1;i<=n;++i){
            memset(b,0,sizeof(b));
            fgets(s,300,stdin);
            for(int j=0,t=f=0;s[j];++j){
                if(s[j]>='0' && s[j]<='9') t=t*10+s[j]-'0';
                else{
                    if(f) b[t]=1;
                    else f=1;
                    t=0;
                }
            }
            for(int j=1;j<=m;++j){
                if(b[j]) a[j]=0;
                else a[j]+=a[j-1];
            }
        }
        printf("%d\n",a[m]);
        if(T) printf("\n");
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

