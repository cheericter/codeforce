#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int left=1,right=n;
    for(int i=0;i<m;i++){
        int ll,rr;
        cin>>ll>>rr;
        if(ll>rr){
            int temp=ll;
            ll=rr;
            rr=temp;
        }
        left=max(left,ll);
        right=min(right,rr);
    }
    cout<<((right-left)>0?(right-left):0 )<<endl;
}
