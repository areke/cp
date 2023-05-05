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
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> res(n, 0);
		int orig = n;
		while (n) {
			if (n == 2) {
				res[1] = 0;
				res[0] = 1;
				break;
			} else if (n == 1) {
				res[0] = 0;
				break;
			} else if (n == 3) {
				res[0] = 1;
				res[1] = 0;
				res[2] = 2;
				break;
			} else if (n == 4) {
				res[0] = 0;
				res[1] = 3;
				res[2] = 2;
				res[3] = 1;
				break;
			} else if (n == 5) {
				res[4] = 0;
				res[3] = 1;
				res[2] = 2;
				res[1] = 3;
				res[0] = 4;
				break;
			}
			int x = sqrt(n - 1) + 1;
			int t = x * x;
			//cout << n << " " << x << " ? " << endl; 
			for (int i = n - 1; i >= t - n + 1; i--) {
				res[t - i] = i; 
			}
			
			//cout << n << endl;
			//t + 1 > 2n
			n = t - n + 1;
		}
		for (int i = 0; i < orig; i++) {
			cout << res[i];
			if (i == orig - 1) cout << endl;
			else cout << " ";
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
