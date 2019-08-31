//#include <iostream>
#include <cstdio>
//#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
vi v;
int n;
void counting_sort(int maxn){
    int c[maxn+1]={0};
    vi s;
    s.resize(n);
    for(int i=0;i!=v.size();++i) ++c[v[i]];
    for(int i=1;i<=maxn;++i) c[i]+=c[i-1];
    for(int i=n-1;i>=0;--i)
        s[--c[v[i]]]=v[i];
    v.swap(s);
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int q,C=0;
    while(~scanf("%d%d",&n,&q) && n){
        printf("CASE# %d:\n",++C);
        v.clear();
        int a,maxn=0;
        for(int i=0;i!=n;++i){
            scanf("%d",&a);
            v.emplace_back(a);
            maxn=max(maxn,a);
        }
        counting_sort(maxn);
        while(q--){
            scanf("%d",&a);
            int x=lower_bound(v.begin(),v.end(),a)-v.begin();
            if(v[x]==a) printf("%d found at %d\n",a,x+1);
            else printf("%d not found\n",a);
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
const int MAX_N=10000;
int a[MAX_N],cnt[MAX_N+1],lo[MAX_N+1];
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q,ca=0;
    while(cin >> n >> q && n){
        for(int i=0;i<n;++i)
            cin >> a[i];
        memset(cnt,0,sizeof(cnt));
        memset(lo,0,sizeof(lo));
        for(int i=0;i<n;++i)
            ++cnt[a[i]];
        lo[0]=cnt[0];
        for(int i=1;i<=MAX_N;++i)
            lo[i]+=cnt[i]+lo[i-1];
        cout << "CASE# " << ++ca << ":\n";
        while(q--){
            int t;
            cin >> t;
            if(cnt[t]) cout << t << " found at " << lo[t]-cnt[t]+1 << "\n";
            else cout << t << " not found\n";
        }
    }
    return 0;
}
