//Oranges are stored in gridboxes.
//There could be rotted oranges and normal oranges. And rotted oranges affect to close oranges.(up,down,right,left)(not affect to diagonal)
//How long does it take for all the orranges to rot? (a few boxes have no oranges.)
//Input: m:width n:height
//       information of oranges. 
//1:rotted orange, 0:normal one, -1:empty

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue <pair<int, int>>q;
int m, n, map[1000][1000] = { 0, }, value[1000][1000] = { 0, }; //m:width, n:height, map:visiting info, value: aging days
int x_pos[4] = { 0,1,0,-1 };
int y_pos[4] = { 1,0,-1,0 };//up,right,down,left

int isRange(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n)
		return -1;//
	return 1;
}
int bfs(vector <pair<int, int>>p) {
	int max=0;

	
	for (int i = 0; i < p.size(); i++) {//initialization
		int x = p[i].first;
		int y = p[i].second;
		map[y][x] = -1;
		value[y][x] = 0;
		
		q.push(p[i]);
	}
	while (!q.empty()) {
		pair<int, int>tmp = q.front();
		q.pop();
		int x = tmp.first;
		int y = tmp.second;

		for (int i = 0; i < 4; i++) {
			int x_search = x + x_pos[i];
			int y_search = y + y_pos[i];
			if (isRange(x_search, y_search) == 1 && map[y_search][x_search] == 0) {

				pair<int, int>pt = make_pair(x_search, y_search);
				q.push(pt);
				map[y_search][x_search] = -1;
				value[y_search][x_search] = value[y][x] + 1;
			
				if (max < value[y_search][x_search]) {
					max = value[y_search][x_search];
				}
			}
		}
	}
	return max;
}
int main() {
	cin >> m >> n;
	vector <pair<int, int>>p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 1) {
				pair<int, int>t = make_pair(j, i);
				p.push_back(t);
			}
		}
	}
	int result = bfs(p);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << result;
	return 0;
}
