#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*int main(){
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++){
        int ele=1;
        while(!s.empty()&&s.top()==ele){
            int tmp=s.top();s.pop();
            ele=ele+1;
        }
        s.push(ele);
    }
    stack<int> o;
    while(!s.empty()){
        o.push(s.top());
        s.pop();
    }
    cout<<o.top();o.pop();
    while(!o.empty()){
        cout<<" "<<o.top();o.pop();
    }
    cout<<endl;
}*/
int main(){
    int n;
    cin>>n;
    vector<int> s;
    for(int i=0;i<n;i++){
        int ele=1;
        while(!s.empty()&&s.back()==ele){
            s.pop_back();
            ele=ele+1;
        }
        s.push_back(ele);
    }
    for(int i=0;i<s.size();i++){
        cout<<s[i];
        if(i<s.size()-1) cout<<" ";
        else cout<<endl;
    }

}
