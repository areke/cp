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
		vector<pair<long long, int> > odds;
		vector<pair<long long, int> > evens;
		int first;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			if (x % 2) odds.push_back(make_pair(x,i + 1));
			else evens.push_back(make_pair(x, i + 1));
			if (i == 0) first = x;
		}
		if (first % 2 == 1) {
			swap(evens, odds);
		}
		cout << evens.size() - 1 + odds.size() << endl;
		for (int i = evens.size() - 2; i >= 0; i--) {
			cout << evens[i].second << " " << evens[i + 1].second << endl;
		}
		for (int i = 0; i< odds.size(); i++) {
			cout << 1 << " " << odds[i].second << endl;
		}
	}
}
