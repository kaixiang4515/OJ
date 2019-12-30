//#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;
typedef pair<int,int> pii;

int V,E;
int d1[5005],d2[5005];

struct edge{
    int to,val;
};
vector<edge> G[5005];

void dijkstra(int source){
    memset(d1,Inf,sizeof(d1));
    d1[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0,source));    // (distance, node)

    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        int v = p.second;
        if(p.first > d1[v]) continue;

        for(int i=0;i<G[v].size();++i){
            edge e = G[v][i];
            if(d1[v] + e.val < d1[e.to]){
                d1[e.to] = d1[v] + e.val;
                pq.push(pii(d1[e.to], e.to));
            }
        }
    }
}

void second_shortest(int source){
    memset(d2,Inf,sizeof(d2));

    while(1){
        bool update = 0;
        for(int i=1;i<=V;++i){
            for(int j=0;j<G[i].size();++j){
                edge e = G[i][j];
                int t1 = d1[i] + e.val, t2 = d2[i] + e.val;
                if(t1 > d1[e.to] && t1 < d2[e.to]){
                    d2[e.to] = t1;
                    update = 1;
                }
                else if(t2 > d1[e.to] && t2 < d2[e.to]){
                    d2[e.to] = t2;
                    update = 1;
                }
            }
        }
        if(!update) break;
    }
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;++i){
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        G[a].push_back(edge{b,n});
        G[b].push_back(edge{a,n});
    }

    dijkstra(1);
    second_shortest(1);

    printf("%d",d2[V]);

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
