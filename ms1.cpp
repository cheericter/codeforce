#include<cstdio>
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
string to_string(int i){
    if (i==0)
        return string("0");
    else if (i==1)
        return string("1");
}
string Binary(int num)
{
	string tmp;
	for(int i=0;i<8;i++)
	{
		tmp=to_string((num&1))+tmp;
		num=num>>1;
	}
	return tmp;
}
string iptostr(string ip, int num){

}

int main(){
    freopen ("in.txt","r",stdin);
    string cmd;
    string ip;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
         cin>>cmd>>ip;
         if(ip.indexof("/")==-1){

         }else{

         }

    }

    cout<<cmd<<ip;
}
