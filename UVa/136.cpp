//#include <iostream>
#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int coeff[3]={2,3,5};
priority_queue<LL, vector<LL>, greater<LL> > mnpq;
set<LL> s;
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    mnpq.push(1); s.insert(1);
    for(int i=1;;++i){
        LL x=mnpq.top(); mnpq.pop();
        if(i==1500){
            printf("The 1500'th ugly number is %d.\n",x);
            break;
        }
        for(int j=0;j!=3;++j){
            LL y=x*coeff[j];
            if(!s.count(y)){ s.insert(y); mnpq.push(y); }
        }
    }
    return 0;
}

