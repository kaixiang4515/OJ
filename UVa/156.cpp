#include <iostream>
//#include <cstdio>
//#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cctype>
using namespace std;
vector<string> words;
map<string,int> cnt;
string repr(const string &str){
    string ans=str;
    for(int i=0;i<ans.length();++i)
        ans[i]=tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s){
        if(s[0]=='#') break;
        words.push_back(s);
        string r=repr(s);
        if(!cnt.count(r)) cnt[r]=0;
        ++cnt[r];
    }
    vector<string> ans;
    for(int i=0;i!=words.size();++i)
        if(cnt[repr(words[i])]==1) ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
    for(int i=0;i!=ans.size();++i)
        cout << ans[i] << '\n';
    return 0;
}

