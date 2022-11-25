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
    long long n;
    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (i < n) {
            long long x;
            cin >> x;
            res ^= x;
        }
        res ^= i;
        
    }
    cout << res << endl;
}