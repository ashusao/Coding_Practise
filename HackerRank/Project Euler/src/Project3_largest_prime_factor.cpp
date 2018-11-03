#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

/*
long largest(long n){

	long max=-1;

	while (n % 2 == 0) {
		max = 2;
		n /= 2; // equivalent to n /= 2
	}

	// n must be odd at this point, thus skip
	// the even numbers and iterate only for
	// odd integers
	for (int i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			max = i;
			n = n / i;
		}
	}

	// This condition is to handle the case
	// when n is a prime number greater than 2
	if (n > 2)
		max = n;

	return max;

}


int main(){
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; a0++){
		long n;
		cin >> n;
		cout << largest(n)<<endl;
	}
	return 0;
}
*/

