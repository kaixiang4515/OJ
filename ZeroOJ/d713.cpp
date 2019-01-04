//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <ctime>
#include <bits/stdc++.h>
using namespace std;
priority_queue<int> mxpq;
priority_queue<int, vector<int>, greater<int>> mnpq;
int main()
{
    //freopen("..\\file\\input.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    /*clock_t start_c,end_c;
    start_c=clock();*/
    int n=0,a;
    while(~scanf("%d",&a)){
        ++n;
        mnpq.push(a);
        if(!mxpq.empty() && mxpq.top()>mnpq.top()){
            int t=mnpq.top();
            mnpq.pop(); mnpq.push(mxpq.top());
            mxpq.pop(); mxpq.push(t);
        }
        if(n%2){
            printf("%d\n",mnpq.top());
        }
        else{
            mxpq.push(mnpq.top());
            mnpq.pop();
            printf("%d\n",(mxpq.top()+mnpq.top())>>1);
        }
    }
    /*end_c=clock();
    printf("Use %.0lf ms\n", (((double)(end_c-start_c))/CLOCKS_PER_SEC)*1000);*/
    return 0;
}

