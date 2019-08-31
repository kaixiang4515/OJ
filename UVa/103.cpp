#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
int n,k;
int box[30][10],dp[30][30],pivot[30][30];
bool cmp(const int *a, const int *b){
    for(int i=0;i<n;++i)
        if(a[i]>=b[i]) return 0;
    return 1;
}
void printpivot(int i, int j){
    int t=pivot[i][j];
    if(t<0) return;
    printpivot(i,t);
    cout << t+1 << " ";
    printpivot(t,j);
}
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> k >> n){
        for(int i=0;i<k;++i){
            for(int j=0;j<n;++j)
                cin >> box[i][j];
            sort(box[i],box[i]+n);
        }
        memset(dp,NeInf,sizeof(dp));
        memset(pivot,-1,sizeof(pivot));
        for(int i=0;i<k;++i){
            for(int j=0;j<k;++j){
                if(i==j) dp[i][j]=1;
                else if(cmp(box[i],box[j])) dp[i][j]=2;
            }
        }
        int maxn=-1,mxi,mxj;
        for(int t=0;t<k;++t){
            for(int i=0;i<k;++i)
                for(int j=0;j<k;++j){
                    int tmp=dp[i][t]+dp[t][j]-1;
                    if(tmp>dp[i][j]){
                        dp[i][j]=tmp;
                        pivot[i][j]=t;
                    }
                    if(dp[i][j]>maxn){
                        maxn=dp[i][j];
                        mxi=i; mxj=j;
                    }
                }
        }
        cout << maxn << "\n";
        if(maxn==1) cout << mxi+1 << "\n";
        else{
            cout << mxi+1 << " ";
            printpivot(mxi,mxj);
            cout << mxj+1 << "\n";
        }
    }
    return 0;
}
