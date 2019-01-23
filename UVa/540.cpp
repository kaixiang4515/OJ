#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <bits/stdc++.h>
#include <string>
#include <queue>
#include <map>
using namespace std;
map<int, int> team;
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,kase=0;
    while(cin >> n && n){
        cout << "Scenario #" << ++kase << "\n";
        team.clear();
        for(int i=0;i!=n;++i){
            int t,x;
            cin >> t;
            while(t--){ cin >> x; team[x]=i; }
        }
        queue<int> qa,qt[n];
        string cmd;
        while(cin >> cmd && cmd[0]!='S'){
            if(cmd[0]=='E'){
                int x;
                cin >> x;
                int t=team[x];
                if(qt[t].empty()) qa.push(t);
                qt[t].push(x);
            }
            else{
                int t=qa.front();
                cout << qt[t].front() << "\n";
                qt[t].pop();
                if(qt[t].empty()) qa.pop();
            }
        }
        cout << "\n";
    }
    return 0;
}

