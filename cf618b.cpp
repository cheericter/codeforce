#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int maxval=-1;
    for(int i=0;i<n;i++){
        int sup=-1;
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            if(sup<tmp) sup=tmp;
        }
        if(maxval<sup) maxval=sup;
        nums[i]=sup;
    }
    int index=0;
    for(int i=0;i<n;i++){
        if(nums[i]==maxval){
            nums[i]+=index++;
        }
        if(i!=n-1)
            cout<<nums[i]<<" ";
        else cout<<nums[i]<<endl;
    }

}
