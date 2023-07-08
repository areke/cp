#include <bits/stdc++.h>
using namespace std;

int query(string & s) {
	cout << "? " << s << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}

int main() {
	int n, m;

	cin >> n >> m;
	vector<pair<int, int> > v(m);
	string output = "";
	for (int i = 0; i < m; i++) {
		output += "0";
	}
	for (int i = 0; i < m; i++) {
		output[i] = '1';
		v[i] = {query(output), i};
		output[i] = '0';
	}
	sort(v.begin(), v.end());
	int res = v[0].first;
	output[v[0].second] = '1';

	for (int i = 1; i < m; i++) {
		output[v[i].second] = '1';
		int next = query(output);
		if (next != res + v[i].first) {
			output[v[i].second] = '0';
		} else {
			res = next;
		}
	}
	cout << "! " << res << endl;
	cout.flush();

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
