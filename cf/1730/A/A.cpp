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
		int n, c;
		int a[100];
		cin >> n >> c;
		map<int, int> m;
		for (int i= 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		int res = 0;
		for (auto it : m) {
			res += min(c, it.second);
		}
		cout << res << endl;

	}
}
