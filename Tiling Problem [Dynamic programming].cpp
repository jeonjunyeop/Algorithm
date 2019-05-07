//Question : In how many ways can you tile a 2xn rectangle by 2x1 or 2x2 tiles ?

//Input : Input is a sequence of a line, the line containing an integer number 0 <= n <= 100000.

//Output : Output one integer number giving the number of possible tilings of a 2xn rectangle.
// *Because the answer can be large, the answer is divided by 20100529

#include <iostream>

using namespace std;

int num[100001];

int tiling(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (num[n] != 0) return num[n];
	return num[n] = (tiling(n - 1) + 2 * tiling(n - 2)) % 20100529;

}
int main() {
	int n;
	cin >> n;
	cout << tiling(n);

	return 0;
}