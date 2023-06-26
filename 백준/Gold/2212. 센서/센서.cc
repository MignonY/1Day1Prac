#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N,&K);
    
    vector<int> positions(N, 0);
    for (int i = 0; N > i; i++)
    {
        scanf("%d", &positions[i]);
    }
    sort(positions.begin(), positions.end());
    
    vector<int> distances; //센서 간 거리를 저장할 벡터
    for (int i = 1; positions.size() > i; i++)
    {
        int dist = positions[i] - positions[i-1];
        distances.emplace_back(dist); //앞뒤 센서간 거리 구하기
    }
    
    //센서간 거리 오름차순 정렬
    sort(distances.begin(), distances.end());
    
    int count = N - K; //최소 거리 개수
    int answer = 0;
    for (int i = 0; count > i; i++)
    {
        answer += distances[i];
    }
    
    printf("%d\n",answer);
    
    return 0;
}