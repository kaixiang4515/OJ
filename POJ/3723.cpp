//#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int n,m,r,par[20005],rk[20005];

void Init(int num){
    for(int i=0;i<num;++i){ par[i] = i; rk[i] = 0; }
}

int Find(int k){
    if(k == par[k]) return k;
    return par[k] = Find(par[k]);
}

bool Same(int a, int b){
    return (Find(a) == Find(b));
}

void Unite(int a, int b){
    a = Find(a); b = Find(b);
    if(a == b) return;
    if(rk[a] < rk[b]){
        par[a] = b;
    }
    else{
        par[b] = a;
        if(rk[a] == rk[b]) ++rk[a];
    }
}

struct edge{
    int from,to,val;
    bool operator < (const edge& b) const{
        return val < b.val;
    }
};
vector<edge> G;

int kruskal(){
    sort(G.begin(),G.end());
    Init(n+m);
    int sum = 0;
    for(int i=0;i<G.size();++i){
        edge e = G[i];
        if(!Same(e.from, e.to)){
            Unite(e.from, e.to);
            sum += e.val;
        }
    }
    return sum;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int ca;
    scanf("%d",&ca);
    while(ca--){
        scanf("%d%d%d",&n,&m,&r);
        G.clear();
        for(int i=0;i<r;++i){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            G.push_back(edge{a,n+b,-c});
            G.push_back(edge{n+b,a,-c});
        }

        printf("%d\n", (n+m)*10000 + kruskal());
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

