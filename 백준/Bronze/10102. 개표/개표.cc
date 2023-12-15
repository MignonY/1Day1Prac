#include <iostream>
#include <string>
using namespace std;

int v,a,b;
string k;

int main(){
    cin >> v >> k;
    for (int i = 0; i < v; i++){
        if (k[i] == 'A') a++;
        else b++;
    }
    if (a == b){
        cout << "Tie" << '\n';
    }
    else{
        printf("%c\n", a < b ? 'B' : 'A');
    }
    return 0;
}
