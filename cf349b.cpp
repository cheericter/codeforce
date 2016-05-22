#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int maxl=0;
    int suml=0;
    for (int i=0;i<n;i++){
        int temp;
        cin>>temp;
        suml+=temp;
        if(temp>maxl){
            maxl=temp;
        }
    }
    suml-=maxl;
    cout<<(maxl-suml+1)<<endl;
}
