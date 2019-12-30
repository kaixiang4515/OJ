//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

long long a[35][35];
bool block[905][905];

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int ca;
    cin >> ca;
    while(ca--){
        int n,sx,sy,ex,ey;
        cin >> n >> sx >> sy >> ex >> ey;
        memset(a,0,sizeof(a));
        memset(block,0,sizeof(block));
        int t;
        cin >> t;
        while(t--){
            int x,y;
            char ch;
            cin >> x >> y >> ch;
            int v1 = (x-1)*n+y;
            if(ch == 'W'){
                int v2 = (x-2)*n+y;
                block[v1][v2] = block[v2][v1] = 1;
            }
            else if(ch == 'E'){
                int v2 = x*n+y;
                block[v1][v2] = block[v2][v1] = 1;
            }
            else if(ch == 'S'){
                int v2 = v1-1;
                block[v1][v2] = block[v2][v1] = 1;
            }
            else if(ch == 'N'){
                int v2 = v1+1;
                block[v1][v2] = block[v2][v1] = 1;
            }
        }

        a[sx][sy] = 1;
        for(int i=sx+1;i<=ex;++i){
            int v1 = (i-2)*n+sy, v2 = (i-1)*n+sy;
            if(block[v1][v2]) break;
            a[i][sy] = 1;
        }
        for(int j=sy+1;j<=ey;++j){
            int v1 = (sx-1)*n+j-1, v2 = v1+1;
            if(block[v1][v2]) break;
            a[sx][j] = 1;
        }

        for(int i=sx+1;i<=ex;++i){
            for(int j=sy+1;j<=ey;++j){
                int v = (i-1)*n+j, v1 = v-n, v2 = v-1;
                if(!block[v][v1]) a[i][j]+=a[i-1][j];
                if(!block[v][v2]) a[i][j]+=a[i][j-1];
            }
        }

        cout << a[ex][ey] << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

