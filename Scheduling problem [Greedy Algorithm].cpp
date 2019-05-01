#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct st {
	int number;
	int start_time;
	int finish_time;
};

st arr[500];

bool compare(st a, st b) {
	return a.finish_time < b.finish_time;
}


int main() {
	int n;
	int count = 1;
	
	vector<int> vec;

	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> arr[i].number >> arr[i].start_time >> arr[i].finish_time;
	

	sort(arr, arr + n, compare);

	int flag = arr[0].finish_time;
	vec.push_back(arr[0].number);
	for (int i = 1; i < n; i++) {
		if (flag <= arr[i].start_time) {
			count++;
			flag = arr[i].finish_time;
			vec.push_back(arr[i].number);
		}
	}

	cout << count << endl;
	for (int j = 0; j < vec.size(); j++)
		cout << vec[j]<<" ";

	return 0;
}