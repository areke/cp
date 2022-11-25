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
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector<string> v;
		string cur = "";
		char last = a[0];
		for (int i = 0; i < n; i++) {
			if (a[i] != last) {
				v.push_back(cur);
				cur = "";
			}
			cur += a[i];
			last = a[i];
		}
		if (cur != "") {
			v.push_back(cur);
		}
		vector<pair<int, int> > res;
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i][0] == '1') {
				res.push_back({cnt, cnt + v[i].size() - 1});
			}
			cnt += v[i].length();
		}
		vector<bool> in(n, false);
		for (int i = 0; i < res.size(); i++) {
			for (int j = res[i].first; j <= res[i].second; j++) {
				in[j] = true;
			}
		}
		for (int i = 0; i < n; i++) {
			bool flipped = res.size() % 2;
			if (flipped ^ in[i]) {
				if (b[i] == '1') b[i] = '0';
				else b[i] = '1';
			}
		}
		char first = b[0];
		bool can = true;
		for (int i = 0; i < n; i++) {
			if (b[i] != first) {
				can = false;
			}
		}
		if (can) {
			cout << "YES" << endl;
			if (first == '1') {
				res.push_back(make_pair(0, 0));
				res.push_back(make_pair(1, n - 1));
				res.push_back(make_pair(0, n - 1));
			}
			cout << res.size() << endl;
			for (int i = 0; i < res.size(); i++) {
				cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
			}
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
