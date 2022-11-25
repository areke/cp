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
		long long arr[300];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long res = 1e9;
		for (int i = 0; i < n; i++) {
			vector<long long> d;
			for (int j = 0; j < n; j++) {
				d.push_back(abs(arr[i] - arr[j]));
			}
			sort(d.begin(), d.end());
			res = min(res, d[0] + d[1] + d[2]);
		}
		cout << res << endl;
	}
	return 0;
}
