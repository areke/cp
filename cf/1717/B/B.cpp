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

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n, k, r, c;
		cin >> n >> k >> r >> c;
		int rm = (r + c) % k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((i + j) % k == rm) {
					cout << "X";
				} else {
					cout << ".";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
