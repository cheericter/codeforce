#include<iostream>
using namespace std;
int main(){
    long long a,b,c;
    long long n;
    cin>>n>>a>>b>>c;
    if(a<=b-c){
        cout<<(n/a)<<endl;
    }else {
        long long tmp=(n-c)/(b-c);
        if(n-c<0) tmp=0;
        cout<<tmp+(n-tmp*(b-c))/a<<endl;
    }
}
