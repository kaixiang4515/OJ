#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int n,a[105],goal;
char s[105];
bool is_find;
bool used[105][32000*2 + 5];

void dfs(int k, int t){
    if(used[k][t+32000]) return;
    if(k >= n){
        if(t == goal) is_find = true;
        return;
    }

    used[k][t+32000] = true;
    int nt;
    nt = t + a[k];
    if(!is_find && -32000 <= nt && nt <= 32000){
        s[k-1] = '+';
        dfs(k+1,nt);
    }
    nt = t - a[k];
    if(!is_find && -32000 <= nt && nt <= 32000){
        s[k-1] = '-';
        dfs(k+1,nt);
    }
    nt = t * a[k];
    if(!is_find && -32000 <= nt && nt <= 32000){
        s[k-1] = '*';
        dfs(k+1,nt);
    }
    nt = t / a[k];
    if(!is_find && nt * a[k] == t && -32000 <= nt && nt <= 32000){
        s[k-1] = '/';
        dfs(k+1,nt);
    }

    //s[k-1] = 0;
    return;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int ca;
    cin >> ca;
    while(ca--){
        cin >> n;
        for(int i=0;i<n;++i) cin >> a[i];
        cin >> goal;
        memset(s,0,sizeof(s));
        memset(used,false,sizeof(used));
        is_find = false;

        dfs(1,a[0]);
        if(is_find){
            for(int i=0;i<n;++i){
                cout << a[i];
                if(i < n-1) cout << s[i];
            }
            cout << "=" << goal << "\n";
        }
        else cout << "NO EXPRESSION\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

