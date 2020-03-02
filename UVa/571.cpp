#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <cstring>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

int a,b,n;
string msg[6]={"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

struct State{
    int a, b;
    State(int a=0, int b=0):a(a), b(b){}
    bool operator==(const State& y)const{
        return this->a == y.a && this->b == y.b;
    }
    bool operator!=(const State& y)const{
        return !(*this == y);
    }
};

State par[1005][1005];
int op[1005][1005];

void print(State s){
    if(par[s.a][s.b] != s){
        print(par[s.a][s.b]);
        cout << msg[op[s.a][s.b]] << "\n";
    }
}

void solve(){
    memset(par,-1,sizeof(par));
    memset(op,-1,sizeof(op));
	
    queue<State> que;
    par[0][0] = State(0,0);
    que.push(State(0,0));
    while(!que.empty()){
        State ts = que.front(); que.pop();  //printf("========================\nts.a = %d , ts.b = %d\n",ts.a,ts.b);
        if(ts.b == n){
            print(ts);
            return;
        }

        int ta, tb;
        ta = a; tb = ts.b;
        if(par[ta][tb].a == -1){    //printf("ta = %d , tb = %d , op = %d\n",ta,tb,0);
            par[ta][tb] = ts;
            op[ta][tb] = 0;
            que.push(State(ta,tb));
        }
        ta = ts.a; tb = b;
        if(par[ta][tb].a == -1){    //printf("ta = %d , tb = %d , op = %d\n",ta,tb,1);
            par[ta][tb] = ts;
            op[ta][tb] = 1;
            que.push(State(ta,tb));
        }
        ta = 0; tb = ts.b;
        if(par[ta][tb].a == -1){    //printf("ta = %d , tb = %d , op = %d\n",ta,tb,2);
            par[ta][tb] = ts;
            op[ta][tb] = 2;
            que.push(State(ta,tb));
        }
        ta = ts.a; tb = 0;
        if(par[ta][tb].a == -1){    //printf("ta = %d , tb = %d , op = %d\n",ta,tb,3);
            par[ta][tb] = ts;
            op[ta][tb] = 3;
            que.push(State(ta,tb));
        }
        ta = (ts.a + ts.b >= b)?(ts.a + ts.b - b):0; tb = ts.a + ts.b - ta;
        if(par[ta][tb].a == -1){    //printf("ta = %d , tb = %d , op = %d\n",ta,tb,4);
            par[ta][tb] = ts;
            op[ta][tb] = 4;
            que.push(State(ta,tb));
        }
        ta = (ts.a + ts.b >= a)?a:(ts.a + ts.b); tb = ts.a + ts.b - ta;
        if(par[ta][tb].a == -1){    //printf("ta = %d , tb = %d , op = %d\n",ta,tb,5);
            par[ta][tb] = ts;
            op[ta][tb] = 5;
            que.push(State(ta,tb));
        }
    }
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    while(cin >> a >> b >> n){
        solve();
        cout << "success\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

