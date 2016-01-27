#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int seg[10]={6,2,5,5,4,5,6,3,7,6};

int cal(int x){
    if(x==0) return seg[0];
    int res=0;
    while(x>0){
        res+=seg[x%10];
        x/=10;
    }
    return res;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        int sum=0;
        for(int i=a;i<=b;i++){
            sum+=cal(i);
        }
        cout<<sum<<endl;
    }
}
