/*
 * SpiralMatrix.cpp
 *
 *  Created on: Aug 13, 2018
 *      Author: ashu
 */

#include <iostream>
#include <vector>
using namespace std;

// save 4 variables rBegin, rEnd, cBegin and cEnd;
// traverse right, bottom, left and up.
// update rBegin, rEnd, cBegin, cEnd

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

    	if( matrix.size() == 0) return vector<int>();

    	int rBegin = 0, cBegin = 0, k=0;
    	int rEnd = matrix.size() - 1;
    	int cEnd = matrix[0].size() - 1;

    	vector<int> result;

    	while( rBegin <= rEnd && cBegin <= cEnd){

    		// traverse left
    		for (int i=cBegin; i <= cEnd ; i++){
    			result.push_back(matrix[rBegin][i]);
    		}
    		rBegin++;

    		//traverse down
    		for (int i = rBegin; i<=rEnd; i++){
    			result.push_back(matrix[i][cEnd]);
    		}
    		cEnd--;

    		if( rBegin <= rEnd){
    			// traverse left
    			for (int i=cEnd; i>=cBegin; i--){
    				result.push_back(matrix[rEnd][i]);
    			}
    		}
    		rEnd--;

    		if( cBegin <= cEnd){
    			//traverse Up
    			for (int i=rEnd; i>=rBegin; i--){
    				result.push_back(matrix[i][cBegin]);
    			}
    		}
    		cBegin++;

    	}

    	return result;
    }
};


