#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  long long N;
  cin>>N;
  string result="";
  long long cnt =0;
  while(N>0){
      result += to_string((N%2));
      //cout<<result;
      N/=2;
  }
  reverse(result.begin(),result.end());
  cout<<result;
}