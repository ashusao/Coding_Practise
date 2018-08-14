/*
 * longestCommonPrefix.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: ashu
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

    	string result = "";

    	if(!strs.size()) return result;

    	for(int i=0; i<strs[0].length(); i++){	// loop char by char on first string

    		char c = strs[0].at(i);

    		for(auto &s: strs){	// loop through all string
    			if( s.length() < i+1 || c != s.at(i)) // check if any string reaches end or any char changes
    				return result;
    		}
    		result += c;
    	}

    	return result;
    }
};


