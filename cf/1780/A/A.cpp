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
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int o = 0;
		int e = 0;
		vector<int> odd;
		vector<int> even;
		for (int i = 0; i < n; i++) {
			if (v[i] % 2) {o++;
			odd.push_back(i + 1);
			}
			else {
				e++;
				even.push_back(i + 1);
			}
		}
		if (o >=1 && e >= 2) {
			cout << "YES" << endl;
			cout << odd[0] << " " << even[0] << " " << even[1] << endl;
		} else if (o >= 3) {
			cout << "YES" << endl;
			cout << odd[0] << " " << odd[1] << " " << odd[2] << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
