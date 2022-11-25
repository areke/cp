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
#include <assert.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    int test = 0;
    while (tests--) {
        test++;
        long long l;
        cin >> l;
        vector<long long> dp(l + 1, 1e18);
        dp[0] = 0;
        vector<long long> best(l + 1, 0);
        for (int i = 0; i < l; i++) {
            dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
            for (int k = 1; k <= l; k++) {
                if (i + k * i > l) break;
                dp[i + k * i] = min(dp[i] + 4 + k * 2, dp[i + k * i]);
            }
        }
        cout << "Case #" << test << ": " << dp[l] << endl; 
    }
}