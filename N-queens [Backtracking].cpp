#include <iostream>

using namespace std;

int n, result;

int a[3][25];

void solution(int i) {
	if (i == n) {
		result++;
		
	}
	for (int j = 0; j < n; j++) {

		if (a[0][j] || a[1][i + j] || a[2][n - 1 + i - j]) 
			continue;
		
		a[0][j] = a[1][i + j] = a[2][n - 1 + i - j] = 1;
		solution(i + 1);
		a[0][j] = a[1][i + j] = a[2][n - 1 + i - j] = 0;

	}

}

int main() {

	cin >> n;
	solution(0);
	cout << result;

	return 0;
}