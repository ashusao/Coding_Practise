/*
 * largestAtleastTwiceOfOthers.cpp
 *
 *  Created on: Aug 12, 2018
 *      Author: ashu
 */

#include <iostream>
#include <vector>
using namespace std;

// track highest, second highest and highest idex
// at end if highest is at least twice second highest return index else return -1

class Solution {
public:
    int dominantIndex(vector<int>& nums) {

    	int max=-1, index=-1, second=-1;

    	for(int i=0; i<nums.size(); i++){

    		if(nums[i] > max){		// tracking highest
    			index = i;
    			second = max;
    			max = nums[i];
    		}else if(nums[i] > second){	// tracking second highest
    			second = nums[i];
    		}
    	}
    	return (max >= 2*second)? index: -1;
    }
};
