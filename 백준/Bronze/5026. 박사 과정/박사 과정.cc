#include <iostream>
#include <string>
#include <stdlib.h>
 
using namespace std;
 
int main() {
 
    int test;
    cin>>test;
 
    for(int i=0; i<test; i++){
 
        string str;
        cin>>str;
 
        int a,b;
 
        if(str=="P=NP"){
            cout<<"skipped"<<"\n";
        }
 
        else{
            int sever=str.find('+');
            a=stoi(str.substr(0,sever)); 
            b=stoi(str.substr(sever+1));

            cout<<a+b<<"\n";
        }
        
    }
}
