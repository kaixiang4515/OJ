#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int s[2][100005];

int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    while(cin >> a >> b && a){
        memset(s,0,sizeof(s));
        for(int i=0;i<a;++i){ int t; cin >> t; s[0][t]=1; }
        for(int i=0;i<b;++i){ int t; cin >> t; s[1][t]=1; }

        int sa=0,sb=0;
        for(int i=1;i<=100000;++i)
            if(s[0][i] && !s[1][i]) ++sa;
        for(int i=1;i<=100000;++i)
            if(s[1][i] && !s[0][i]) ++sb;
        cout << min(sa,sb) << "\n";
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

