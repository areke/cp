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
		int n;
		cin >> n;
		vector<long long> a(n);
		long long g2 = 0;
		long long g1 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] < 0) g2 += a[i];
			else g1 += a[i];
		}
		cout << abs(g1 + g2) << endl;
		
	}
	return 0;
}
