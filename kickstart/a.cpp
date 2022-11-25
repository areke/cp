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
        long long l,n, d;
        cin >> l >> n;
        char dir;
        long long pos = 0;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            char c;
            cin >> x >> c;
            if (i == 0) dir = c;
            if (dir == c) {
                res += (pos + x) / l;
                pos = (pos + x) % l;
            } else {
                if (x >= pos) {
                    x -= pos;
                    pos = 0;
                    res += (pos + x) / l;
                    pos = (pos + x) % l;
                    dir = c;
                } else {
                    pos -= x;
                }
            }
        }
        cout << "Case #" << test << ": " << res << endl; 
    }
}