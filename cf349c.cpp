#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#define Si(a) scanf("%d",&a)
#define Sl(a) scanf("%lld",&a)
#define Sd(a) scanf("%lf",&a)
#define Ss(a) scanf("%s",a)
#define Pi(a) printf("%d\n",(a))
#define Pl(a) printf("%lld\n",(a))
#define Pd(a) printf("%lf\n",(a))
#define Ps(a) printf("%s\n",(a))
#define W(a) while(a--)
#define mem(a,b) memset(a,(b),sizeof(a))
#define FOP freopen("data.txt","r",stdin)
#define inf 0x3f3f3f3f
#define maxn 100010
#define mod 1000000007
#define PI acos(-1.0)
#define LL long long
using namespace std;

bool dp[maxn][2];
set<string> ans;
int main(){
    string str;
    cin>>str;
    int len=str.size();
    for(int i=len-1;i>=5;i--){
        if(i+2==len){
            dp[i][0]=1;
            ans.insert(str.substr(i,2));
        }
        if(i+3==len){
            dp[i][1]=1;
            ans.insert(str.substr(i,3));
        }
        if(dp[i+3][0]||(dp[i+3][1]&&str.substr(i,3)!=str.substr(i+3,3))){
            dp[i][1]=1;
            ans.insert(str.substr(i,3));
        }
        if(dp[i+2][1]||(dp[i+2][0]&&str.substr(i,2)!=str.substr(i+2,2))){
            dp[i][0]=1;
            ans.insert(str.substr(i,2));
        }
    }
    cout<<ans.size()<<endl;
    for(set<string>::iterator it = ans.begin();it!=ans.end();it++){
        cout<<*it<<endl;
    }
}
