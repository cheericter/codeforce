#include<iostream>
#include<string>
#include<map>
using namespace std;
int check(string s){

    map<char, int> cmd;
    cmd['U'] = 1;
    cmd['D'] = -1;
    cmd['L'] = 1;
    cmd['R'] = -1;
    int ud = 0;
    int lr = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='U'||s[i]=='D'){
            ud += cmd[s[i]];
        }else if(s[i]=='L'||s[i]=='R'){
            lr += cmd[s[i]];
        }
    }
     return ud==0 && lr==0;

}
int main(){
    int n;
    string str;
    int cnt=0;
    cin>>n;
    cin>>str;
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length()+1;j++){
            string ss=str.substr(i,j-i);
            //cout<<ss<<endl;
            if(check(ss)){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
