#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
bool f=0;

struct bigint{
    static const int BASE=1000000;
    static const int WIDTH=6;
    vector<int>  v;

    bigint(long long n=0){ *this=n; }
    bigint(const string& str){ *this=str; }
    bigint& operator=(long long n){
        v.clear();
        do{
            v.push_back(n%BASE);
            n/=BASE;
        }while(n);
        return *this;
    }
    bigint& operator=(const string& str){
        v.clear();
        int e=str.size(),b;
        for(int i=0;e>0;++i){
            int t=0;
            for(b=max(0,e-WIDTH);b<e;++b)
                t=t*10+str[b]-'0';
            v.push_back(t);
            e-=WIDTH;
        }
        return *this;
    }
    bigint& operator=(const bigint& b){
        v.clear();
        for(int i=0;i<b.v.size();++i)
            v.push_back(b.v[i]);
        return *this;
    }
    bigint operator+(const bigint& b)const{
        bigint c;
        c.v.clear();
        int t=0;
        for(int i=0,j=0;i < v.size() || j < b.v.size();++i,++j){
            if(i < v.size()) t+=v[i];
            if(j < b.v.size()) t+=b.v[j];
            c.v.push_back(t%BASE);
            t/=BASE;
        }
        while(t>0){
            c.v.push_back(t%BASE);
            t/=BASE;
        }
        if(c.v.size()>10) f=1;
        return c;
    }

};

vector<bigint> arr[2];

ostream& operator<<(ostream& a, const bigint& b){
    a << b.v.back();
    for(int i=b.v.size()-2;i>=0;--i){
        char str[20];
        sprintf(str,"%06d",b.v[i]);
        int len=strlen(str);
        for(int j=0;j<len;++j) a << str[j];
    }
    return a;
}
/*
istream& operator>>(istream& a, bigint& b){
    string str;
    if(!(a >> str)) return a;
    b=str;
    return a;
}
*/
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bigint a,b;
    vector<bigint>& p=arr[0],q=arr[1];
    p.push_back(bigint(1));
    q.push_back(bigint(1));
    
    for(int i=0;!f;++i){
        for(int j=0;j<=i;++j){
            if(q.size()-1<j) q.push_back(bigint(0));
            if(j==0 || j==i){
                q[j]=1;
            }
            else{
                q[j]=p[j-1]+p[j];
            }
            if(j) cout << " ";
            cout << q[j];
        }
        cout << "\n";
        swap(p,q);
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

