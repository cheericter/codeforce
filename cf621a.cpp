#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,cnt=0,sup=1000000009;
    long long ans=0;
    scanf("%d",&n);
    while(n--){
        int tmp;
        scanf("%d",&tmp);
        ans+=tmp;
        if(tmp%2==1){
            cnt++;
            if(sup>tmp) sup=tmp;
        }
    }
    if(cnt%2==1) ans-=sup;
    cout<<ans<<endl;
}
