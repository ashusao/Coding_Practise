/*
 * PlusOne.cpp
 *
 *  Created on: Aug 12, 2018
 *      Author: ashu
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

    	int n = digits.size();
    	for( int i=n-1; i>=0; i++){
    		if( digits[i] == 9){
    			digits[i] = 0;
    		}else{
    			digits[i]++;
    			return digits;
    		}
    	}
    	digits[i] = 1;
    	digits.push_back(0);
    	return digits;
    }
};

