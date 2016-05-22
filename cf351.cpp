#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<int>  t(90,1);
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        t[tmp-1]=0;
    }
    int btime=0;
    int i=0;
    for(i=0;i<90;i++){
        //cout<<i<<" "<<t[i]<<endl;
        if(t[i]==0){
            btime=0;
        }else{
            btime++;
            if(btime==15){
                break;
            }
        }
    }
    if(i==90)
        cout<<"90"<<endl;
    else
        cout<<(i+1)<<endl;
}
