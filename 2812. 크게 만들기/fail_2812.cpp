#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace::std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int k;
	string num;

	int currentIndex; // 스트링에서 현재 위치를 저장하고 있는 Index
	stack<int> stk; // k개를 지우고 남아있는 숫자 값을 저장할 스택
	int limitIndex;

	cin >> n >> k >> num;
	limitIndex = k + 1;
	currentIndex = 0;

	while (currentIndex < n) { // O(n^2)의 시간복잡도로 인한 시간초과로 fail
		if (currentIndex == limitIndex) {
			stk.push(stk.top() + 1);
			limitIndex++;
			currentIndex = stk.top() + 1;
		}
		else if (currentIndex < limitIndex) {
		
			if (!stk.empty()) {
				if (stoi(string(1, num[stk.top()])) < stoi(string(1, num[currentIndex]))) {
					stk.pop();
					stk.push(currentIndex);
				}
			}
			else {
				stk.push(currentIndex);
			}
			currentIndex++;
		}
	}
	
	int* result = new int[stk.size() + 1];
	int size = stk.size();

	for (int i = size - 1; i > -1; --i) {
		result[i] = stoi(string(1, num[stk.top()]));
		stk.pop();
	}
	for (int i = 0; i < size; i++) {
		cout << result[i];
	}
	cout << "\n";
}
