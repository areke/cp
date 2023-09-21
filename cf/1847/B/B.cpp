#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int get(string & s, int a, int b) {
        int res = 0;
        for (int i = a; i <= b; i++) {
            res *= 2;
            res += (s[i] - '0');
        }
        return res;
    }
    int minimumBeautifulSubstrings(string s) {
        int bad = 1e6;
        vector<int> dp(s.length() + 1, bad);
        set<int> fives;
        int x = 1;
        for (int i = 1; i <= 9; i++) {
            fives.insert(x);
            x *= 5;
        }
        dp[0] = 0;
        vector<int> last(s.length() + 1, 0);
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                int y = get(s, j, i - 1);
                if (fives.count(y)) {
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
        if (dp[s.length()] >= bad) {
            return -1;
        }
        return dp[s.length()];
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> inp = {"1011", "111", "0"};
	Solution s = Solution();
	for (string t : inp) {
		cout << s.minimumBeautifulSubstrings(t) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
