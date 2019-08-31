#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <vector>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
vector<int> p[6];
int v[9]={1};
bool used[6][6];

void init(){
    int a[]={2,3,5};
    p[1].insert(p[1].begin(),a,a+3);
    int b[]={1,3,5};
    p[2].insert(p[2].begin(),b,b+3);
    int c[]={1,2,4,5};
    p[3].insert(p[3].begin(),c,c+4);
    int d[]={3,5};
    p[4].insert(p[4].begin(),d,d+2);
    int e[]={1,2,3,4};
    p[5].insert(p[5].begin(),e,e+4);
}
void dfs(int idx){
    int from=v[idx-1],to=-1;
    vector<int> &t=p[from];

    for(int i=0;i<t.size();++i)
        if(!used[from][t[i]]){
            v[idx]=t[i];
            if(idx==8){
                for(int j=0;j<9;++j) cout << v[j];
                cout << "\n";
                return;
            }
            used[from][t[i]]=used[t[i]][from]=1;

            dfs(idx+1);
            used[from][t[i]]=used[t[i]][from]=0;
        }
}

int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    init();
    dfs(1);
    return 0;
}

