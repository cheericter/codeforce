#include<iostream>
using namespace std;
int main(){
    string s,subs;
    cin>>s>>subs;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<subs.size();j++){
            if(s[i+j]!=subs[j]) break;
            if(j==subs.size()-1) {
                    cnt++;
                    i+=subs.size()-1;
            }
        }
    }
    cout<<cnt<<endl;
}
