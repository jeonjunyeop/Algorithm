//******Bubble Sort Review-Print every stage.******
//Enter Length of an array and each number
//and return the array per every stage.

#include <iostream>
using namespace std;

int main() {
	int i, j,k, n;
	cin >> n;
	int arr[100];
	for (i = 0; i < n; i++)
		cin >> arr[i];

	for (i = 1; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
		for (k = 0; k < n; ++k) {
			cout << arr[k] << " ";
		}cout << endl;
	}
	return 0;
}
