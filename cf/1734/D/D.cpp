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

bool solve(int n, int k, vector<long long> & arr) {
	long long health = 0;
	queue<pair<long long, long long> > q;
	long long cost = 0;
	long long s = 0;
	for (int i = k + 1; i < n; i++) {
		s += arr[i];
		cost = min(cost, s);
		if (s > 0) {
			q.push(make_pair(cost, s));
			s = 0;
			cost = 0;
		}
	}	
	for (int i = k; i >= 0; i--) {
		health += arr[i];
		while (!q.empty() && health + q.front().first >= 0) {
			health += q.front().second;
			q.pop();
		}
		if (health < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n, k;
		cin >> n >> k;
		vector<long long> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		k--;
		bool b = solve(n, k, arr);
		k = n - k - 1;
		reverse(arr.begin(), arr.end());
		b |= solve(n, k, arr);
		if (b) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
	return 0;
}
