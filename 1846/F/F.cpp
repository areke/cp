#include <bits/stdc++.h>
using namespace std;

vector<int> rem(vector<int> v, int s) {
	cout << "- ";
	cout << v.size();
	if (v.size() == 0) {
		cout << endl; 
	} else {
		cout << " ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " \n"[i == v.size() - 1];
		}
	}

	cout.flush();
	int ns = s - v.size();
	vector<int> a(ns);
	for (int i = 0; i < ns; i++) {
		cin >> a[i];
	}
	return a;
}

int main() {
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> c;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			c[a[i]]++;
		}

		int type = -1;
		for (int t = 0; t < 2; t++) {
			auto b = rem({}, n);
			map<int, int> d;
			for (int x : b) {
				d[x]++;
			}
			for (int i = 1; i <= 9; i++) {
				if (d[i] > c[i]) {
					//assert(d.size() >= 2);
					type = i;
				}
			}
			if (type != -1) {
				a = b;
				c = d;
				break;
			}
		}
		assert(type != -1);
		vector<int> tr;
		for (int i = 0; i < n; i++) {
			if (a[i] != type) {
				tr.push_back(i + 1);
			}
		}
		vector<int> b = rem(tr, n);
		for (int t = 0; t < 2; t++) {
			
			int ind = -1;
			for (int i = 0; i < b.size(); i++) {
				if (b[i] != type) {
					ind = i;
					break;
				}
			}
			if (ind != -1) {
				cout << "! " << ind + 1 << endl;
				cout.flush();
				break;
			}
			if (t == 1) assert(false);
			b = rem({}, b.size());
		}
	}





	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
