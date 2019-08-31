#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <algorithm>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int locate[21],sequence2[21],len[21];
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) cin >> locate[i];
    int a;
    while(cin >> a){
        sequence2[a]=1;
        for(int i=2;i<=n;++i){
            cin >> a;
            sequence2[a]=i;
        }
        int maxn=1;
        for(int i=1;i<=n;++i){
            len[i]=1;
            for(int j=1;j<i;++j){
                if(locate[sequence2[j]]<locate[sequence2[i]])
                    len[i]=max(len[i],len[j]+1);
            }
            maxn=max(maxn,len[i]);
        }
        cout << maxn << "\n";
    }
    return 0;
}

#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int locate[21],sequence2[21],len[21];
bool cmp(const int a, const int b){
    return locate[a]<locate[b];
}
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) cin >> locate[i];
    int a;
    while(cin >> a){
        sequence2[a]=1;
        for(int i=2;i<=n;++i){
            cin >> a;
            sequence2[a]=i;
        }
        vector<int> v;
        v.push_back(sequence2[1]);
        for(int i=2;i<=n;++i){
            if(locate[sequence2[i]]>locate[v.back()])
                v.push_back(sequence2[i]);
            else *lower_bound(v.begin(),v.end(),sequence2[i],cmp)=sequence2[i];
        }
        cout << v.size() << "\n";
    }
    return 0;
}
