#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    //freopen("input.txt","r",stdin);
    int T,a;
    scanf("%d",&T);
    while(T--){
        int n;
        v.clear();
        scanf("%d%d",&n,&a);
        v.push_back(a);
        for(int i=1;i!=n;++i){
            scanf("%d",&a);
            if(a>v.back()) v.push_back(a);
            else *upper_bound(v.begin(),v.end(),a)=a;
        }
        printf("%d\n",v.size());
    }
    return 0;
}
