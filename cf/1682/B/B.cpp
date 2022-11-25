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
	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;
		int x = -1;
		for (int i = 0; i < n; i++) {
			int y;
			cin >> y;
			if (y != i) {
				if (x == -1) x = y;
				else x &= y;
			}
		}
		cout << x << endl;
	}
	return 0;
}
