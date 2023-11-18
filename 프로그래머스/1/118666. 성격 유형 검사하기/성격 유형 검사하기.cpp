#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
 
int Ssize;
int score[30];
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    Ssize = survey.size();
    
    for(int i=0; i<Ssize; ++i){
        int num = choices[i];
        char first = survey[i][0];
        char second = survey[i][1];
        if(num <=3){
            score[first-'A'] += 4-num; 
        }
        else if(num>=5){
            score[second-'A'] += num-4;
        } 
    }
    
    if(score['R'-'A'] >= score['T'-'A']){
        answer += 'R';
    }
    else answer += 'T';
    
    if(score['C'-'A'] >= score['F'-'A']){
        answer += 'C';
    }
    else answer += 'F';
    
    if(score['J'-'A'] >= score['M'-'A']){
        answer += 'J';
    }
    else answer += 'M';
    
    if(score['A'-'A'] >= score['N'-'A']){
        answer += 'A';
    }
    else answer += 'N';

    
    
    return answer;
}