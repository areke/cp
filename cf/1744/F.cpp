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
    while (tests--) {
        int n;
        cin >> n;
        vector<pair<int, int> > p(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            p[i] = make_pair(x, i);
        }
        sort(p.begin(), p.end());
        int l = 1e6;
        int r = 0;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            l = min(l, p[i].second);
            r = max(r, p[i].second);
            int l1 = 2 * i + 1;
            int l2 = l1 + 1;
            int d = (r - l + 1);
            vector<int> lengths = {l1, l2};
            for (int len : lengths) {
                if (len > n) continue;
                if (d > len) continue;
                int s = max(0, r - len + 1);
                int e = min(l, n - len);
                //cout << s << " " << l << " " << r << " " << d << " " << len << endl;
                res += e - s + 1;
            }
        }
        cout << res << endl;

    }
}