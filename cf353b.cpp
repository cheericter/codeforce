#include<iostream>
using namespace std;
int main(){
    long long n,a[4];
    cin>>n>>a[0]>>a[1]>>a[2]>>a[3];
    long long minv=1000000,maxv=-1;
    long long  b[4];
    b[0]=a[0]+a[1];
    b[1]=a[0]+a[2];
    b[2]=a[3]+a[1];
    b[3]=a[3]+a[2];
    for(int i=0;i<4;i++){
        if(b[i]<minv) minv=b[i];
        if(b[i]>maxv) maxv=b[i];
    }
    if (n<(maxv-minv))
        cout<<'0'<<endl;
    else
        cout<<n*(n-(maxv-minv))<<endl;;
}
