#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

int main(){
    int h,m;
    int gap;
    char punt;
    string s;
    cin>>s;
    cin>>gap;
    stringstream ss;
    ss<<s;
    ss>>h;
    ss>>punt;
    ss>>m;
    //cout<<h<<m<<endl;
    m += gap;
    int hh = m/60;
    m%=60;
    h+=hh;
    h%=24;
    cout<<setw(2)<<setfill('0')<<h<<":"<< setw(2)<<setfill('0') <<m;
}
