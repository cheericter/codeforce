/**
trie
**/
#include<iostream>
using namespace std;
#define ALPHABET_SIZE 20000
struct node
{
    bool is_end;
    int prefix_count;
    struct node *child[ALPHABET_SIZE];
}*head;

void init(){
    head = new node();
    head->prefix_count = 0;
    head->is_end = false;
}

void insert(string word){
    node *cur = head;
    cur->prefix_count++;
    for(int i=0;i<word.length();++i){
        int letter = (int)word[i]-(int)'a';
        cout<<word[i]<<" "<<(int)word[i]<<endl;
        if(cur->child[letter] == NULL){
            cur->child[letter] = new node();
        }
        cur->child[letter]->prefix_count++;
        cur=cur->child[letter];

    }
    cur->is_end=true;
}

bool search(string word){
    node *cur = head;
    for (int i=0;i<word.length();i++){
        if(cur->child[(int)word[i]-(int)'a']==NULL)
            return false;
        cur = cur->child[(int)word[i]-(int)'a'];
    }
    return cur->is_end;
}

int word_with_prefix(string prefix){
    node *cur = head;
    for (int i=0;i<prefix.length();i++){
        if(cur->child[(int)prefix[i]-(int)'a']==NULL){
            return 0;
        }else{
            cur = cur->child[(int)prefix[i]-(int)'a'];
        }
    }
    return cur->prefix_count;
}
int main(){
    init();

    insert("hello");
    insert("hello kity");
    insert("hello");
    cout<<search("hello")<<endl;
    cout<<word_with_prefix("hello")<<endl;
}
