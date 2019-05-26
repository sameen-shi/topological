#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool yes(vector<int>v, int i) {
	for (int x = 0; x < v.size(); x++) {
		if (i == v[x]) {
			return true;
		}
	}
	return false;
}
int main() {
	int m, n;
	bool are = false;
	int x, y;
	cin >> m >> n;
	int flag = 1;
	int flag1 = 1;
	int sum = 1;
	int record;
	int* entry = new int[m];
	int* exit = new int[m];
	int* result = new int[m];
	int a[50][50];
	bool is[50];
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		entry[i] = 0;
		exit[i] = 0;
		result[i] = 0;
		is[i] = true;

	}
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		exit[x - 1] = exit[x - 1] + 1;
		entry[y - 1] = entry[y - 1] + 1;
		a[x - 1][y - 1] = 1;
	}
	queue<int>q1;
	for (int i = 0; i < m; i++) {
		if (entry[i] == 0) {
			q1.push(i);
			is[i] = false;
			entry[i] = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		if (q1.empty()) {
			flag = 0;
			record = i;
			break;
		}
		else {
			result[i] = q1.front() + 1;
			q1.pop();
			for (int j = 0; j < m; j++) {
				if (a[result[i] - 1][j] == 1) {
					entry[j] = entry[j] - 1;
				}
			}
			for (int j = 0; j < m; j++) {
				if (entry[j] == 0) {
					is[j] = false;
					q1.push(j);
					entry[j] = 1;
				}
			}
		}
	}
	if (flag == 1) {
		cout << "YES" << endl;
		for (int i = 0; i < m - 1; i++) {
			cout << result[i] << ",";
		}
		cout << result[m - 1];
	}
	if (flag == 0) {
		cout << "NO" << endl;
		while (sum != 0) {
			sum = 0;
			for (int i = 0; i < m; i++) {
				if (exit[i] == 0) {
					is[i] = false;
					sum++;
					exit[i] = 1;
					for (int j = 0; j < m; j++) {
						if (a[j][i] == 1) {
							exit[j] = exit[j] - 1;
						}
					}
				}
			}
		}
		vector<int>v1;
		for (int i = 0; i < m; i++) {
			if (is[i]) {
				v1.push_back(i);
				record = i;
				break;
			}
		}
		while (1) {
			for (int i = 0; i < m; i++) {
				if (a[record][i] == 1 && is[i] && !yes(v1, i)) {
					v1.push_back(i);
					record = i;
					break;
				}
				if (a[record][i] == 1 && is[i] && yes(v1, i)) {

					record = i;
					flag1 = 0;
					break;
				}
			}
			if (flag1 == 0) {
				break;
			}
		}
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] == record || are) {
				cout << v1[i] + 1 << ",";
				are = true;
			}
		}
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] == record) {
				cout << v1[i] + 1;

			}
		}
	}
	delete[] entry;
	delete[] exit;
}



