#include<iostream>
#include<cstdio>
using namespace std;
bool a[2005][2005];
int main(){
    int n;
    cin>>n;
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x-1][y-1]=true;
    }
    long long res=0;
    for(int i=0;i<=2000;i++){
        int cnt=0;
        for(int j=0;j<=i;j++){
            if(a[j][i-j]) cnt++;
        }
        res+=cnt*(cnt-1)/2;
    }

    for(int i=0;i<1000;i++){
        int cnt=0;
        int j=i;
        int l=0;
        while(l<1005&&j<1005){
            if(a[l][j]) cnt++;
            l++;
            j++;
        }
         res+=cnt*(cnt-1)/2;
    }
    for(int i=1;i<1000;i++){
        int cnt=0;
        int j=i;
        int l=0;
        while(l<1005&&j<1005){
            if(a[j][l]) cnt++;
            l++;
            j++;
        }
         res+=cnt*(cnt-1)/2;
    }
    cout<<res<<endl;
}
