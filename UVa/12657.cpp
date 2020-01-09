#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <algorithm>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int Left[100005],Right[100005];

void link(int L, int R){
    Right[L] = R; Left[R] = L;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,ca=0;
    long long s;
    while(cin >> n >> m){
        for(int i=1;i<=n;++i){
            Left[i] = i-1;
            Right[i] = i+1;
        }
        Right[0] = 1; Left[0] = 0; Right[n+1] = n+1; Left[n+1] = n;
        bool token = 0;
        int op;
        while(m--){
            cin >> op;
            if(op == 4) token = !token;
            else{
                int x,y;
                cin >> x >> y;
                if(op == 3 && Right[y] == x) swap(x,y);
                if(op != 3 && token) op = 3-op;

                int xl = Left[x], xr = Right[x], yl = Left[y], yr = Right[y];
                if(op == 1 && Left[y] != x){
                    link(xl,xr); link(yl,x); link(x,y);
                }
                if(op == 2 && Right[y] != x){
                    link(xl,xr); link(y,x); link(x,yr);
                }
                if(op == 3){
                    if(Right[x] == y){
                        link(xl,y); link(y,x); link(x,yr);
                    }
                    else{
                        link(xl,y); link(y,xr); link(yl,x); link(x,yr);
                    }
                }
            }
        }

        s = 0;
        if(token){
            int i = Left[n+1];
            while(i!=Left[i]){
                s += i;
                i = Left[i]; i = Left[i];
            }
        }
        else{
            int i = Right[0];
            while(i!=Right[i]){
                s += i;
                i = Right[i]; i = Right[i];
            }
        }
        cout << "Case " << ++ca << ": " << s << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

