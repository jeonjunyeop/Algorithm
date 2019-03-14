/* Count the number of movement in Insetion sort*/

/*Input type : The number of sequence 'n' would be enntered in first line.
				n integers would be entered which are over -1000 and under 1000.*/
/*Output type: Print the number of movement with entered integers when it comes to Insertion sort .*/

#include <iostream>
using namespace std;

int main() {
	int i, j, temp, n;
	int count=0;

	int arr[100];

	cin >> n;

	for (i = 0; i < n; i++)
		cin >> arr[i];

	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
			count++;
		}
		arr[j + 1] = temp;
	}
	cout << count;

	return 0;

}

/*for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
			count++;
		}
		arr[j + 1] = temp;
	}
	
=============================================both are same.

	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];
				count++;
			}else break;	
		}
		arr[j + 1] = temp;
	}*/
