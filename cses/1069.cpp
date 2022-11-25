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
    string s;
    cin >> s;
    long long res = 0;
    long long cnt = 0;
    char last = s[0];
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == last) cnt++;
        else {
            res = max(res, cnt);
            cnt = 1;
        }
        last = s[i];
    }
    res = max(res, cnt);
    cout << res << endl;
}