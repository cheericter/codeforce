#include<iostream>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long i;
    for(i=1;i<100000;i++){
        long long  s=i*(i+1)/2;
        if(s>=k){
            break;
        }
    }
    long long index=k-(i-1)*i/2;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(i==index-1){
            cout<<temp<<endl;
        }
    }
}
