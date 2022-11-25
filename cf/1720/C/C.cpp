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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > v(n, vector<int>(m, 0));
		long long su = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				v[i][j] = (s[j] - '0');
				su += v[i][j];
			}
		}
		int mini = 3;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				int ss = 0;
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						ss += v[i + k][j + l];
					}
				}
				if (ss > 0) {
					mini = min(max(0, ss - 2), mini);
				}
			}
		}
		
		cout << max((long long)0, su - mini) << endl;
	}
	return 0;
}
