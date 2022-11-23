#include <bits/stdc++.h>
using namespace std;

void replace(string s){

    //base case
    if(s.length()==0){
        return ;
    }

    //rec case
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replace(s.substr(2));
    }
    else{
        cout<<s[0];
        replace(s.substr(1));
    }


}
int main()
{

    replace("pidsdfirfgpiafgpasfgadfgjsdfpifg");

    return 0;
}