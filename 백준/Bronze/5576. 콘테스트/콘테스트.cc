#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    
    
    vector<int>v(10);
    vector<int>c(10);
 
    for(int i=0; i<10; i++){
 
        cin>>v[i];
    }
 
    for(int i=0; i<10; i++){
        cin>>c[i];
    }
 
    sort(v.begin(), v.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    
    cout<<v[0]+v[1]+v[2]<<"\n";
    cout<<c[0]+c[1]+c[2]<<"\n";






 
    return 0;
}
