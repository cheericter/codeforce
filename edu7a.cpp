#include<iostream>
using namespace std;


long long div(long long l,long long r,long long d){
    long long mid = (l+r)/2;
    if(l+1==r){
        return l;
    }else if (mid*(mid+1)/2>d){
        r=mid;
        return div(l,r,d);
    }else if(mid*(mid+1)/2<=d){
        l=mid;
        return div(l,r,d);
    }
}
int main(){
     long long n;
     cin>>n;
     long long l;
     l=div(0,100000000L,n);
     //cout<<l<<endl;
     cout<<((n-l*(l+1)/2)==0?l:(n-l*(l+1)/2))<<endl;
}
