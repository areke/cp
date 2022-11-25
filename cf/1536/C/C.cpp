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
	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int d = 0;
		map<pair<int, int>, int> m;
		vector<int> v(n);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'D') d++;
			int k = i + 1 - d;
			int g = gcd(d, k);
			pair<int, int> p = make_pair(d / g, k / g);
			m[p]++;
			v[i] = m[p];
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
