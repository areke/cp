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

string bin(int n, int d) {
	string s = "";
	for (int i = d - 1; i >= 0; i--) {
		s += ('0' + (((1 << i) & n) >> i));
	}
	return s;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<int> res = {0, 1};
	for (int cnt = 1; cnt < n; cnt++) {
		int x = res.size();
		for (int i = x - 1; i >= 0; i--) {
			res.push_back(res[i]);
		}
		for (int i = 0; i < x; i++) {
			res[i] += (1 << cnt);
		}


	}
	for (int i = 0; i < res.size(); i++) {
		cout << bin(res[i], n) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
