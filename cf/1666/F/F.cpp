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


// b_n is largest
// b_{n-2} is 2nd largest
// b_{n-1} can be ANY value
//	if b_{n-1} is 3rd largest, b_{n-3} must be 4th largest

// if choosing from end to beginning, the even indices are fixed because they must be the largest value
// that remains
//
// this means that if there are no duplicates, there are (n - 2) * (n - 4) * ... ways to arrange the blocks
//
// if there are x duplicates of a specific number, y, at least x - 1 of them must be in an odd place. so
// x - 1 of them must be used before y is the largest
//
// there must be at least x numbers > y
//
// place numbers with duplicates in descending order? doesn't seem to work
//
// dp on odd vs even placement
// dp[i+1][j] = dp[i][j] if a[i + j] != a[i + j - 1]
// dp[i][j+1] 
//if z numbers > y, z-1 spots to place y. so C(z-1, x) ways. 
//
//
//
// 1 1 2 3 4 4 6 7
//
//_ _ _ 4 _ 6 4 7
//
//1 2 1 4 3 6 4 7
//1 3 1 4 2 6 4 7
//1 3 2 4 1 6 4 7
//2 3 1 4 1 6 4 7




// 1 1 2 3 4 5
//
// _ _ _ 4 1 5 ... 2 ways
//
// 1 3 2 4 1 5
//
// 2 3 1 4 1 5
//
// _ _ 1 4 _ 5 ... 3 ways with 1 overlap
//
// 1 2 1 4 3 5
// 1 3 1 4 2 5
// 2 3 1 4 1 5
//

//
// 
//

const int N = 5000;
int dp[N][N];

void solve() {
	int n;
	cin >> n;
	int a[5000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	reverse(a, a+n);

	cout << "?" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	cout << "?" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i / 2; j++) {
			if (i == 0 || a[i] != a[i-1]) {
				if (i + 1 - j <= n / 2) {
					dp[i+1-j][j] += dp[i - j][j];
				}
			}
			if (i -j >= n / 2) dp[i-j][j+1] += dp[i - j][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << dp[i][j] << " " ;
		}
		cout << endl;
	}
	cout << dp[n/2][n/2] << endl;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}
