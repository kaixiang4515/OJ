//#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int n,d[505],cnt[505],parent[505];
bool inque[505];
struct edge{
    int to,val;
};
vector<edge> G[505];

bool negative_cycle(int source){    //SPFA
    memset(d,Inf,sizeof(d));
    d[source]=0;
    memset(inque,false,sizeof(inque));
    memset(cnt,0,sizeof(cnt));
    parent[source]=source;

    queue<int> Q;
    Q.push(source);

    while(!Q.empty()){
        int u=Q.front(); Q.pop();
        inque[u] = false;

        if(inque[parent[u]]) continue;

        for(int i=0;i<G[u].size();++i){
            edge e = G[u][i];
            if(d[u]+e.val < d[e.to]){
                d[e.to] = d[u]+e.val;
                parent[e.to]=u;
                cnt[e.to] = cnt[u]+1;
                if(cnt[e.to] > n-1) return true;

                if(!inque[e.to]){
                    inque[e.to] = true;
                    Q.push(e.to);
                }
            }
        }
    }
    return false;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int ca,m,w;
    scanf("%d",&ca);
    while(ca--){
        scanf("%d%d%d",&n,&m,&w);
        for(int i=0;i<n;++i) G[i].clear();
        for(int i=0;i<m;++i){
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            --s; --e;
            G[s].push_back(edge{e,t});
            G[e].push_back(edge{s,t});
        }
        for(int i=0;i<w;++i){
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            --s; --e;
            G[s].push_back(edge{e,-t});
        }

        if(negative_cycle(0)) printf("YES\n");
        else printf("NO\n");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

