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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int res = 0;
		for (int k = n; k >= 1; k--) {
			bool b = true;
			int bp = 0;
			int ap = n - 1;
			for (int j = 0; j < k; j++) {
				bool bb = false;
				while (!bb && ap >= bp) {
					if (a[ap] <= k - j) {
						bb = true;
						bp++;
					}
					ap--;
				}
				if (!bb) b = false;
			}
			if (b) {
				res = k;
				break;
			}
		}
		cout <<res << endl;
	}
	return 0;
}
