#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#define Inf 0x3f3f3f3f
#define Neinf 0xc0c0c0c0

using namespace std;

int a[3005];
bool used[3005];

int main()
{
    //freopen("./in.txt", "r", stdin);
    //freopen("./out.txt", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    while(~scanf("%d",&n)){
        bool ok = 1;
        memset(used,0,sizeof(used));

        for(int i=0;i<n;++i){
            scanf("%d",a+i);
            if(ok && i){
                int x = abs(a[i-1] - a[i]);
                if(x >= n || used[x] == 1)
                    ok = 0;
                used[x] = 1;
            }
        }
        if(!ok) printf("Not jolly\n");
        else printf("Jolly\n");

    }
    return 0;
}

