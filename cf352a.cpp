#include<string>
#include<iostream>
#include<sstream>
using namespace std;
template <typename T>
string ToString(T val)
{
    stringstream stream;
    stream << val;
    return stream.str();
}
int main(){

    string s=string("");
    for(int i=1;i<500;i++){

        s+=ToString(i);
    }
    int n;
    cin>>n;
    cout<<s[n-1]<<endl;
}

