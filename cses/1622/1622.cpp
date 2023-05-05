#include <iostream>
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
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	string s;
	cin >> s;
	vector<int> v(s.size());
	set<string> res;
	for (int i = 0; i < s.size(); i++) v[i] = i;
	do {
		string t = "";
		for (int j =0; j < s.size(); j++) {
			t += s[v[j]];
		}
		res.insert(t);
	} while (next_permutation(v.begin(), v.end()));
	cout << res.size() << endl;
	for (string x : res) {
		cout << x << endl;
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
