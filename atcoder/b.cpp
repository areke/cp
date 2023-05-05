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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (s.find(i + 1) == s.end()) {
			s.insert(a);
		}
	}
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (s.find(i) == s.end()) {
			res.push_back(i);
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i == res.size() - 1) cout << endl;
		else cout << " ";
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
