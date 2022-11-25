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

// [1, 2, 4, 5, 3, 6, 7]

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        long long x = a[i];
        while (x % 2 == 0) {
            x = x/ 2;
        }
        while (x % 3 == 0) {
            x = x / 3;
        }
        b[i] = x;
    }
    bool poss = true;
    for (int i = 1; i < n; i++) {
        if (b[i] != b[i - 1]) {
            poss = false;
        }
    }
    if (!poss) {
        cout << -1 << endl;
        return 0;
    }
    long long res = 1e10;
    long long curx = b[0];
    map<long long, int> m;
    long long curr = 1;
    for (int i = 0; i <= 30; i++) {
        long long curr2 = curr;
        for (int j = 0; j <= 30; j++) {
            if (curr2 > 1e9) break;
            m[curr2] = i + j; 
            curr2 *= 3;
        }
        curr *= 2;
    }
    for (int i = 0; i <= 30; i++) {
        long long cur = curx;
        for (int j = 0; j <= 30; j++) {
            if (cur > 1e9) {
                break;
            }
            bool can = true;
            long long val = 0;
            for (int k = 0; k < n; k++) {
                if (a[k] % cur != 0) can = false;
                val += m[a[k] / cur];
            }

            if (can) {
               // cout << can << " " << cur << " " << val << " " << i << " " << j << endl;
                res = min(res, val);
            }
            cur *= 3;
        }
        curx *= 2;
    }
    cout << res << endl;
}