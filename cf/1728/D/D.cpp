#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include <limits>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

const int DRAW = 5;
const int ALICE = 10;
const int BOB = 11;

long long hsh(char c, int start, int length) {
	return c + start * 2001 + length * 2001 * 2001;
}

int solve(int t, char c, string & s, int start, int length, unordered_map<long long, int> & dp) {
	int dpv = dp[hsh(c, start, length)];
	if (dpv) return dpv;
	if (length == 0) {
		return DRAW;
	}
	int choice1 = solve(t ^ 1, s[start], s, start + 1, length - 1, dp);
	int choice2 = solve(t ^ 1, s[start + length - 1], s, start, length - 1, dp);
	int res = DRAW;
	if (t == 0) { 
		if (choice1 == ALICE || choice2 == ALICE) res = ALICE;
		else if (choice1 == DRAW || choice2 == DRAW) {
			res = DRAW;
		}
		else res = BOB;
	} else {
		if (choice1 == BOB || choice2 == BOB) res = BOB;
		else if (choice1 == DRAW) {
			if (s[start] < c) res = BOB;
			else if (s[start] == c) res = DRAW;
			else res = ALICE;
		} else if (choice2 == DRAW) {
			if (s[start + length - 1] < c) res = BOB;
			else if (s[start + length - 1] == c) res = DRAW;
			else res = ALICE;
		}
		else res = ALICE;
	}
	dp[hsh(c, start, length)] = res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		string s;
		cin >> s;
		unordered_map<long long, int> dp;
		char first = 'a' - 1;
		int res = solve(0, first, s, 0, s.length(), dp);
		if (res == DRAW) cout << "Draw" << endl;
		else if (res == ALICE) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
	return 0;
}
