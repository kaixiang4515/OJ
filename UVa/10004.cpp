#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int n,m;
int color[205];
vector<int> g[205];

bool bfs(){
    memset(color,-1,sizeof(color));

    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int t = que.front(); que.pop();

        for(auto i:g[t]){
            if(color[i] == -1){
                color[i] = color[t]^1;
                que.push(i);
            }
            else if(color[i] == color[t]) return false;
        }
    }

    return true;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> n && n){
        for(int i=0;i<n;++i) g[i].clear();
        cin >> m;
        for(int i=0;i<m;++i){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        if(bfs()) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

