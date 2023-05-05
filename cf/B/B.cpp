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
	int tests = 1;
	while (tests--) {
		int n, t;
		cin >> n >> t;
		string s;
		cin >> s;
		while (t--) {
			for (int i = n - 1; i >= 1; i--) {
				if (s[i] == 'G' && s[i - 1] == 'B') {
					swap(s[i], s[i - 1]);
					i--;
				}
			}
		}
		cout << s << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
