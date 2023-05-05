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
    while (n != 1) {
        cout << n << endl;
        if (n % 2) n = n * 3 + 1;
        else n /= 2;
    }
    cout << n << endl;
}