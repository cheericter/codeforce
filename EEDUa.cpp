#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    double rate = 1.000000011 ;
    int n,t;
    cin>>n>>t;
    cout<<(double)n*pow(rate,t)<<endl;
}
