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
	// Suppose we just have a graph with N "1"s.
	// If N % 2 == 1, the degree sum is odd, so print 1.
	// If N % 2 == 0, consider a star around the first vertex.
	// Clearly, the graph is planar. The degree sum is 2N - 2.
	// and the graph is connected, so it is a tree.
	
	// Suppose you add a 0 in between any 1s. Just connect it to the 1 on its left.
	//
	// All 0s is impossible.
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		//cout << s << endl;
		int ones = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') ones++;
		}
		if (ones == 0 || ones % 2) {
			cout << "NO" << endl;
			continue;
		}
		int shift = 0;
		int rshift = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				shift = i;
				rshift = i;
				break;
			}
		}
		rotate(s.begin(), s.begin() + rshift, s.end());
		cout << "YES" << endl;
		// cout << s << " " << shift << endl;
		vector<int> v;
		v.push_back(0);
		vector<vector<int> > inds;
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') {
				inds.push_back(v);
				v.clear();
			}

			v.push_back(i);
		}
		if (v.size()) inds.push_back(v);
		/**
		for (int i = 0; i < inds.size(); i++) {
			for (int j = 0; j < inds[i].size(); j++) {
				cout << inds[i][j] << " ";
			}
			cout << endl;
		}
		cout << "---" << endl; */
		int first = inds[0][inds[0].size() - 1];
		for (int i = 0; i < inds.size(); i++) {
			for (int j = 1; j < inds[i].size(); j++) {
				cout << (inds[i][j] + shift) % n + 1 << " " << (inds[i][j - 1] + shift) % n + 1<< endl;
			}
			if (i > 0) {
				cout << (first + shift) % n + 1 << " " << (inds[i][inds[i].size() - 1] + shift) % n+ 1 << endl;
			}
		}
	}
	return 0;
}
