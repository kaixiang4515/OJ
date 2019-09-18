#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c[105][105];
int Combination(int n, int m){
    if(n==m || m==0) return 1;
    if(c[n][m]) return c[n][m];
    return c[n][m]=Combination(n-1,m-1)+Combination(n-1,m);
}

int main()
{
    //freopen("./input.txt","r",stdin);
    //freopen("./output.txt","w",stdout);
    memset(c,0,sizeof(c));
    int n,m;
    while(cin >> n >> m && n)
        cout << n << " things taken " << m << " at a time is " << Combination(n,m) << " exactly.\n";

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
