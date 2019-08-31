#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    unsigned a,b,ans,t;
    while(~scanf("%u%u",&a,&b)){
        t=1<<31; ans=0;
        do{
            unsigned ta=a&t,tb=b&t;
            ans|=ta^tb;
            t>>=1;
        }while(t);
        printf("%u\n",ans);
    }
    return 0;
}

