#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	cin >> n;

	vector<int> v(n);

	int i, j, temp;

	for (i = 0; i < n; i++) {
		cin >> v[i];
	}


	for (i = 0; i < n - 1; i++) {
		for (j = 1; j < n - i; j++) {
			if (v[j - 1] > v[j]) {
				/*temp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = temp;*/
				swap(v[j], v[j - 1]);
			}
			
		}
		for (j = 0; j < n; j++)
			cout << v[j] << ' ';
		
		cout << endl;
		
	}
	/*for (i = 0; i < n; i++)
		cout << v[i] << ' ';*/
	return 0;
	}
	
