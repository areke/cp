#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int best = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            bool alt = abs(nums[i] - nums[i + 1]) == 1;
            if (!alt) continue;
            int x = nums[i + 1] - nums[i];
            int res = 2;
            best = max(res, best);
            for (int j = i + 1; j < nums.size() - 1; j++) {
                int y = nums[j + 1] - nums[j];
                if (x != -1 * y) {
                    break;
                }
                x = y;
                res++;
                best = max(best, res);
            }
        }
        return best;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<vector<int > > inp = {{2, 3, 4, 3, 4}, {4, 5, 6}};
	for (auto & x : inp) {
		cout << s.alternatingSubarray(x) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
