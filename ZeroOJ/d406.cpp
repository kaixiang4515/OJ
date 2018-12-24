//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int a[100][100];
queue<pii> q;
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int T=0,S,n,m;
    while(~scanf("%d%d%d",&S,&n,&m)){
        for(int i=0;i!=n;++i)
            for(int j=0;j!=m;++j)
                scanf("%d",&a[i][j]);
        printf("Case %d:\n",++T);
        for(int j=0;j!=m;++j) printf("%d ",a[0][j]);
        printf("\n");
        for(int j=0;j!=m;++j)
            if(a[0][j]){ q.push(pii(0,j));break; }
        while(q.size()){
            pii p=q.front(); q.pop();
            if(S==1 && p.first && a[p.first-1][p.second]==1){
                a[p.first-1][p.second]=a[p.first][p.second]+1;
                q.push(pii(p.first-1,p.second));
            }
            if(p.second && a[p.first][p.second-1]==1){
                a[p.first][p.second-1]=a[p.first][p.second]+1;
                q.push(pii(p.first,p.second-1));
            }
            if(p.first<n-1 && a[p.first+1][p.second]==1){
                a[p.first+1][p.second]=a[p.first][p.second]+1;
                q.push(pii(p.first+1,p.second));
            }
            if(p.second<m-1 && a[p.first][p.second+1]==1){
                a[p.first][p.second+1]=a[p.first][p.second]+1;
                q.push(pii(p.first,p.second+1));
            }
        }
        for(int i=1;i!=n;++i){
            for(int j=0;j!=m;++j)
                if(a[i][j]<=1) printf("0 ");
                else printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

