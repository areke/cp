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
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

vector<int> nextGreater(vector<long long>& nums) {
		stack<int> st;
		vector<int> res(nums.size());
		if (nums.size() > 0) st.push(0);
		for (int i = 1; i < nums.size(); i++) {
				if (nums[i] > nums[st.top()]) {
						while (!st.empty() && nums[i] > nums[st.top()]) {
								res[st.top()] = i - 1;
								st.pop();
						}
				}
				st.push(i);
		}
		while (!st.empty()) {
			res[st.top()] = nums.size() - 1;
			st.pop();
		}
		return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int m;
		cin >> m;
		vector<long long> r(m);
		map<long long, int> rc;
		for (int i = 0; i < m; i++) {
			cin >> r[i];
			rc[r[i]]++;
		}
		map<long long, vector<int> > ma;

		// razor can be used on index if desired length is >=.
		// consider all elements of a given desired height for each element x,
		// find first index to right that is greater. update [x, r + 1].
		// use that razor

		bool can = true;
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) can = false;
			if (a[i] != b[i]) {
				ma[b[i]].push_back(i);
			}
		}
		vector<int> d = nextGreater(b);
		for (auto it : ma) {
			int best = -1;
			int cnt = 0;
			for (auto x : it.second) {
				if (x <= best) continue;
				best = max(d[x], best);
				cnt++;
			}
			if (cnt > rc[it.first]) can = false;
		}
		if (can) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
