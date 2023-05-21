#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		int low = 1;
		int high = n;
		int res = -1;
		set<int> last;
		for (int i = 1; i <= n; i++) {
			last.insert(i);
		}
		while (low <= high) {
			if (low == high) {
				res = low;
				break;
			}
			int mid = (low + high) / 2;
			cout << "? " << low << " " << mid << endl;
			set<int> left;
			set<int> right = last;
			for (int i = 0; i < mid - low + 1; i++) {
				int x;
				cin >> x;
				left.insert(x);
				right.erase(right.find(x));
			}
			int leftc = 0, rightc = 0;
			for (int i = low; i <= mid; i++) {
				if (left.find(i) != left.end()) leftc++;
			}
			for (int i = mid + 1; i <= high; i++) {
				if (right.find(i) != right.end()) rightc++;
			}
			if (leftc % 2) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		cout << "! " << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
