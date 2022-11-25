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
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		priority_queue<long long> pq;
		long long mini = a[0];
		long long res = 0;
		for (int i = 0; i < n; i++) {
			pq.push(a[i]);
		}
		while (!pq.empty()) {
			long long x = pq.top();
			if (pq.top() >= 2 * mini) {
				int slices = x / (2 * mini - 1);
				slices--;
				if (x % (2 * mini - 1) != 0) slices++;
				res += slices;
			}
			pq.pop();
		}
		
		cout << res << endl;
	}
	return 0;
}
