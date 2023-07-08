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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

// #a#b#a#a#b#a#
// 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> m = manacher(s);
		vector<int> e(n + 1, 0);
		for (int i = 0; i < n; i++) {
			e[i + 1] = (m[2 * i + 1] - 1) / 2;
		}
		
		vector<int> dp(n + 1, 0);
		stack<int> st;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && i - st.top() >= e[st.top()]) {
				st.pop();
			}
			if (e[i]) {
				st.push(i);
			}
			if (!st.empty()) {
				dp[i + 1] = dp[st.top() - (i - st.top()) - 1] + 1;
			}
			

			res += dp[i + 1];
		}
		

		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
