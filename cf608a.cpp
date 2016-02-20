#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MAXN 1005
int main(){
    int n,s;
    int t;
    while(cin>>n>>s){
        vector<int> a(1005,0);
         t=-1;
        for(int i=0;i<n;i++){
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            if(a[tmp1]<tmp2)
                a[tmp1]=tmp2;
        }
        for(int i=s;i>=0;i--){
            t++;
            if(a[i]-t>0)
                t=a[i];

        }
        cout<<t<<endl;
    }
}
