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
		vector<long long> v(n);
		long long res = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long best = 0;
		long long bestl = 0;
		long long bestr = 0;
		for (int i = 0; i < n; i++) {
			int low = 0;
			int high = n - 1;
			long long lasts = -1;
			long long dir = 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				long long s = 0;
				long long x = 0;
				for (int j = 0; j <= mid; j++) {
					s += v[j];
					x ^= v[j]; 
				}
				long long left = s - x;
				if (left > best || (left == best && mid - i <= bestr - bestl)) {
					bestl = i;
					bestr = mid;
					best = left;
				}
				if (left > lasts) {
					if (dir == 1) {
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				} else {
					if (dir == 1) {
						high = mid - 1;
					} else {
						low = mid + 1;
					}
					dir ^= 1;
				}
			}
		}
		cout << bestl + 1 << " " << bestr + 1 << endl;

	}
	return 0;
}
