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
#include <unordered_map>
using namespace std;
 
vector<long long> a(200000);
vector<long long> p(200000);
vector<long long> m(400001, 0);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;

		
		cin >> n;
		m.assign(2 * n + 1, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long res = n * (n + 1) / 2;
		p[0] = 0;
		for (int i = 0; i < n; i++) {
			p[i + 1] = a[i] ^ p[i];
		}
		long long bad = 0;
		long long t;
		for (int j = 0; j < n + 1; j++) {
			for (long long i = 0; i <= sqrt(4*n) + 1; i++) {
				t = i * i;
				t ^= p[j];
				if (t < m.size()) {
					bad += m[t];
				}
			}
			//cout << n << " " << p[j] << endl;
			m[p[j]]++;
		}
		cout << res - bad << endl;
 
	}
 
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}