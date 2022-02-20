#include <iostream>
//#include <fstream>
//#include <string>
#include <vector>
//#include <map>
//#include <set>
//#include <cmath>
//#include <algorithm>
using namespace std;

vector<int> helper;

vector<int> Merge(const vector<int>& a, const vector<int>& b) {
	helper.clear();
	int n = a.size();
	int m = b.size();
	int i = 0;
	int j = 0;
	while ((i < n) || (j < m)) {
		if ((j == m) || ((i < n) && (a[i] <= b[j]))) {
			helper.push_back(a[i]);
			++i;
		} else {
			helper.push_back(b[j]);
			++j;
		}
	}
	return helper;
}

void MergeSort(vector<int>& list) {
	int n = list.size();
	vector<vector<int>> sorter;
	helper.clear();
	for (int i = 0; i < n; ++i) {
		helper.push_back(list[i]);
		sorter.push_back(helper);
		helper.clear();
	}
	while (n > 1) {
		helper = Merge(sorter[0], sorter[1]);
		for (int i = 2; i < n; ++i) {
			sorter[i - 2] = sorter[i];
		}
		sorter[n - 2] = helper;
		sorter.pop_back();
		--n;
	}
	list = sorter[0];
}

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int& elem : v) {
		cin >> elem;
	}

	cout << n << endl;

	for (int& elem : v) {
		cout << elem << " ";
	}

	cout << endl;

	MergeSort(v);

	for (int& elem : v) {
		cout << elem << " ";
	}

	return 0;
}
