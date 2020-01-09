#include <iostream>
//#include <cstdio>
//#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int n;
string names[125];
map<string, int> m;
bool adj[125][125];
vector<string> ans[125];

bool is_connected(int a, int b){
    if(adj[a][b] || a == b) return true;
    for(int i=0;i<n;++i){
        if(i == a || i == b) continue;
        if(adj[a][i] && is_connected(i,b)) return true;
    }
    return false;
}

void solve(){
    while(1){
        bool update = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<n;++k){
                    if(i == j || k == i || k == j) continue;
                    if(adj[i][j] && is_connected(i,k) && is_connected(k,j)){
                        adj[i][j] = 0;
                        update = 1;
                    }
                }
            }
        }
        if(!update) break;
    }

    for(int i=0;i<n;++i){
        ans[i].clear();
        for(int j=0;j<n;++j){
            if(adj[j][i]){
                ans[i].push_back(names[j]);
            }
        }
        if(ans[i].size() > 1) sort(ans[i].begin(),ans[i].end());
    }
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int ca;
    cin >> ca;
    while(ca--){
        cin >> n;
        string name;
        m.clear();
        memset(adj,0,sizeof(adj));
        for(int i=0;i<n;++i){
            cin >> name;
            names[i] = name;
        }
        sort(names,names+n);
        for(int i=0;i<n;++i){
            name = names[i];
            m[name] = i;
        }
        int t;
        cin >> t;
        while(t--){
            string a,b;
            int j;
            cin >> a >> j;
            int i = m[a];
            while(j--){
                cin >> b;
                int v = m[b];
                adj[v][i] = 1;
            }
        }

        solve();
        for(int i=0;i<n;++i){
            if(!ans[i].empty()){
                cout << names[i] << " " << ans[i].size();
                for(int j=0;j<ans[i].size();++j) cout << " " << ans[i][j];
                cout << "\n";
            }
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

