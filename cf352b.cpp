#include<string>
#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    map<char,int> dict;
    for(int i=0;i<n;i++){
        dict[s[i]]++;
    }
    if(n>26) cout<<"-1"<<endl;
    else if(n==1) cout<<"0"<<endl;
    else cout<<(n-dict.size())<<endl;
}
