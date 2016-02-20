#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    double d,L,v1,v2;
    cin>>d>>L>>v1>>v2;
    double res=(L-d)/(v1+v2);
    printf("%.9f\n",res);
}
