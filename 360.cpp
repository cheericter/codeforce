#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int getint(string s){
    bool in=false;
    int cnt=0;
    int cur =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            in=true;
            cur+=1;
        }else{
            if(in){
                cnt= cnt+cur-1;
                in=false;
            }
            cur=0;
        }
    }
    if(in){
        cnt +=cur-1;
    }
    return cnt;
}
int main(){
    //freopen ("in.txt","r",stdin);
    int m,n;
    string str;
    while(cin>>m>>n){

        cin>>str;
        int cnt =0;
        int cum =0;
        bool in=false;
        //cout<<getint(str)<<endl;
        int num = getint(str);
        int p;
        char ch;
        for(int i=0;i<n;i++){
            cin>>p>>ch;
            string sub;
            p=p-1;
            if(p==0){
                sub=str.substr(p,2);
            }else if(p==str.length()-1){
                sub=str.substr(p-1,2);
            }else{
                sub=str.substr(p-1,3);
            }
            //cout<<getint(sub)<<endl;
            int ori =getint(sub);
            //cout<<sub<<endl;
            //cout<<"ori"<<ori<<endl;

            str[p]=ch;
            if(p==0){
                sub=str.substr(p,2);
            }else if(p==str.length()-1){
                sub=str.substr(p-1,2);
            }else{
                sub=str.substr(p-1,3);
            }
            //cout<<sub<<endl;
            int mod =getint(sub);
            //cout<<"mod"<<mod<<endl;
            num+=mod-ori;
            cout<<num<<endl;;
        }
    }
    //cout<<getint(string("..."))<<endl;
}
