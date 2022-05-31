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
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int m;
		cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; i++) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a[n - 1] >= b[m - 1]) cout << "Alice" << endl;
		else cout << "Bob" << endl;
		if (b[m - 1] >= a[n - 1]) cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
	return 0;
}
