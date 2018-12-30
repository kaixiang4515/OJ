#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
//#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n,l,p;
typedef pair<int,int> pii;
typedef vector<pii> vp;
vp a;
bool com(pii x, pii y){
    return x.first<y.first;
}
void solve(){
    priority_queue<int> mxpq;
    int cnt=0,lo=0;
    for(int i=0;i!=n;++i){
        int d=a[i].first-lo;
        while(p-d<0){
            if(mxpq.empty()){
                printf("-1\n");
                return;
            }
            p+=mxpq.top();
            mxpq.pop();
            ++cnt;
        }
        mxpq.push(a[i].second);
        p-=d;
        lo=a[i].first;
    }
    printf("%d\n",cnt);
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int ia,ib;
    while(~scanf("%d",&n)){
        a.clear();
        for(int i=0;i!=n;++i){
            scanf("%d%d",&ia,&ib);
            a.push_back(pii(ia,ib));
        }
        scanf("%d%d",&l,&p);
        for(int i=0;i!=n;++i)
            a[i].first=l-a[i].first;
        sort(a.begin(),a.end(),com);
        a.push_back(pii(l,0)); //為了簡化問題而將目的地加入加油站列表
        ++n;
        solve();
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

