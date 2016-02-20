#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main(){
    set<int> nums;
    int n;
    cin>>n;
    while(n--){
        int tmp;
        cin>>tmp;
        while(nums.find(tmp)!=nums.end()&&tmp>=1){
            tmp--;
        }
        if(tmp)
            nums.insert(tmp);
    }
    long long res=0;
    for(set<int>::iterator it=nums.begin();it!=nums.end();it++){
        res+=*it;
    }
    cout<<res<<endl;
}
