//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
string a,b;
int cta[26];

int guess(char ch){
    if(cta[ch-'a']==1){
        cta[ch-'a']=-1;
        return 1;
    }
    else if(cta[ch-'a']==0){
        cta[ch-'a']=-1;
        return -1;
    }
    return 0;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n && n!=-1){
        a.clear(); b.clear();
        memset(cta,0,sizeof(cta));
        //memset(ctb,0,sizeof(ctb));
        cin >> a >> b;
        for(int i=0;i<a.size();++i) cta[a[i]-'a']=1;
        int charsum=0;
        for(int i=0;i<26;++i) if(cta[i]) ++charsum;

        int deadcnt=0;
        for(int i=0;i<b.size() && charsum>0 && deadcnt<7;++i){
            int state=guess(b[i]);
            if(state==-1) ++deadcnt;
            else if(state==1) --charsum;
        }

        cout << "Round " << n << "\n";
        if(charsum<=0) cout << "You win.\n";
        else if(deadcnt>=7) cout << "You lose.\n";
        else cout << "You chickened out.\n";
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

