//#include <iostream>
//#include <cstdio>
#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
using namespace std;

int main()
{
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.get(); cin.get();
    for(int ca=1;ca<=t;++ca){
        string s,ans;
        if(ca>1) cout << "\n";
        cout << "Case #" << ca << ":\n";

        while(getline(cin, s)){
            if(s.size()==0) break;
            ans.clear();

            stringstream ss(s);
            string tmp;
            while(ss >> tmp){
                if(tmp.size() > ans.size()){
                    ans+=tmp[ans.size()];
                }
            }
            cout << ans << "\n";
        }
    }

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

