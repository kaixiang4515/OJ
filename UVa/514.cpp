//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int t[1005];

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    while(~scanf("%d",&n) && n){
        int x;
        while(~scanf("%d",&x) && x){
            t[1] = x;
            for(int i=2;i<=n;++i)
                scanf("%d",t+i);

            stack<int> s;
            bool ok=1;
            int a=1,b=1;
            while(b<=n){
                if(a == t[b]){ ++a; ++b; }
                else if(!s.empty() && t[b] == s.top()){ s.pop(); ++b; }
                else if(a<=n){ s.push(a++); }
                else{ ok=0; break; }
            }

            printf("%s\n", (ok==1?"Yes":"No"));
        }
        printf("\n");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

