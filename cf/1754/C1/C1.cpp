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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		vector<pair<int, int> > res;
		for (int i = 1; i < n; i++) {
			if ((s > 0 && a[i] == 1) || (s < 0 && a[i] == - 1)) {
				res.push_back(make_pair(i - 1, i));
				i++;
				if (s > 0) s-=2;
				if (s < 0) s+=2;
			} else {
				res.push_back(make_pair(i - 1, i - 1));
			}
		}
		if (res.size() == 0 || res[res.size() - 1].second != n - 1) {
			res.push_back(make_pair(n - 1, n - 1));
		}
		if (s == 0) {
			cout << res.size() << endl;
			for (int i = 0; i < res.size(); i++) {
				cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
			}
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}
