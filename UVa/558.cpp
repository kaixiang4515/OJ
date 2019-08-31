#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
struct edge{ int from,to,weight; } e[2005];
int d[1005];
int V,E;

bool negative_cycle(int s){
    memset(d,Inf,sizeof(d));
    d[s]=0;

    for(int i=0;i<V;++i){
        for(int j=0;j<E;++j){
            if(d[e[j].from]!=Inf && d[e[j].from] + e[j].weight < d[e[j].to]){
                d[e[j].to]=d[e[j].from] + e[j].weight;
                if(i==V-1) return true;
            }
        }
    }
    return false;
}
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        cin >> V >> E;
        for(int i=0,a,b,w;i<E;++i){
            cin >> a >> b >> w;
            e[i].from=a;
            e[i].to=b;
            e[i].weight=w;
        }

        if(negative_cycle(0)) cout << "possible\n";
        else cout << "not possible\n";
    }
    return 0;
}

