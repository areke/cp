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


int gcd(int a, int b) {
	return a == 0 ? b : gcd(b % a, a);
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		bool bb = true;
		vector<int> res(n + 1);
		res[0] = v[0];
		for (int i = 1; i < n; i++) {
			res[i] = v[i];
			if (res[i] % v[i - 1] != 0) {
				int g = gcd(res[i], v[i - 1]);
				res[i] *= v[i - 1] / g;
			}
		}
		res[n] = v[n - 1];
		for (int i = 1; i <= n; i++) {
			//cout << res[i] << " ";
			if (gcd(res[i], res[i - 1]) != v[i - 1]) bb = false;
		}
		if (bb) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
