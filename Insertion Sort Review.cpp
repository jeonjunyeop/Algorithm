//*****Insertion Sort Review_2019/03/31****
//#include <iostream>
//using namespace std;
//int main() {
//	int i, j, n, k;
//	int arr[100];
//	cin >> n;
//	for (i = 0; i < n; i++)
//		cin >> arr[i];
//
//	for (i = 1; i < n; i++) {
//		for (j = i; j >= 0; j--) {			
//			if (arr[j] > arr[i]) {
//				arr[j + 1] = arr[j];
//			}
//			else {
//				arr[j] = arr[i];
//				continue;
//			}
//		}
//	}
//	
//	for (i = 0; i < n; i++)
//		cout << arr[i] << " ";
//	
//	return 0;
//}***wrong answer***

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int i, j, n;
//	int arr[100];
//	cin >> n;
//
//	for (i = 0; i < n; i++)
//		cin >> arr[i];
//
//	for (i = 1; i < n; i++) {
//
//		for (j = i - 1; j >= 0; j--) {
//			if(arr[j]>arr[i])
//				arr[j + 1] = arr[j];
//			else {
//				arr[j] = arr[i];
//				break;
//			}
//		}
//	}
//	for (i = 0; i < n; i++) {
//		cout << arr[i] << " ";
//	}
//
//
//	return 0;
//}***wrong answer***

//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int i, j, n, temp;
//	int arr[100];
//	cin >> n;
//	for (i = 0; i < n; i++)
//		cin >> arr[i];
//	for (i = 1; i < n; i++) {
//
//		for (j = i - 1; j >= 0; j--) {
//			if (arr[j] > arr[i]) {
//				arr[j + 1] = arr[j];
//			}
//			else {
//				
//				continue;
//			}
//		}arr[j + 1] = arr[i];
//	}
//	for (i = 0; i < n; i++)
//		cout << arr[i] << " ";
//
//	return 0;
//}***wrong answer***
//---------------------------------------
//#include <iostream>
//using namespace std;
//int main() {
//	int i, j, n, temp;
//	int arr[100];
//	cin >> n;
//	for (i = 0; i < n; i++)
//		cin >> arr[i];
//
//	for (i = 1; i < n; i++) {
//		temp = arr[i];
//		for (j = i - 1; j >= 0; j--) {
//			if (arr[j] > temp) {
//				arr[j + 1] = arr[j];
//			}
//			else
//				break;
//		}arr[j + 1] = temp;
//	}
//	
//	for (i = 0; i < n; i++) 
//		cout << arr[i] << " ";
//
//	return 0;
//}******OK******
#include <iostream>
using namespace std;
int main() {
	int i, j, n, temp;
	int arr[100];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	
	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0&&arr[j]>temp; j--) {
			arr[j + 1] = arr[j];
		}arr[j + 1] = temp;
	}

	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
}
