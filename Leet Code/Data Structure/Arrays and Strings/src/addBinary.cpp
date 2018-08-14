/*
 * addBinary.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: ashu
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

    	string result = "";

    	int c=0, i=a.length()-1, j = b.length()-1;

    	while(i>=0 || j>=0 || c==1){

    		if(i>=0){
    			c += a[i] - '0';	// convert characcter to unicode
    		}

    		if(j>=0){
    			c += b[j] - '0';	// convert characcter to unicode
    		}

    		// if sum is 1 or 3 add 1 else add 0 to result
    		result = char(c%2) + result;

    		//calculate carry
    		c /= 2;
    		i--, j--;
    	}

    	return result;
    }
};
