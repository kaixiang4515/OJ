//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
string a,b;
int cnt[2][26],num[2][105];

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> a >> b){
        memset(cnt,0,sizeof(cnt));
        memset(num,0,sizeof(num));

        for(int i=0;i<a.size();++i) ++cnt[0][a[i]-'A'];
        for(int i=0;i<b.size();++i) ++cnt[1][b[i]-'A'];

        for(int i=0;i<26;++i) ++num[0][cnt[0][i]],++num[1][cnt[1][i]];
        bool yes=1;
        for(int i=1;i<=100;++i) if(num[0][i]!=num[1][i]){ yes=0; break; }
        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

