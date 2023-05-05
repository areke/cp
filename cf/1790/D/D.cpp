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
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			m[x]++;
		}
		int res = 0;
		for (auto it : m) {
			
		
			while (m[it.first]) {
				res++;
				auto cur = it.first;
				while (m[cur]) {
					m[cur++]--;
				}
			}
		}
		cout << res << endl;


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
