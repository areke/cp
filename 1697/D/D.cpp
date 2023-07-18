#include <bits/stdc++.h>
using namespace std;

int query2(int l, int r) {
	cout << "? " << 2 << " " << l + 1 << " " << r + 1 << endl;
	int x;
	cin >> x;
	return x;
}

char query1(int ind) {
	cout << "? " << 1 << " " << ind + 1<< endl;
	char x;
	cin >> x;
	return x;
}

int main() {
	int n;
	cin >> n;
	vector<char> s(n);
	vector<int> used;
	map<char, int> last;
	s[0] = query1(0);
	used.push_back(0);
	for (int i = 1; i < n; i++) {

		int low = 0;
		int high = (int)used.size() - 1;
		int best = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			int x = query2(used[mid], i);
			int exp = (int)used.size() - 1 - mid + 1;
			if (x > exp) {
				high = mid - 1;
			} else {
				best = mid;
				low = mid + 1;
			}
		}
		if (best == -1) {
			s[i] = query1(i);
			used.push_back(i);
		} else {
			s[i] = s[used[best]];
			used.erase(used.begin() + best);
			used.push_back(i);
		}
	}
	cout << "! ";
	for (char c : s) cout << c;
	cout << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
