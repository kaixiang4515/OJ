//O((M^2)*N)
//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
bool a[101][101];
int width[101][101];
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n,m;
    while(~scanf("%d%d",&n,&m) && n){
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%d",&a[i][j]);
        memset(width,0,sizeof(width));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(!a[i][j]) width[i][j]=width[i][j-1]+1;
        int maxn=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                for(int k=i,w=width[k][j];k<=n;++k){
                    if(a[k][j]) break;
                    w=min(w,width[k][j]);
                    maxn=max(maxn,w*(k-i+1));
                }
        printf("%d\n",maxn);
    }
    return 0;
}

//O(M*N)
#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <algorithm>
//#include <ctime>
//#include <bits/stdc++.h>
using namespace std;
bool tmap[102][102];
int wl[102],wr[102],h[102],l[102],r[102];
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int m,n;
    while(~scanf("%d%d",&m,&n) && m){
        memset(wl,0,sizeof(wl));
        memset(wr,0,sizeof(wr));
        memset(h,0,sizeof(h));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",&tmap[i][j]);
        int mxa=0;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(tmap[i][j]) wl[j]=0;
                else wl[j]=wl[j-1]+1;
            }
            for(int j=n;j>=1;--j){
                if(tmap[i][j]) wr[j]=0;
                else wr[j]=wr[j+1]+1;
            }
            for(int j=1;j<=n;++j){
                if(tmap[i][j]) h[j]=0;
                else ++h[j];
            }
            for(int j=1;j<=n;++j){
                if(l[j]) l[j]=min(l[j],wl[j]);
                else l[j]=wl[j];
            }
            for(int j=1;j<=n;++j){
                if(r[j]) r[j]=min(r[j],wr[j]);
                else r[j]=wr[j];
            }
            for(int j=1;j<=n;++j)
                mxa=max(mxa,(l[j]+r[j]-1)*h[j]);
        }
        printf("%d\n",mxa);
    }
    //printf("\nTime used = %lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

//Stack O(M*N)
#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <algorithm>
//#include <ctime>
//#include <bits/stdc++.h>
#include <utility>
#include <stack>
using namespace std;
using pii=pair<int,int>;
bool a[102][102];
int li[102][102];
stack<pii> s;
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int m,n,mxa;
    while(~scanf("%d%d",&m,&n) && m){
        memset(li,0,sizeof(li));
        mxa=0;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j){
                scanf("%d",&a[i][j]);
                if(!a[i][j]) li[i][j]=li[i-1][j]+1;
            }
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s.empty() || s.top().first<li[i][j])
                    s.push(make_pair(li[i][j],j));
                else if(s.top().first>li[i][j]){
                    int t;
                    while(!s.empty() && li[i][j]<s.top().first){
                        mxa=max(mxa,s.top().first*(j-s.top().second));
                        t=s.top().second; s.pop();
                    }
                    if(s.empty() || li[i][j]!=s.top().first)
                        s.push(make_pair(li[i][j],t));
                }
            }
            while(!s.empty()){
                mxa=max(mxa,s.top().first*(n+1-s.top().second));
                s.pop();
            }
        }
        printf("%d\n",mxa);
    }
    //printf("\nTime used = %lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
