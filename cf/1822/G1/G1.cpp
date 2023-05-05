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
#include<unordered_map>
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
		unordered_map<long long, long long> l;
		unordered_map<long long, long long> r;
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			r[a[i]]++;
		}
		sort(a.begin(), a.end());
		long long res = 0;
		for (int i = 0; i < n; i++) {
			r[a[i]]--;
			
			for (long long j = 2; j <= 1000; j++) {
				if (a[i] % j == 0) {
					res += l[a[i] / j] * r[a[i] * j];
				}
			}
			res += l[a[i]] * r[a[i]] * 6;
			l[a[i]]++;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
