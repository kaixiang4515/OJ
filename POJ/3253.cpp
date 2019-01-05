#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
//#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long LL;
int n;
void solve(){
    priority_queue<LL, vector<LL>, greater<LL> > mnpq;
    int in;
    LL s=0;
    for(int i=0;i!=n;++i){
        scanf("%d",&in);
        mnpq.push(in);
    }
    LL a,b;
    while(n>1){
        a=mnpq.top(); mnpq.pop();
        b=mnpq.top(); mnpq.pop();
        s+=a+b;
        mnpq.push(a+b);
        --n;
    }
    printf("%lld\n",s);
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    while(~scanf("%d",&n)) solve();
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}
