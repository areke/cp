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
	while (tests--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool q = false;
		stack<char> st;
		bool b = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'Q') {
				q = true;
				st.push(s[i]);
			} else {
				if (!q) {
					b = false;
					break;
				}
				if (!st.empty()) {
					st.pop();
				}
			}
		}
		if (!st.empty()) b = false;
		if (b) cout << "Yes" << endl;
		else cout <<"No" << endl;
	}
	return 0;
}
