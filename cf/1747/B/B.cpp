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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		long long res = n / 2 + (n % 2);
		vector<pair<long long, long long> > moves(res);
		for (int i = 0; i < res; i++) {
			moves[i] = make_pair(i * 3 + 1, 3 * n - i * 3);
		}
		cout << res << endl;
		for (int i = 0; i < res; i++) {
			cout << moves[i].first << " " << moves[i].second << endl;
		}
	}
	return 0;
}
