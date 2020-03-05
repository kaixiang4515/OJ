#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <algorithm>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0

using namespace std;

double cost[5][3] = {
    0.1, 0.06, 0.02,
    0.25, 0.15, 0.05,
    0.53, 0.33, 0.13,
    0.87, 0.47, 0.17,
    1.44, 0.8, 0.3
};

int main(){
    //freopen("../file/input_ascii.txt","r",stdin);
    //freopen("../file/output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    char ch, str[10];
    int sh,sm,eh,em;
    while(~scanf("%c",&ch) && ch != '#'){
        scanf("%s %d %d %d %d",str,&sh,&sm,&eh,&em);
        getchar();
        int ss = sh*60+sm, es = eh*60+em, l;
        if(ss < es) l = es - ss;
        else l = (eh+24)*60+em - ss;

        int d = 0, e = 0, n = 0, tss = ss;
        while(l > 0){
            if(8*60 <= tss && tss < 18*60){  //Day
                int t = min(18*60 - tss, l);
                d += t;
                l -= t;
                tss += t;
            }
            else if(18*60 <= tss && tss < 22*60){  //Evening
                int t = min(22*60 - tss, l);
                e += t;
                l -= t;
                tss += t;
            }
            else{  //Night
                if(22*60 <= tss){  //22:00 ~ 00:00
                    int t = min(24*60 - tss, l);
                    n += t;
                    l -= t;
                    tss += t;
                    if(tss == 24*60) tss = 0;
                }
                else{  //00:00 ~ 08:00
                    int t = min(8*60 - tss, l);
                    n += t;
                    l -= t;
                    tss += t;
                }
            }
        }
        double s = cost[ch-'A'][0]*d + cost[ch-'A'][1]*e + cost[ch-'A'][2]*n;
        printf("%10s%6d%6d%6d%3c%8.2f\n",str, d, e, n, ch, s);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

