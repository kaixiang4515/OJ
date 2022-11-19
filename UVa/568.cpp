// #include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#define Inf 0x3f3f3f3f
#define NeInf 0xc0c0c0c0
#define REP(i, n) for (int i = 0; i < int(n); ++i)

using namespace std;
using LL = long long;

LL a[10005] = {1};

int main() {
#ifdef LOCAL
    freopen("../file/in.txt", "r", stdin);
    freopen("../file/out.txt", "w", stdout);
#endif  // LOCAL
    ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed << setprecision(3);
    REP(i, 10000) {
        int t = i + 1;
        a[t] = a[i] * t;
        while (!(a[t] % 10)) a[t] /= 10;
        a[t] %= int(1e6);  // 5^5 = 3125 < 10000 < 5^6 = 15625, 一次最多產生5個0, 所以取後6位
    }
    int n;
    while (cin >> n) {
        cout << setw(5) << n << " -> " << a[n] % 10 << "\n";
    }
    return 0;
}
