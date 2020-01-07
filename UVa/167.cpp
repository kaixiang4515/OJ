//#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int used[8],L[15],R[15];
int in[8][8];
vector<int> locate[8];

void Queens(int n){
    if(n >= 8){
        for(int i=0;i<8;++i){
            locate[i].push_back(used[i]);
        }
        return;
    }

    for(int i=0;i<8;++i){
        if(used[i] == -1 && L[n-i+7] == -1 && R[n+i] == -1){
            used[i] = L[n-i+7] = R[n+i] = n;
            Queens(n+1);
            used[i] = L[n-i+7] = R[n+i] = -1;
        }
    }
}

int main()
{
    //freopen("./input.txt","r",stdin);
    //freopen("./output.txt","w",stdout);
    memset(used,-1,sizeof(used));
    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));
    Queens(0);
    
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<8;++i)
            for(int j=0;j<8;++j)
                scanf("%d",&in[i][j]);

        int ans = 0;
        for(int i=0;i<92;++i){
            int ta = 0;
            for(int j=0;j<8;++j){
                ta += in[j][locate[j][i]];
            }
            ans = max(ans, ta);
        }
        printf("%5d\n",ans);
    }
    return 0;
}
