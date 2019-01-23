//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
//#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;
set<string> dict;
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    while(cin >> s){
        for(int i=0;i!=s.length();++i)
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';
        stringstream ss(s);
        while(ss >> t) dict.insert(t);
    }
    for(auto it=dict.begin();it!=dict.end();++it)
            cout << *it << "\n";
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

