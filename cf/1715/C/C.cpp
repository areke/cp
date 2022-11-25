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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m;
	cin >> n>> m;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> v(n + 1, 0);
	v[0] = 0;
	v[1] = 1;
	for (int i = 1; i < n; i++) {
		v[i + 1] = v[i];
		if (a[i] != a[i - 1]) {
			v[i + 1]++;
		}
	}
	long long res = 0;
	for (long long i = 1; i <= n; i++) {
		res += i * v[i];
		res -= (n - i + 1) * v[i];
		res += i;
	}
	for (int i = 0; i < m; i++) {
		//cout << i << " " << m << endl;
		long long ind, x;
		cin >> ind >> x;
		ind--;
		if (a[ind] == x) {
			cout << res << endl;
			continue;
		}
		if (ind > 0) {
			long long segs = ind * (n - ind);
			if (a[ind - 1] != x && a[ind - 1] == a[ind]) {
				res += segs;
			} else if (a[ind - 1] == x && a[ind - 1] != a[ind]) {
				res -= segs;
			}
		}
		if (ind < n - 1) {
			long long segs = (ind + 1) * (n - ind - 1);
			if (a[ind + 1] != x && a[ind + 1] == a[ind]) {
				res += segs;
			} else if (a[ind + 1] == x && a[ind + 1] != a[ind]) {
				res -= segs;
			}
		}
		a[ind] = x;
		cout << res << endl;
	}
}
