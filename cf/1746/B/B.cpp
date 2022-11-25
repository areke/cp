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
		vector<int> z;
		int res = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 0) z.push_back(i);
		}
		int cur = z.size() - 1;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1 && cur >= 0) {
				if (i < z[cur]) {
					res++;
					cur--;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
