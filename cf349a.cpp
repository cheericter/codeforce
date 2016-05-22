#include<iostream>
using namespace std;
int main(){
    double PI=3.1415926;
    double d,h,v,e;
    cin>>d>>h>>v>>e;
    double dv=v/(PI*(d/2)*(d/2));
    if(e>=dv){
        cout<<"NO"<<endl;
    }else if(h/(dv-e)>10000){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<h/(dv-e)<<endl;
    }
}
