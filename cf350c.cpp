#include<set>
#include<map>
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    map<int,int> l2n;
    int n;
    cin>>n;
    int maxf=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        l2n[temp]++;
        if(l2n[temp]>maxf){
            maxf=l2n[temp];
        }
    }
    int m;
    cin>>m;
    int b[200005],c[200005];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    int res=0;
    int tempa=l2n[b[0]],tempb=l2n[c[0]];
    for(int i=1;i<m;i++){
        if(l2n[b[i]]>tempa){
            res=i;
            tempa=l2n[b[i]];
            tempb=l2n[c[i]];
        }
        else if(l2n[b[i]]==tempa &&l2n[c[i]]>tempb){
            tempb=l2n[c[i]];
            res=i;
        }
    }
    cout<<(res+1)<<endl;
}
