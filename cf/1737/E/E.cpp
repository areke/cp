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
#include <assert.h>
using namespace std;

const int MOD = 1e9 + 7;

struct mi { // WARNING: needs some adjustment to work with FFT
 	int v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(long long _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, long long p) { assert(p >= 0); // won't work for negative p
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }


int main() {
	// assume last ant goes left
	// assume first ant goes right
	// RRRL RRRRL RRRL
	// = 4L, 5L, 4L
	// RLRRLR = 2L, 3L, L


	// Let p(i, j) = prob of ant in position j being winner for length i

	// assume p(i, j) is known for all i <= N, j <= N

	// if S_j == L, then p(i + 1, j) = p(i, j)
	// p(i + 1, j) = 1/2 * p(i, j) + 1/2 * X

	// let sequence be a_1, a_2, a_3, ..., a_n

	// 4L, 5L, 4L, 1L
	// RRRLRRRRLRRR L + R
	// RRRLRRRRLRRR L + L


	// 4L, 5L, 5L
	// RRRLRRRRLRRR R + R
	// RRRLRRRRLRRR R + L


	// let N be length of string before adding the new character,
	// and L_x be length of last group before adding the new character


	// if N is even,
	// P(N+1, N + 1) = 1/2 * P(N, N) becauese L_x >= N / 2
	// P(N + 1, N) = 1/2 * P(N, N)
	// P(N + 1, i) = P(N, i) for all 1 <= i < N


	// if N is odd, P(N + 1, N + 1) = P(N, N) + the case where L_X = N/2 - 1
		// = P(N, N) + (1/2)^(N/2 - 2)
		// N = 7 example RRRL RRR and add L
		// RRR LRRR
		// 1L then (N - 1)Rs

	// P(N + 1, N) = 1/2 P(N, N)
	// P(N + 1, N + 1) = 1/2 * P(N, N) + (1/2)^(N/2 - 1)
	// P(N + 1, i) = P(N, i) for all (N + 1) / 2 <= i < N
	// P(N + 1, i) = P(N, i) - 1/2^((N+1)/2) * P(N/2, i) for all 1 <= i < (N + 1) / 2
			// = P(N, i) * (1 - (1/2) ^((N + 1)/2))
	// do forward DP then correct the 1/2 terms afterwards.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<mi> res(n, 0);
		res[0] = 0;
		res[1] = 1;
		vector<mi> twos(n + 1);
		twos[0] = mi(1);
		for (int i = 1; i <= n; i++) {
			twos[i] = twos[i - 1] * 2;
		}
		for (int i = 2; i < n; i++) {
			if (i % 2 == 0) {
				res[i] = res[i - 1] / mi(2);
				res[i - 1] = res[i - 1] / mi(2);
			} else {
				res[i] = res[i - 1] / mi(2) + mi(1) / mi(twos[(i + 1) / 2]);
				res[i - 1] = res[i - 1] / mi(2);
				for (int j = 0; j < (i + 1) / 2; j++) {
					res[j] = res[j] * ((twos[(i) / 2] - mi(1)) / twos[(i) / 2]);
				}
			}
		}
		//cout << "HM" << endl;
	
		for (int i = 0; i < n; i++) {
			cout << res[i].v << endl;
		}
	}
	return 0;
}
