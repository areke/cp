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
    int n;
    cin >> n;
    long long x;
    cin >> x;
    long long res = 0;
    for (int i = 1; i < n; i++) {
        long long y;
        cin >> y;
        if (y < x) {
            res += (x - y);
        } else {
            x = y;
        }
    }
    cout << res << endl;
}