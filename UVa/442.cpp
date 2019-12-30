#include <iostream>
//#include <cstdio>
//#include <bits/stdc++.h>
#include <stack>
#include <string>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

struct Matrix{
    int a,b;
    Matrix(int a=0, int b=0):a(a), b(b) {}
}m[26];

stack<Matrix> s;

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        string name;
        cin >> name;
        int idx = name[0]-'A';
        cin >> m[idx].a >> m[idx].b;
    }

    string expr;
    while(cin >> expr){
        bool error = false;
        int ans = 0;
        for(int i=0;i<expr.size();++i){
            if(isalpha(expr[i])) s.push(m[expr[i]-'A']);
            else if(expr[i] == ')'){
                Matrix m2 = s.top(); s.pop();
                Matrix m1 = s.top(); s.pop();
                if(m1.b != m2.a){ error = true; break; }

                ans += m1.a * m1.b * m2.b;
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if(error) cout << "error\n";
        else cout << ans << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

