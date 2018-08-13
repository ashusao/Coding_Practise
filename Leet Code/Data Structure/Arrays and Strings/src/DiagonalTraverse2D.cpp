/*
 * DiagonalTraverse2D.cpp
 *
 *  Created on: Aug 13, 2018
 *      Author: ashu
 */

#include <vector>
#include <iosfwd>
using namespace std;

// logic if r + c is even then traversing upward else traversing downward
// check boundary condition
// if goes out of top, left, right and bottom

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

		int m = matrix.size();
		if (m == 0)
			return vector<int>();

		int n = matrix[0].size();
		vector<int> result(m * n);

		int r = 0, c = 0;

		for (int i = 0; i < result.size(); i++) {
			result[i] = matrix[r][c];

			if ((r + c) % 2 == 0) {	// moving upward
				if (c == n - 1) {	// goes out from right
					r++;
				} else if (r == 0) { // goes out from top
					c++;
				} else {	// general case
					r--, c++;
				}
			} else {
				if (r == m - 1) { // goes out from bottom
					c++;
				} else if (c == 0) { // goes out from left
					r++;
				} else { // general case
					c--, r++;
				}
			}
		}

		return result;
	}
};

