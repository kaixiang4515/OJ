#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

const int MAX_N = 105;

int n;
double d[MAX_N];
bool used[MAX_N];
struct P{ double x, y; };
vector<P> p;

double dist(const P& a,const P& b){
    return sqrt( pow(a.x - b.x, 2) + pow(a.y - b.y, 2) );
}

double Prim(int root){
    for(int i=0;i<n;++i) d[i] = 1e9;
    d[root] = 0;
    memset(used,false,sizeof(used));
    //for(int i=0;i<n;++i) cout << d[i] << "\n";

    double sum = 0;
    while(1){
        int v = -1;
        for(int i=0;i<n;++i)
            if(!used[i] && (v==-1 || d[i] < d[v])) v = i;

        if(v == -1) break;

        used[v] = 1;
        sum+=d[v];
        for(int i=0;i<n;++i){
            double t;
            if(!used[i] && (t=dist(p[i], p[v])) < d[i]){
                d[i] = t;
            }
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
    cout << fixed << setprecision(2);
    int t;
    bool first = 1;
    cin >> t;
    while(t--){
        cin >> n;
        p.clear();
        for(int i=0;i<n;++i){
            double x, y;
            cin >> x >> y;
            p.push_back(P{x,y});
        }

        if(first) first = 0;
        else cout << "\n";
        cout << Prim(0) << "\n";
    }
    return 0;
}

