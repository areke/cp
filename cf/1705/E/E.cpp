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
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
 
const long long MAXN = 200100;
 
const unsigned long long mask = -1;
void add(int ind, vector<unsigned long long> & v) {
	int ai = ind / 64;
	ind %= 64;
	unsigned long long last = v[ai];
	v[ai] += (1ULL << ind);
	while (v[ai] < last) {
		ai++;
		last = v[ai];
		v[ai]++;
	}
}
 
void subtract(int ind, vector<unsigned long long> & v) {
	int ai = ind / 64;
	ind %= 64;
	unsigned long long last = v[ai];
	v[ai] -= (1ULL << ind);
	while (v[ai] > last) {
		ai++;
		last = v[ai];
		v[ai]--;
	}
}
 
int get(vector<unsigned long long> & v) {
	for (int i = v.size() - 1; i >= 0; i--) {
		if (mask & v[i]) {
			unsigned long long x = v[i];
			int add = 0;
			while (x >>= 1) {
				add++;	
			}
			return (i * 64 + add);
		}
	}
	return -1;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, q;
	cin >> n >> q;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<unsigned long long> s(MAXN / 64 + 1);
	for (int i = 0; i < n; i++) {
		add(a[i], s);
	}
	for (int qq = 0; qq < q; qq++) {
		int k, l;
		cin >> k >> l;
		k--;
		subtract(a[k], s);
		a[k] = l;
		add(a[k], s);
		cout << get(s) << endl;
	}
	
 
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}