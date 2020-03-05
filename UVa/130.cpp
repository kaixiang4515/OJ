#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int que[105];

int next(int s, int cnt, int n){
    while(cnt){
        s = (s==n)?1:s+1;
        if(que[s]) --cnt;
    }

    return s;
}

int simu(int n, int k){
    if(n == 1) return 1;
    for(int i=1;i<=n;++i) que[i] = i;
    int cnt = n, idx = 0;
    while(cnt > 1){
        int ni = next(idx,k,n);
        que[ni] = 0;
        int ni2 = next(ni,k,n);
        que[ni] = que[ni2];
        que[ni2] = 0;
        idx = ni;
        --cnt;
    }

    return que[idx];
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n,k;
    while(cin >> n >> k && n){
        int t = simu(n,k);
        if(t == 1) cout << "1\n";
        else cout << n-(t-1-1) << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

