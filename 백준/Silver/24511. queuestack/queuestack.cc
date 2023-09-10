#include <iostream>
#include <deque>
using namespace std;

deque<int> q;
bool arr[100000];
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	int N; 
    cin >> N;
	for (int i = 0; i < N; i++){
        cin >> arr[i];
    } 
	for (int i = 0; i < N; i++) {
		int x; 
        cin >> x;
		if (arr[i]) continue;
		q.push_back(x);
	}
    
	int M; 
    cin >> M;
	while (M--) {
		int x; 
        cin >> x;
		q.push_front(x);
		cout << q.back() << ' ';
		q.pop_back();
	}
}