#include <iostream>
//#include <cstdio>
//#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int> pile[30];
void find_h(int a, int &p, int &h){
    for(p=0;p<n;++p)
        for(h=0;h<pile[p].size();++h)
            if(pile[p][h]==a) return;
}
void clear_above(int p, int h){
    for(int i=h+1;i<pile[p].size();++i){
        int t=pile[p][i];
        pile[t].push_back(t);
    }
    pile[p].resize(h+1);
}
void pile_onto(int p, int h, int p2){
    for(int i=h;i<pile[p].size();++i)
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}
void print(){
    for(int i=0;i<n;++i){
        cout << i << ":";
        for(int j=0;j<pile[i].size();++j)
            cout << " " << pile[i][j];
        cout << "\n";
    }
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n){
        string s1,s2;
        int a,b;
        for(int i=0;i<n;++i) pile[i].clear(),pile[i].push_back(i);
        while(cin >> s1){
            if(s1=="quit") break;
            cin >> a >> s2 >> b;
            int pa,pb,ha,hb;
            find_h(a,pa,ha);
            find_h(b,pb,hb);
            if(pa==pb) continue;
            if(s1=="move") clear_above(pa,ha);
            if(s2=="onto") clear_above(pb,hb);
            pile_onto(pa,ha,pb);
        }
        print();
    }
    return 0;
}

