//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

const int MAX_N = 1000005;
int Upar[MAX_N],Urank[MAX_N];
int n;

void Uinit(int k){
    for(int i=1;i<=k;++i){
        Upar[i]=i;
        Urank[i]=0;
    }
}

int Ufind(int k){
    if(k == Upar[k]) return k;
    return Upar[k] = Ufind(Upar[k]);
}

void Unite(int a, int b){
    a=Ufind(a); b=Ufind(b);
    if(a == b) return;
    if(Urank[a]<Urank[b]){
        Upar[a] = b;
    }
    else{
        Upar[b] = a;
        if(Urank[b] == Urank[a]) ++Urank[a];
    }
}

bool Usame(int a, int b){
    return Ufind(a) == Ufind(b);
}

struct edge{ int from, to, cost; };

bool operator < (const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

edge es[MAX_N * 100];

int Kruskal(int E){
    sort(es,es+E);
    Uinit(n);
    int ans = 0;
    for(int i=0;i<E;++i){
        edge e = es[i];
        if(!Usame(e.from, e.to)){
            Unite(e.from, e.to);
            ans += e.cost;
        }
    }
    return ans;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    bool first=1;
    while(cin >> n){
        int a,b,c,old=0,idx=-1;
        for(int i=0;i<n-1;++i){
            cin >> a >> b >> c;
            old+=c;
        }
        int k;
        cin >> k;
        for(int i=0;i<k;++i){
            cin >> a >> b >> c;
            es[++idx].from = a;
            es[idx].to = b;
            es[idx].cost = c;
        }
        int m;
        cin >> m;
        for(int i=0;i<m;++i){
            cin >> a >> b >> c;
            es[++idx].from = a;
            es[idx].to = b;
            es[idx].cost = c;
        }
        int ans = Kruskal(m+k);
        if(first) first = false;
        else cout << "\n";
        cout << old << "\n" << ans << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

/*
	***********
	***********
	another algorithm
	***********
	***********
*/

#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

const int MAX_N = 1000005;
int n,d[MAX_N];
bool used[MAX_N];

struct edge{
    int to,val;
};
vector<edge> G[MAX_N];

int Prim(int root){
    memset(d,Inf,sizeof(d));
    d[root] = 0;
    memset(used,false,sizeof(used));

    int sum = 0;
    while(1){

        int v=-1;
        for(int i=0;i<n;++i)
            if(!used[i] && (v==-1 || d[i] < d[v])) v = i;

        if(v == -1) break;

        used[v] = 1;
        sum+=d[v];

        for(int i=0;i<G[v].size();++i){
            edge e = G[v][i];
            d[e.to] = min(d[e.to], e.val);
        }
    }
    return sum;
}

int main()
{
    //freopen("./input.txt","r",stdin);
    //freopen("./output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    bool first=1;
    while(cin >> n){
        int a,b,c,old=0,ans=0;
        for(int i=0;i<n;++i){
            G[i].clear();
        }
        for(int i=0;i<n-1;++i){
            cin >> a >> b >> c;
            old+=c;
        }
        int k;
        cin >> k;
        for(int i=0;i<k;++i){
            cin >> a >> b >> c;
            G[--a].push_back(edge{--b,c});
            G[b].push_back(edge{a,c});
        }
        int m;
        cin >> m;
        for(int i=0;i<m;++i){
            cin >> a >> b >> c;
            G[--a].push_back(edge{--b,c});
            G[b].push_back(edge{a,c});
        }

        if(first) first = 0;
        else cout << "\n";
        cout << old << "\n" << Prim(0) << "\n";
    }
    return 0;
}

