#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <queue>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

priority_queue<int> mxpq;
priority_queue<int, vector<int>, greater<int>> mnpq;

int main(){
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int x;
    while(cin >> x){
        if(mxpq.empty() || x <= mxpq.top()) mxpq.push(x);
        else mnpq.push(x);

        if(mxpq.size() > mnpq.size() + 1){
            mnpq.push(mxpq.top());
            mxpq.pop();
        }
        else if(mnpq.size() > mxpq.size() + 1){
            mxpq.push(mnpq.top());
            mnpq.pop();
        }

        if(mxpq.size() == mnpq.size()) cout << (mxpq.top()+mnpq.top()>>1) << "\n";
        else if(mxpq.size() > mnpq.size()) cout << mxpq.top() << "\n";
        else cout << mnpq.top() << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

