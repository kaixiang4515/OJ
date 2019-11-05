//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define Next(x) (x+d<=0?n:(x+d>n?1:x+d))
using namespace std;
int n;
bool q[25];

int next_f(int b ,int r, int d){
    while(r>0){
        if(!q[b=Next(b)]) --r;
    }
    return b;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int k,m;
    while(~scanf("%d%d%d",&n,&k,&m) && n){
        memset(q,0,sizeof(q));
        int i=0,j=0,cnt=n;
        while(cnt>0){
            if(cnt!=n) cout << ",";
            i=next_f(i,k,1);
            j=next_f(j,m,-1);
            printf("%3d",i);
            --cnt; q[i]=1;
            if(j!=i){
                printf("%3d",j);
                --cnt; q[j]=1;
            }
        }
        printf("\n");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

