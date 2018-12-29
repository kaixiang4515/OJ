//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vv;
vv v;
void constrvv(){
    vi vt;
    vt.push_back(0);
    v.push_back(vt);
    vt[0]=1;
    v.push_back(vt);
    for(int i=2;i<=5000;++i){
        vt.clear();
        for(int j=0;j!=v[i-1].size();++j) vt.push_back(v[i-1][j]);
        for(int j=0;j!=v[i-2].size();++j) vt[j]+=v[i-2][j];
        int t=0;
        for(int j=0;j!=vt.size();++j){
            t=(vt[j]+=t)/10;
            vt[j]%=10;
        }
        while(t){
            vt.push_back(t%10);
            t/=10;
        }
        v.push_back(vt);
    }
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    constrvv();
    int n;
    while(~scanf("%d",&n)){
        printf("The Fibonacci number for %d is ",n);
        for(int i=v[n].size()-1;i>=0;--i)
            printf("%d",v[n][i]);
        printf("\n");
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

