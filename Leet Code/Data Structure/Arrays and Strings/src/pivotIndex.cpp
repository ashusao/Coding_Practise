/*
 * pivotIndex.cpp
 *
 *  Created on: Jul 24, 2018
 *      Author: ashu
 */

#include <iostream>
#include <vector>
using namespace std;

// calculate sum of array
// Initialize left to 0 and right to sum
// loop through array
// 1. subtract num from right 2. compare left and right 3. add num to left.

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

    	int sum=0, left=0, right=0;

    	for(auto &n: nums) sum+=n;

    	right = sum;
    	for(auto i=0; i<nums.size(); ++i){
    		right -= nums[i];
    		if(left == right)
    			return i;
    		left += nums[i];
    	}

    	return -1;
    }
};

