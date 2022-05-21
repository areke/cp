#include <iostream>
#include <numeric>
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
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	long long p = 1;

	for (int i = 1; i < n; i++) {
		if (gcd(i, n) == 1) {
			v.push_back(i);
			p = (p * i) % n;
		}
	}
	int res = v.size();
	int rem = -1;
	if (p != 1) {
		res = v.size() - 1;
		rem = p; 
	}
	cout << res << endl;
	for (int i = 0; i < v.size(); i++) {
		if (p == 1 || v[i] != p) cout << v[i] << " ";
	}
	cout << endl;



















}
