//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

struct poker{
    char point,color;
};

vector<poker> v[52];

bool match(poker a, poker b){
    return (a.point == b.point || a.color == b.color);
}

void solve(){
    while(1){
        bool moved = false;
        for(int i=1;i<52;++i){
            if(v[i].empty()) continue;

            if(i >= 3 && match(v[i].back(), v[i-3].back())){
                v[i-3].push_back(v[i].back());
                v[i].pop_back();
                moved = true;
                if(v[i].empty()){
                    for(int j=i+1;j<52;++j){
                        v[j].swap(v[j-1]);
                    }
                }
                break;
            }
            if(match(v[i].back(), v[i-1].back())){
                v[i-1].push_back(v[i].back());
                v[i].pop_back();
                moved = true;
                if(v[i].empty()){
                    for(int j=i+1;j<52;++j){
                        v[j].swap(v[j-1]);
                    }
                }
                break;
            }
        }

        if(!moved) return;
    }
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    string s;
    while(getline(cin, s)){
        int idx = -1;
        for(int i=0;i<52;++i) v[i].clear();
        stringstream ss(s);
        string a;
        while(ss >> a){
            if(a == "#") return 0;
            v[++idx].push_back(poker{a[0],a[1]});
        }
        getline(cin, s);
        ss.clear();
        ss.str(s);
        while(ss >> a){
            v[++idx].push_back(poker{a[0],a[1]});
        }

        solve();

        vector<int> ans;
        for(int i=0;i<52;++i){
            if(!v[i].empty()) ans.push_back(v[i].size());
        }
        cout << ans.size() << " ";
        if(ans.size() == 1) cout << "pile remaining:";
        else cout << "piles remaining:";
        for(int i=0;i<ans.size();++i) cout << " " << ans[i];
        cout << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

