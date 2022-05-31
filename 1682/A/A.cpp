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
		string s;
		cin >> s;
		int mid = s.length() / 2;
		int res = 1;
		int left = mid - 1;
		while (left >= 0 && s[mid] == s[left]) {
			res++;
			left--;
		}
		int right = mid + 1;
		while (right < s.length() && s[mid] == s[right]) {
			res++;
			right++;
		}
		cout << res << endl;
	}
	return 0;
}
