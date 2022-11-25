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
		int n, k;
		cin >> n >> k;
		vector<long long> a(n, -1e10);
		vector<long long> s(n);
		for (int i = n - k; i  < n; i++) {
			cin >> s[i];
		}
		for (int i = n - k + 1; i < n; i++) {
			a[i] = s[i] - s[i - 1];
		}
		a[n - k] = s[n - k] / (n - k + 1);
		if (s[n - k] > 0 && s[n - k] % (n - k + 1) != 0) a[n - k]++;
		bool b = true;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) b = false;
		}
		
		if (b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
