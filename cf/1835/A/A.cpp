#include <bits/stdc++.h>
using namespace std;

long long count(long long a, int b, int c) {
	int low = 1;
	for (int i = 0; i < b - 1; i++) {
		low *= 10;
	}
	int high = low * 10 - 1;

	int lowc = 1;
	for (int i = 0; i < c - 1; i++) {
		lowc *= 10;
	}
	int highc = lowc * 10 - 1;
	
	int mini = a + low;
	int maxi = a + high;
	if (mini > highc || maxi < lowc) return 0;
	mini = max(mini, lowc);
	mini = min(mini, highc);
	maxi = max(maxi, lowc);
	maxi = min(maxi, highc);
	//cout << a << " " << b << " " << c << " " << mini << " " << maxi << endl;
	if (mini > maxi) return 0;
	return maxi - mini + 1;
}

void print(int a, int b) {
	cout << a << " + " << b << " = " << (a + b) << endl;
}

void solve(int a, int b, int c, long long t) {
	int low = 1;
	for (int i = 0; i < b - 1; i++) {
		low *= 10;
	}
	int high = low * 10 - 1;

	int lowc = 1;
	for (int i = 0; i < c - 1; i++) {
		lowc *= 10;
	}

	int highc = lowc * 10 - 1;
	for (int i = low; i <= high; i++) {
		if (a + i >= lowc && a + i <= highc) {
			t--;
		}
		if (!t) {
			print(a, i);
			return;
		}
	}
	assert(1 == 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int a, b, c;
		long long k;
		cin >> a >> b >> c >> k;
		int low = 1;
		for (int i = 0; i < a - 1; i++) {
			low *= 10;
		}
		int maxi = low * 10;
		long long s = 0;
		bool found = false;
		for (int i = low; i < maxi; i++) {
			long long olds = s;
			s += count(i, b, c);
			if (s >= k) {
				solve(i, b, c, k - olds);
				found = true;
				break;
			}
		}
		if (!found) {
			cout << -1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
