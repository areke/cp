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
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, k;
		cin >> n >> k;
		if (k % 4 == 0) {
			cout << "NO" << endl;
			continue;
		}
		vector<long long> g;
		vector<long long> b;
		for (int i = 1; i <= (n / 4) * 4; i++) {
			if ((i + k) % 4 == 0 || i % 4 == 0) {
				g.push_back(i);
			} else {
				b.push_back(i);
			}
		}
		if (n % 4 == 2) {
			if (k % 2 == 1) {
				g.push_back(n - 1);
				b.push_back(n);
			} else {
				g.push_back(n);
				b.push_back(n - 1);
			}
		}
		cout << "YES" << endl;
		for (int i = 0; i < g.size(); i++) {
			if (g[i] % 4 == 0) {
				swap(g[i], b[i]);
			}
			cout << g[i] << " " << b[i] << endl;
		}
	}
	return 0;
}
