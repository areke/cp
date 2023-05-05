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
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<int> xx(k);
		vector<int> cc(k);
		for (int i = 0; i < k; i++) {
			cin >> xx[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> cc[i];
		}
		int cur = 0;
		int curc = 0;
		vector<pair<int, int> > v;
		for (int i = 0; i < k; i++) {
			v.push_back({xx[i] - cur, cc[i] - curc});
			cur = xx[i];
			curc = cc[i];
		}
		bool can = true;
		int bad = 0;
		int tot = 0;
		for (int i = 0; i < k; i++) {
			if (v[i].second > v[i].first) {
				can = false;
			}
			tot += v[i].first;
			bad += v[i].first - v[i].second;
			if (tot <= 3 && bad > 0) can = false;
		}
		if (!can) {
			cout << "NO" << "\n";
			continue;
		}
		
		string res = "";
		char ch = 'a';
		int bd = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < v[i].second; j++) {
				res += (ch + i);
				if (ch <= 'b') ch++;
			}
			int c = v[i].first - v[i].second;
			for (int j = 0; j < c; j++) {
				res += ('a' + (bd % 3)); 
				bd++;
			}
		}
		cout << "YES" << "\n";
		cout << res << "\n";
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
