#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

int i, j, k, n, c;

void selection_sort(int data[], int n);

int main() {
	
	int data[MAX];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> data[i];

	selection_sort(data, n);

	return 0;
}

void selection_sort(int data[], int n) {
	for (i = 0; i < n-1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (data[j] < data[k])
				k = j;			
		}swap(data[i], data[k]);
		
		for (c = 0; c < n; c++)
			cout << data[c] << ' ';
		cout << endl;
	}
}