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
        long long y, x;
        cin >> y >> x;
        long long maxi = max(x, y);
        long long start = (maxi - 1) * (maxi - 1) + 1;
        if (maxi % 2 == 0) {
            start += (y - 1);
            start += (maxi - x);
            
        } else {
            start += (x - 1);
            start += (maxi - y);
        }
        cout << start << endl;
    }
}