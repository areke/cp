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

long long solve(string & s) {
	long long res = 0;
	long long d = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') d++;
		else {
			d--;
			res += d;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long res = 0;
		int k;
		cin >> k;
		string s;
		cin >> s;
		int n = s.length();
		while (k--) {
			stack<int> st;
			stack<long long> cost;
			long long best = -1;
			pair<int, int> match;
			long long cur = 0;
			long long dep = 0;
			vector<int> matches(s.length());
			vector<string> v;
			for (int i = 0; i < n; i++) {
				if (s[i] == '(') {
					st.push(i);
					dep++;
				} else {
					dep--;
					int m = st.top();
					matches[m] = i;
					matches[i] = m;
					if (dep == 0) {
						v.push_back(s.substr(m, i - m + 1));
					}
					st.pop();
				}
			}
			vector<long long> c(v.size(), -1);
			int ind = 0;
			for (int i = 0; i < v.size(); i++) {
				c[i] = 0;
				if (v[i].length() > 2) {
					string t = v[i].substr(1, v[i].size() - 2);
					c[i] = solve(v[i]) - solve(t);
				}
				if (c[i] > c[ind]) {
					ind = i;
				}
			}
			s = "";
			for (int i = 0; i < v.size(); i++) {
				if (i == ind) {
					if (v[i].size() > 2) {
						s += "()" + v[i].substr(1, v[i].size() - 2);
					} else {
						s += v[i];
					}
				} else {
					s += v[i];
				}
			}


		}
		
		cout << solve(s) << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
