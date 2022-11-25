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
		int n;
		cin >> n;
		if (n % 2 == 1) cout << 1 << " " << 2 << " " << 3 << " ";
		else cout << 2 <<  " " << 1 << " ";
		for (int i = 1; i < (n - 2) / 2; i++) {
			int big = 2 * i + 2 + (n % 2);
			int small = big - 1;
			cout << big << " " << small << " ";
		}
		cout << n - 1 << " " << n << endl;
	}
	return 0;
}
