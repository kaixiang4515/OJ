#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <queue>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

char g[35][35][35];
int l,r,c;
int dx[6] = {0,0,0,0,1,-1}, dy[6] = {-1,0,1,0,0,0}, dz[6] = {0,1,0,-1,0,0};

struct Node{
    int x,y,z,cnt;
    Node(int x, int y, int z, int c):x(x), y(y), z(z), cnt(c){}
};

int bfs(int sx, int sy, int sz){
    queue<Node> que;
    que.push(Node(sx,sy,sz,0));
    while(!que.empty()){
        Node t = que.front(); que.pop();

        for(int i=0;i<6;++i){
            int nx = t.x + dx[i], ny = t.y + dy[i], nz = t.z + dz[i];
            if(0 <= nx && nx < l && 0 <= ny && ny < r && 0 <= nz && nz < c && g[nx][ny][nz] != '#'){
                if(g[nx][ny][nz] == 'E') return t.cnt+1;
                g[nx][ny][nz] = '#';
                que.push(Node(nx,ny,nz,t.cnt+1));
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> l >> r >> c && l){
        int x,y,z;
        for(int i=0;i<l;++i){
            for(int j=0;j<r;++j){
                for(int k=0;k<c;++k){
                    cin >> g[i][j][k];
                    if(g[i][j][k] == 'S') x = i, y = j, z = k;
                }
            }
            cin.get();
        }

        int ans = bfs(x,y,z);
        if(ans != -1) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

