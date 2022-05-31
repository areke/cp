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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int m;
		cin >> m;
		long long tot =0 ;
		for (int i = 0; i < m ; i++) {
			long long x;
			cin >> x;
			tot += x;
		}
		tot %= n;
		cout << a[tot] << endl;
	}
	return 0;
}
