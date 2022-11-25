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
		long long n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long b = a[0];
		long long mini = 1e10;
		for (int i = 1; i < n; i++) {
			mini = min(mini, a[i]);
		}
		if (b <= mini) {
			cout << "Bob" << endl;
		} else {
			cout << "Alice" << endl;
		}
	}
	return 0;
}
