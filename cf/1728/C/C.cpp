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
		multiset<long long> as;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			as.insert(x);

		}
		vector<long long> b;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			if (as.find(x) == as.end()) {
				b.push_back(x);
			}
			else {
				as.erase(as.find(x));
			}
		}
		vector<long long> a;
		for (long long x : as) {
			a.push_back(x);
		}
		long long res = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > 9) {
				res++;
				a[i] = log10(a[i]) + 1; 
			}
			if (b[i] > 9) {
				res++;
				b[i] = log10(b[i]) + 1;
			}
		}
		map<int, int> am;
		map<int, int> bm;
		for (int i = 0; i < a.size(); i++) {
			am[a[i]]++;
			bm[b[i]]++;
		}
		for (int i = 1; i <= 9; i++) {
			long long x = max(0, am[i] - bm[i]);
			bm[i] = max(0, bm[i] - am[i]);
			am[i] = x;
		}
		for (int i = 2; i <=9; i++) {
			//cout << i << " " << am[i] << " " << bm[i] << endl;
			res += am[i];
			res += bm[i];
		}
		cout << res << endl;

	}
	return 0;
}
