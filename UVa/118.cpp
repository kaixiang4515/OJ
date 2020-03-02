#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

bool f[55][55];
int n,m;

struct robot{
    int x, y;
    char d;
    robot(int x, int y, char d):x(x),y(y),d(d) {}

    void Turn(char t){
        if(t == 'L'){
            switch(d){
                case 'N':
                    d = 'W';
                    break;
                case 'E':
                    d = 'N';
                    break;
                case 'S':
                    d = 'E';
                    break;
                case 'W':
                    d = 'S';
                    break;
            }
        }
        else{
            switch(d){
                case 'N':
                    d = 'E';
                    break;
                case 'E':
                    d = 'S';
                    break;
                case 'S':
                    d = 'W';
                    break;
                case 'W':
                    d = 'N';
                    break;
            }
        }
    }

    bool Forward(){
        if(d == 'N'){
            if(y == m){
                if(!f[x][y]){
                    f[x][y] = 1;
                    return 0;
                }
            }
            else{
                ++y;
            }
            return 1;
        }
        if(d == 'S'){
            if(y == 0){
                if(!f[x][y]){
                    f[x][y] = 1;
                    return 0;
                }
            }
            else{
                --y;
            }
            return 1;
        }
        if(d == 'E'){
            if(x == n){
                if(!f[x][y]){
                    f[x][y] = 1;
                    return 0;
                }
            }
            else{
                ++x;
            }
            return 1;
        }
        if(d == 'W'){
            if(x == 0){
                if(!f[x][y]){
                    f[x][y] = 1;
                    return 0;
                }
            }
            else{
                --x;
            }
            return 1;
        }
    }
};

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    int x,y;
    char d;
    string op;
    while(cin >> x >> y >> d){
        robot r(x,y,d);
        cin >> op;

        bool out = 0;
        for(int i=0;i<op.size();++i){
            if(op[i] == 'F'){
                if(!r.Forward()){ out = 1; break; }
            }
            else r.Turn(op[i]);
        }

        cout << r.x << " " << r.y << " " << r.d;
        if(out) cout << " LOST";
        cout << "\n";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

