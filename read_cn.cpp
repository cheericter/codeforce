#include<locale>
#include<iostream>
#include<string>

using namespace std;

int main(){
    locale china("chs");
    wcin.imbue(china);
    wcout.imbue(china);
    wstring s;
    wchar_t wc=L'¡£';
    while(getline(wcin,s,wc)){
        wcout<<s<<endl;
    }


}
