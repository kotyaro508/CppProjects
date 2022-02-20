#include <iostream>
#include <fstream>
//#include <string>
#include <vector>
//#include <map>
//#include <set>
//#include <cmath>
//#include <algorithm>
//#include <limits>
using namespace std;

ofstream output("output.txt");

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

void MergeSort(vector<int>& v, const int& l, const int& r) {
	int n = r - l + 1;
	int l_l = l;
	int l_r = l + (n + 1) / 2 - 1;
	int r_l = l + (n + 1) / 2;
	int r_r = r;
	if (l_r > l_l) {
		MergeSort(v, l_l, l_r);
	}
	if (r_r > r_l) {
		MergeSort(v, r_l, r_r);
	}
	vector<int> left, right;
	for (int i = l_l; i <= l_r; ++i) {
		left.push_back(v[i]);
	}
	for (int i = r_l; i <= r_r; ++i) {
		right.push_back(v[i]);
	}
	helper = Merge(left, right);
	for (int i = l; i <= r; ++i) {
		v[i] = helper[i - l];
	}
	output << "Left = " << l + 1 << "  Right = " << r + 1 << "  Min = " << v[l] << "  Max = " << v[r] << endl;
}

int main() {
	ifstream input("input.txt");

	int n;
	input >> n;
	vector<int> list(n);

	for (int i = 0; i < n; ++i) {
		input >> list[i];
	}

	MergeSort(list, 0, n - 1);

	output << "Sorted list: ";

	for (int i = 0; i < n; ++i) {
		output << list[i] << " ";
	}
	output << endl;

	return 0;
}

