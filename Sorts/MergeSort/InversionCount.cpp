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

vector<long long> helper;

vector<long long> MergeCount(const vector<long long>& a, const vector<long long>& b) {
	helper.clear();
	long long count = 0;
	int n = a.size();
	int m = b.size();
	int i = 0;
	int j = 0;
	while ((i < n) || (j < m)) {
		if ((j == m) || ((i < n) && (a[i] <= b[j]))) {
			helper.push_back(a[i]);
			++i;
			count += j;
		} else {
			helper.push_back(b[j]);
			++j;
		}
	}
	helper.push_back(count);
	return helper;
}

vector<long long> MergeSortCount(vector<long long>& v) {
	int n = v.size() - 1;
	if (n == 1) {
		return v;
	}
	vector<long long> left, right;
	for (auto i = 0; i < n / 2; ++i) {
		left.push_back(v[i]);
	}
	for (auto i = n / 2; i < n; ++i) {
		right.push_back(v[i]);
	}
	left.push_back(0);
	right.push_back(0);
	left = MergeSortCount(left);
	right = MergeSortCount(right);

	long long count = left[left.size() - 1] + right[right.size() - 1];

	left.pop_back();
	right.pop_back();

	helper.clear();

	helper = MergeCount(left, right);
	helper[helper.size() - 1] += count;

	return helper;
}


int main() {
	ifstream input("input.txt");

	int n;
	input >> n;

	vector<long long> v(n + 1);

	for (auto i = 0; i < n; ++i) {
		input >> v[i];
	}

	v = MergeSortCount(v);

	ofstream output("output.txt");

	output << v[n] << endl;

	return 0;
}
