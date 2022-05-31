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
	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;
		vector<vector<int> > v(2, vector<int>(n, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		vector<vector<int> > dp(2, vector<int>(n, 0));
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (v[0][i] == '*') {
				if (last != -1) {
					dp[0][i] = dp[0][i - 1] + (i - last);
				}
				last = i;
			}
		}
		for (int i = 0; i < n; i++) {
			
		}
	}
	return 0;
}
