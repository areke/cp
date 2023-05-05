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
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int x = 0;
    int y = 0;
    string s;
    int v;
    long long aim = 0;
    while (cin >> s >> v) {
        if (s == "forward") {
            x += v;
            y += aim * v;
        } else if (s == "up") {
            aim -= v;
        } else if (s == "down") {
            aim += v;
        } else {
            x -= v;
        }
    }
    cout << x << " " << y << endl;
    cout << x * y << endl;
	return 0;
}
