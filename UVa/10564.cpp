#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int n;
int a[45][25],adj[45][25][505];
long long cnt[45][25][505];

struct node{
    int value;
    char direct;
}path[45],ans[45];

bool smaller(node (&a)[45], node (&b)[45]){
    for(int i=0;i<2*n-1;++i){
        if(a[i].value != b[i].value)
            return a[i].value < b[i].value;
    }
    return 0;
}

bool lefter(node (&a)[45], node (&b)[45]){
    for(int i=0;i<2*n-2;++i){
        if(a[i].direct != b[i].direct){
            if(a[i].direct == 'L') return 1;
            else return 0;
        }
    }
    return 0;
}

long long dp(int i, int j, int k){
    if(cnt[i][j][k]) return cnt[i][j][k];
    if(k<a[i][j]) return cnt[i][j][k]=-1;
    if(i==2*n-2){   //on bottom
        if(k==a[i][j]) return cnt[i][j][k]=1;
        else return cnt[i][j][k]=-1;
    }

    int nk=k-a[i][j];
    int& t=adj[i][j][k];

    if(i<n-2){ //上面
        if(j-1>=0 && dp(i+1,j-1,nk)>0){
            cnt[i][j][k]+=dp(i+1,j-1,nk);
            t=(t==-1)?0:((t==1)?2:0);
        }
        if(a[i+1][j]!=-1 && dp(i+1,j,nk)>0){
            cnt[i][j][k]+=dp(i+1,j,nk);
            t=(t==-1)?1:((t==0)?2:1);
        }
    }
    else if(i==n-2){
        if(dp(i+1,0,nk)>0){
            cnt[i][j][k]+=dp(i+1,0,nk);
            t=(j==0)?1:0;
        }
    }
    else{
        if(dp(i+1,j,nk)>0){
            cnt[i][j][k]+=dp(i+1,j,nk);
            t=(t==-1)?0:((t==1)?2:0);
        }
        if(dp(i+1,j+1,nk)>0){
            cnt[i][j][k]+=dp(i+1,j+1,nk);
            t=(t==-1)?1:((t==0)?2:1);
        }
    }
    if(cnt[i][j][k]==0) cnt[i][j][k]=-1;
    return cnt[i][j][k];
}

void printpath(int i, int j, int k){
    path[i].value=a[i][j];
    if(i==2*n-2){
        if(ans[0].value<0 || (ans[0].value>0 && smaller(path,ans) && lefter(path,ans)) ){
            for(int t=0;t<2*n-1;++t){
                ans[t]=path[t];
            }
        }
        path[i].value=-1;
        return;
    }

    int nk=k-a[i][j];
    int& t=adj[i][j][k];
    if(i<=n-2){
        if(t==0){
            path[i].direct='L';
            printpath(i+1,j-1,nk);
        }
        else if(t==1){
            path[i].direct='R';
            printpath(i+1,j,nk);
        }
        else if(t==2){
            path[i].direct='L';
            printpath(i+1,j-1,nk);
            path[i].direct='R';
            printpath(i+1,j,nk);
        }
    }
    else{
        if(t==0){
            path[i].direct='L';
            printpath(i+1,j,nk);
        }
        else if(t==1){
            path[i].direct='R';
            printpath(i+1,j+1,nk);
        }
        else if(t==2){
            path[i].direct='L';
            printpath(i+1,j,nk);
            path[i].direct='R';
            printpath(i+1,j+1,nk);
        }
    }
    path[i].value=-1;
    path[i].direct=0;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int s;
    while(cin >> n >> s && n){
        memset(cnt,0,sizeof(cnt));
        memset(a,-1,sizeof(a));
        memset(adj,-1,sizeof(adj));

        for(int i=0;i<n;++i)
            for(int j=0;j<n-i;++j)
                cin >> a[i][j];

        for(int i=n,len=2;i<2*n-1;++i,++len)
            for(int j=0;j<len;++j)
                cin >> a[i][j];


        long long sum=0;
        for(int j=0;j<n;++j)
            if(dp(0,j,s)>0) sum+=dp(0,j,s);

        cout << sum << "\n";
        for(int j=0;j<n;++j){
            if(dp(0,j,s)>0){
                cout << j << " ";
                ans[0].value=-1;
                printpath(0,j,s);
                break;
            }
        }

        if(sum>0){
            for(int i=0;i<2*n-2;++i)   //不包括底部 **
                cout << ans[i].direct;
        }
        cout << "\n";
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

