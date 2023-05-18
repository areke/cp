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
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

long long dp[20][10][2][2];
bool vis[20][10][2][2];


long long cnt(vector<int> & v, int ind, int d, int z, int e) {
	if (ind == v.size() - 1) {
		//cout << ind << " huh " << d << " " << z << " " << e << " " << 1 << endl;
		return 1;
	}
	if (vis[ind][d][z][e]) return dp[ind][d][z][e];
	
	int maxi = e ? v[ind + 1] : 9;
	
	vis[ind][d][z][e] = 1;
	
	long long res = 0;
	for (int i = 0; i <= maxi; i++) {
		if (d == i && !(z & (i == 0))) continue;
		res += cnt(v, ind + 1, i, z & (i == 0), e & (i == v[ind + 1]));
	}
	return dp[ind][d][z][e] = res;
}

long long solve(long long a) {
	if (a < 10) return a + 1;
	vector<int> v;
	long long x = a;
	while (x) {
		v.push_back(x % 10);
		x /= 10;
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					dp[i][j][k][l] = 0;
					vis[i][j][k][l] = 0;
				}
			}
		}
	}
	long long res = 0;
	for (int i = 0; i <= v[0]; i++) {
		res += cnt(v, 0, i, (i == 0), (i == v[0]));
	}
	return res;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b;
	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
