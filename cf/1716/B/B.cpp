#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

void print(vector<int> & v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i == v.size() - 1) cout << endl;
		else cout << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		cout << n << endl;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			v[i] = i + 1;
		}
		print(v);
		swap(v[0], v[n - 1]);
		print(v);
		for (int i = 1; i < n - 1; i++) {
			swap(v[i], v[i - 1]);
			print(v);
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
