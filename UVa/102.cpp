#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <string>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;

int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int in[9],a[6];
    string msg[6]={"BCG","BGC","CBG","CGB","GBC","GCB"};
    while(cin >> in[0]){
        int sum=in[0];
        for(int i=1;i<9;++i){ cin >> in[i]; sum+=in[i]; }
        a[0]=sum-in[0]-in[5]-in[7];
        a[1]=sum-in[0]-in[4]-in[8];
        a[2]=sum-in[2]-in[3]-in[7];
        a[3]=sum-in[2]-in[4]-in[6];
        a[4]=sum-in[1]-in[3]-in[8];
        a[5]=sum-in[1]-in[5]-in[6];
        int minn=0;
        for(int i=1;i<6;++i)
            if(a[i] < a[minn]) minn=i;
        cout << msg[minn] << " " << a[minn] << "\n";
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

