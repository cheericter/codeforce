#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int a[300009];
int b[300009][2];
int main(){
    int n;
    set<int> nums;
    int index=0;
    while(scanf("%d",&n)!=EOF){
        nums.clear();
        index=0;

        b[0][0]=0;
        for(int i=0;i<n;i++){
             scanf("%d",&a[i]);
            if(nums.find(a[i])==nums.end()){
                 nums.insert(a[i]);
                 //b[index][1]=i;
            }
            else{
                b[index][1]=i;
                b[++index][0]=i+1;
                nums.clear();
            }
        }
        if(index==0){
            printf("-1\n");
        }
        else{
            printf("%d\n",index);
            b[index-1][1]=n-1;
            for(int i=0;i<index;i++)
                printf("%d %d\n",b[i][0]+1,b[i][1]+1);
        }
    }
}
