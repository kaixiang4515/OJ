#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <algorithm>
//#include <ctime>
//#include <bits/stdc++.h>
using namespace std;
int n,t[7]/*紅棋類型*/,rx[7],ry[7];
bool f=0;
bool horse(int i, int x, int y){
    int vx[]={-2,-2,-1,1,2,2,1,-1},vy[]={-1,1,2,2,1,-1,-2,-2};
    int bx[]={-1,-1,0,0,1,1,0,0},by[]={0,0,1,1,0,0,-1,-1};
    for(int j=0;j<8;++j){
        if(rx[i]+vx[j]==x && ry[i]+vy[j]==y){
            bool ok=1;
            for(int k=0;ok && k<n;++k)
                if(k!=i && rx[k]==rx[i]+bx[j] && ry[k]==ry[i]+by[j])
                    ok=0;
            if(ok) return 1;
            else return 0;
        }
    }
    return 0;
}
void func(int x, int y){
    if(f) return;
    for(int i=0;i<n;++i){
        if(rx[i]==x && ry[i]==y) continue;  //被吃掉
        if(t[i]=='G'){
            if(y==ry[i]){   //將帥照面
                bool ok=1;
                for(int j=0;ok && j<n;++j)
                    if(j!=i && ry[j]==y && rx[j]!=x)
                        ok=0;
                if(ok) return;
            }
        }
        else if(t[i]=='R'){ //車
            if(rx[i]==x){
                bool ok=1;
                for(int j=0;ok && j<n;++j)
                    if(j!=i && rx[j]==x && ry[j]>min(y,ry[i]) && ry[j]<max(y,ry[i]))
                        ok=0;
                if(ok) return;
            }
            else if(ry[i]==y){
                bool ok=1;
                for(int j=0;ok && j<n;++j)
                    if(j!=i && ry[j]==y && rx[j]>min(x,rx[i]) && rx[j]<max(x,rx[i]))
                        ok=0;
                if(ok) return;
            }
        }
        else if(t[i]=='H'){
            if(horse(i,x,y)) return;
        }
        else if(t[i]=='C'){
            if(rx[i]==x){
                int cnt=0;
                for(int j=0;cnt<=1 && j<n;++j)
                    if(j!=i && rx[j]==x && ry[j]>min(y,ry[i]) && ry[j]<max(y,ry[i]))
                        ++cnt;
                if(cnt==1) return;
            }
            else if(ry[i]==y){
                int cnt=0;
                for(int j=0;cnt<=1 && j<n;++j)
                    if(j!=i && ry[j]==y && rx[j]>min(x,rx[i]) && rx[j]<max(x,rx[i]))
                        ++cnt;
                if(cnt==1) return;
            }
        }
    }
    f=1;
}
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int vx[]={-1,1,0,0},vy[]={0,0,-1,1},bgx,bgy;
    while(~scanf("%d%d%d",&n,&bgx,&bgy) && n){
        memset(t,0,sizeof(t));
        memset(rx,0,sizeof(rx));
        memset(ry,0,sizeof(ry));
        for(int i=0;i<n;++i)
            scanf(" %c%d%d",t+i,rx+i,ry+i);
        for(int i=0;i<n;++i)
            if(t[i]=='G'){
                if(ry[i]==bgy){
                    bool ok=1;
                    for(int j=0;ok && j<n;++j)
                        if(j!=i && ry[j]==bgy)
                            ok=0;
                    if(ok) t[i]=rx[i]=ry[i]=-1;
                }
                break;
            }
        f=0;
        for(int i=0;i<4;++i){
            int nx=bgx+vx[i],ny=bgy+vy[i];
            if(1<=nx && nx<=3 && 4<=ny && ny<=6)
                func(nx,ny);
        }
        if(f) printf("NO\n");
        else printf("YES\n");
    }
    //printf("\nTime used = %lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

