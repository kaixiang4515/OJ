//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
//#include <iomanip>

//#define LOCAL
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

stack<char> S;

int main(){
    #ifdef LOCAL
        freopen("./file/in.txt","r",stdin);
        freopen("./file/out.txt","w",stdout);
    #endif // LOCAL
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(3);
    int t;
    string s;
    cin >> t;
    cin.get();cin.get();
    bool b = 0;
    while(t--){
        if(b) cout << "\n";
        else b = 1;
        while(getline(cin, s) && s.size()){
            //cout << s[0];

            if(isdigit(s[0])) cout << s[0];
            else{
                const char& c = s[0];
                switch(c){
                case '(':
                    S.push(c);
                    break;
                case ')':
                    while(S.top() != '('){
                        cout << S.top();
                        S.pop();
                    }
                    if(S.top() == '(') S.pop();
                    break;
                case '*':
                case '/':
                    while(!S.empty() && (S.top() == '*' || S.top() == '/')){
                        cout << S.top();
                        S.pop();
                    }
                    S.push(c);
                    break;
                default:
                    while(!S.empty() && S.top() != '('){
                        cout << S.top();
                        S.pop();
                    }
                    S.push(c);
                }
            }
        }
        //cout << "\n";
        if(!s.size()){
            while(!S.empty()){

