#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    char s[209];
    cin>>n;
    getchar();
    scanf("%s",s);
    map<char,int> c2n;
    for(int i=0;i<n;i++){
        c2n[s[i]]++;
    }

    if(c2n.size()==1){
         for (std::map<char,int>::iterator it=c2n.begin(); it!=c2n.end(); ++it)
            cout << it->first << '\n';
    }else if(c2n.size()==3){
        cout<<"BGR"<<endl;
    }else if (c2n.size()==2){
        set<char>  out;
        char c[3]={'R','G','B'};
        char miss;
        for(int i=0;i<3;i++){
            if(c2n.count(c[i])==0){
                miss = c[i];
                out.insert(miss);
            }
            else{
                if(c2n[c[i]]>1){
                    for(int j=0;j<3;j++){
                        if(c[j]!=miss && c[j] !=c[i] ){
                            out.insert(c[j]);
                        }
                    }
                }
            }
        }
        std::vector<char> output(out.size());
        std::copy(out.begin(), out.end(), output.begin());
        sort (output.begin(), output.end());
        for (vector<char>::iterator it1 = output.begin(); it1 != output.end(); ++it1)
        {
            cout << *it1;
        }
        cout<<endl;

    }
}
