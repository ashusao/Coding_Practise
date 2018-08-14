/*
 * strstr.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: ashu
 */

#include <iostream>
using namespace std;

// brute force technique check character by character

class Solution {
public:
    int strStr(string haystack, string needle) {

    	int n = haystack.length();
    	int m = needle.length();

    	if(!m) return 0;

    	for(int i=0; i<n; i++){
    		int j=0;
    		for(; j<m; j++){
    			if( haystack[i+j] != needle[j]) break;	// compare and break if char not matched
    		}

    		if( j==m) return i; // check if needle reached end
    	}

    	return -1;
    }
};


