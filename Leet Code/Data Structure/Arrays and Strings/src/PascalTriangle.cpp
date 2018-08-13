/*
 * PascalTriangle.cpp
 *
 *  Created on: Aug 13, 2018
 *      Author: ashu
 */
#include <iostream>
#include <vector>
using namespace std;

// take var of vector of vectors
// loop through number of rows and insert a row of 1's
// update the middle values

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

    	vector<vector<int>> result;

    	for (int i=0; i<numRows; i++){
    		result.push_back(vector<int>(i+1, 1));

    		for (int j=1; j<i; j++){
    			result[i][j] = result[i-1][j-1] + result[i-1][j];
    		}
    	}

    	return result;
    }
};

