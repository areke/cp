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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <array>
#include <cstring>
using namespace std;

long double EPS = 1e-3;

int main() {
	int n;
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		cin >> n;
		cout << "? 0 1 0" << endl;
		cout.flush();

		vector<long double> x(n);
		vector<long double> y(n);
		for (int i = 0; i < n; i++) {
			long double a, b;
			cin >> a >> b;
			x[i] = a;
		}
		cout << "? 1 0 0" << endl;
		cout.flush();

		for (int i = 0; i < n; i++) {
			long double a, b;
			cin >> a >> b;
			y[i] = b;
		}
		vector<pair<long double, long double> > c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				c.push_back({x[i], y[j]});
			}
		}
		vector<long double> v;
		for (int i = 0; i < c.size(); i++) {
			for (int j = i + 1; j < c.size(); j++) {
				long double dy = c[i].second - c[j].second;
				long double dx = c[i].first - c[j].first;
				if (dx != 0) {
					v.push_back((dy / dx));
				}
			}
		}
		sort(v.begin(), v.end());
		long double m = -1.0 / (v[v.size() - 1] + 1);
		//a = (x + ym) / (m^2 + 1)
		int ind = 0;
		cout << "? " << -m << " 1 0" << endl;
		cout.flush();

		vector<pair<long double, long double> > real(n);
		for (int i = 0; i < n; i++) {
			cin >> real[i].first >> real[i].second;
		}

		// a = (x + ym) / (m^2 + 1)
		// point is (a, ma)
		vector<pair<long double, long double> > res;
		for (int i = 0; i < c.size(); i++) {
			long double x = (c[i].first + c[i].second * m) / (m * m + 1);
			long double y = m * x;
			for (int j = 0; j < n; j++) {
				if (abs(x - real[j].first) <= EPS && abs(y - real[j].second) <= EPS) {
					res.push_back({c[i].first, c[i].second});
					break;
				}
			}
		}

		cout << "! ";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].first << " " << res[i].second;
			if (i == res.size() - 1) cout << endl;
			else cout << " ";
		}
		cout.flush();
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
