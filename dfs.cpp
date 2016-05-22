#include<iostream>
#include<fstream>
using namespace std;
int a[1000][1000];
int maxs;
int mx=-1;
int m,n;
int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
//走到想x,y去,step到xy的步数，已经获得的分数
int dfs(int x,int y,int score,int step){

    if(a[x][y]==2)
        score+=1;  //candy plus one
    cout<<x<<"\t"<<y<<"\t"<<score<<endl;
    if(step==maxs){
        if(mx<score)
            mx=score;
        return score;
    }
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx>=0&&xx<m&&yy>=0&&yy<n&&a[xx][yy]>0){
            dfs(xx,yy,score,step+1);
        }
    }
}
int main(){
    freopen("in.txt", "r",stdin);
    while(cin>>m>>n){
        mx=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        int x,y;
        cin>>x>>y>>maxs;
        x-=1;
        y-=1;
        if(a[x][y]==2){
            dfs(x,y,1,0);
        }else{
            dfs(x,y,0,0);
        }
        if(mx==-1)
            cout<<"0"<<endl;
        else
            cout<<mx<<endl;
    }
}
