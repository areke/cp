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
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			res[(n - a[i])] = i + 1;
		}
		for (int i = 1; i <= n; i++) {
			cout << res[i - 1] << " ";
		}
		cout << endl;
	}
	return 0;
}
