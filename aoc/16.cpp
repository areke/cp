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
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
#include <numeric>
using namespace std;

long long sum(vector<vector<long long> > & v) {
	long long res = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			res += v[i][j];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int x = 4;
	int y = 8;
	vector<vector<vector<long long> > > dp(2, vector<vector<long long> >(22, vector<long long>(11, 0)));
	dp[0][0][7] = 1;
	dp[1][0][10] = 1;
	vector<long long> res(2, 0);
	vector<long long> roll(10, 0);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				roll[i + j + k]++;
			}
		}
	}
	
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 2; j++) {
			vector<vector<long long> > next(22, vector<long long>(11, 0));
			for (int val = 1; val <= 9; val++) {
				for (int l = 0; l < 21; l++) {
					for (int s = 1; s <= 10; s++) {
						int n = (s + val) % 10;
						if (n == 0) n = 10;
						if (l + n < 21) {
							next[l + n][n] += dp[j][l][s] * roll[val];
						} else {
							res[j] += dp[j][l][s] * sum(dp[j ^ 1]) * roll[val];
						}	
					}
				}
				
			}
			dp[j] = next;
		}
	}
	cout << max(res[0], res[1]) << endl;

	 
	return 0;
}
