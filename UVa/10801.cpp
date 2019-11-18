//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int d[105];
bool used[105];
vector<int> V[5];
struct edge{
    int to, num, val;
};
vector<edge> G[105]; //adjacency list

void dijkstra(int source){
    memset(d,Inf,sizeof(d));
    d[source] = 0;
    memset(used,false,sizeof(used));
    int T[105];
    memset(T,-1,sizeof(T));

    while(1){
        int v = -1;
        for(int i=0;i<100;++i){
            if(!used[i] && (v == -1 || d[i]<d[v])) v=i;
        }
        if(v == -1) break;
        used[v] = 1;

        for(int i=0;i<G[v].size();++i){
            edge V = G[v][i];
            int newd = d[v] + V.val;
            if(T[v] != -1 && T[v] != V.num){
                newd += 60;
            }

            if(newd < d[V.to]){
                d[V.to] = newd;
                T[V.to] = V.num;
            }
        }
    }
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n,k;
    int t[5];
    while(cin >> n >> k){
        for(int i=0;i<n;++i) cin >> t[i];
        cin.get();
        for(int i=0;i<n;++i){
            string s;
            getline(cin, s);
            stringstream ss(s);
            V[i].clear();
            int v;
            while(ss >> v){
                V[i].push_back(v);
            }
        }
        for(int i=0;i<100;++i) G[i].clear();
        for(int i=0;i<n;++i){
            for(int u=0;u<V[i].size();++u){
                for(int v=0;v<V[i].size();++v){
                    if(u == v)continue;
                    G[ V[i][u] ].push_back(edge{V[i][v],i,t[i]*abs(V[i][u] - V[i][v])});
                }
            }
        }

        dijkstra(0);

        if(d[k] == Inf) cout << "IMPOSSIBLE\n";
        else cout << d[k] << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

