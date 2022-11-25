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
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		map<int, int> m;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				res++;
			}
			m[a[i]]++;
			m[b[i]]--;
		}
		cout << min(res, abs(m[0]) + 1) << endl;
	}
	return 0;
}
