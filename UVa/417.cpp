#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#define Inf 0x3f3f3f3f3f
#define Neinf 0xc0c0c0c0

using namespace std;

map<string, int> m;

bool is_legal(const string& s){
    for(int i=0;i<s.size()-1;++i){
        if(s[i] >= s[i+1]) return false;
    }
    return true;
}

void carry(string& s){
    bool append = true;
    char ch = 'z';
    for(int i=s.size()-1;i>=0;--i,--ch){
        if(s[i] != ch){ append = false; break; }
    }
    if(append){
        ch = 'a';
        for(int i=0;i<s.size();++i) s[i] = ch++;
        s += ch;
        return;
    }
    s.back() = 'a';
    int idx = s.size()-2;
    while(idx >= 0 && ++s[idx] >= 'z'){
        s[idx--] = 'a';
    }
    while(!is_legal(s)){
        if(s.back() != 'z') ++s.back();
        else{
            s.back() = 'a';
            int idx = s.size()-2;
            while(idx >= 0 && ++s[idx] >= 'z'){
                s[idx--] = 'a';
            }
        }
    }
}

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    string str="a";
    int n=1;
    while(str.size() <= 5){
        m[str] = n++;
        if(str.back() != 'z'){
            ++str.back();
        }
        else{
            carry(str);
        }
    }
    while(cin >> str){
        if(is_legal(str)) cout << m[str] << "\n";
        else cout << "0\n";
    }
    return 0;
}
