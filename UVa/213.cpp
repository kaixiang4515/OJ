//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;
char code[7][1<<7];
string str;

void Init(const string& s){
    auto it=s.begin();
    for(int len=1;len<8 && it!=s.end();++len){
        for(int i=0,e=(1<<len)-1;i<e && it!=s.end();++i)
            code[len][i] = *it,++it;
    }
}
/*
void printcode(){
    for(int len=1;len<8;++len){
        for(int i=0,e=(1<<len)-1;i<e;++i){
            if(!code[len][i]) return;
            printf("Code[%d][%d] = %c\n",len,i,code[len][i]);
        }
    }
}
*/
char readchar(){
    while(1){
        char ch=cin.get();
        if(ch!='\n' && ch!='\r') return ch;
    }
}

int Decode(int len){
    int t=0;
    for(int i=0;i<len;++i){
        t=(t<<1)+ readchar() -'0';
    }
    return t;
}

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin,str)){
        memset(code,0,sizeof(code));
        Init(str);
        //printcode();

        int len;
        while(1){
            len=Decode(3);
            if(!len) break;
            int w;
            while(1){
                w=Decode(len);
                if(w==(1<<len)-1) break;
                cout << code[len][w];
            }
        }
        cout << "\n"; cin.get();
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

