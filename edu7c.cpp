#include<iostream>
using namespace std;
#define MAX_INT 100000000
const int MAX_N = 1<<17;
int n,dat[2*MAX_N-1];
void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++) dat[i]=MAX_INT;
}


void update(int k, int a){
    k+=n-1;
    dat[k] = a;
    while(k > 0){
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1],dat[k*2+ 2]);
    }
}
//get minmal value in array range [ab)
//k is node number
//l,r 对应节点的区间
//used as: query(a,b,0,0,n)
int query(int a, int b, int k, int l, int r){
    if(r<=a || l>=b){
        return MAX_INT;
    }
    if (a<=l && r<=b){
        return dat[k];
    }
    else{
        if (k<0) return -1;
        int v1 = query(a, b, 2*k+1, l, (l+r)/2);
        int v2 = query(a, b, 2*k+2, (l+r)/2, r);
        return min(v1, v2);
    }
}
int main(){
    init(4);
    update(1,2);
    update(2,1);
    update(0,12);
    int res=query(0,4,0,0,n);
    cout<<res<<endl;
}
