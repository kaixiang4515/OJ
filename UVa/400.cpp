#include <iostream>
//#include <cstdio>
//#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
#include <string>
using namespace std;
const int maxcol=60;
string filenames[105];
void print(const string &str, int len){
    cout << str;
    for(int i=len-str.length();i;--i) cout << " ";
}
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        int maxl=0;
        for(int i=0;i!=n;++i){
            cin >> filenames[i];
            maxl=max(maxl,(int)filenames[i].length());
        }
        int cols=(maxcol-maxl)/(maxl+2)+1,rows=(n-1)/cols+1;
        for(int i=0;i<60;++i) cout << "-";
        cout << "\n";
        sort(filenames,filenames+n);
        for(int r=0;r<rows;++r){
            bool first=0;
            int tmp;
            for(int c=0;c<cols;++c){
                int idx=c*rows+r;
                if(idx<n){
                    if(first) cout << "  ";
                    else first=1;
                    print(filenames[idx],maxl);
                    tmp=filenames[idx].length();
                }
            }
            cout << "\n";
        }
    }
    return 0;
}

