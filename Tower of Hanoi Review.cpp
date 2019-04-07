#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, int c) {
	if (n <= 1) {
		printf("%d : %d -> %d\n", n, a, c);
	}
	else {
		hanoi(n - 1, a, c, b);
		printf("%d : %d -> %d\n", n, a, c);
		hanoi(n - 1, b, a, c);
	}
}
int main() {
	int n, a, b, c;

	cin >> n;

	hanoi(n, 1, 2, 3);

	return 0;
}