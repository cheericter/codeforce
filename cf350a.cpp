#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dayoff=(n/7)*2;
    int maxd=(n%7>2?2:n%7);
    int mind=n%7<=5?0:(n%7-5);
    cout<<(dayoff+mind)<<" "<<(dayoff+maxd)<<endl;
}
