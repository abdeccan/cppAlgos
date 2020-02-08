#pragma once
#include "pch.h"

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

#define _ZIGZAGTEST_

// https://leetcode.com/problems/zigzag-conversion/
class Zigzag {

public:

	inline bool isDiag(int j, int diagPerSet) { return (j + 1) % diagPerSet == 0; }
	
	string convert(string s, int numRows) {
		size_t len = s.size();

		if (numRows <= 1) return s;

		int numDiagPerSet = numRows - 2;

		string res;

		// calculate the num columns
		// each diag elem is one column
		int numCols = 0;
		int tmp = len;
		while (tmp >= 0) {

			tmp -= numRows;
			numCols++;
			if (tmp > numDiagPerSet) {
				numCols += numDiagPerSet;
			}
			else if(tmp >= 0) {
				numCols += tmp;
			}
			tmp -= numDiagPerSet;
		}
		std::cout << "Num cols " << numCols << " numDiag " << numDiagPerSet << std::endl;

		char *arr = new char[numRows* numCols];
		memset(arr, 0, numRows * numCols);

		int pos = 0;
		
		int prevDiag = numRows - 1;

		for (int j = 0; j < numCols && pos < len; j++) {
			
			// diag col where we need to fill only one rows
			if (j % (numDiagPerSet + 1) != 0) {
				// diag elem
				arr[--prevDiag * numCols + j] = s[pos++];
			}
			else {
				prevDiag = numRows - 1;
				// non diag col where we need to fill all rows
				for (int i = 0; i < numRows && pos < len; i++) {
//					if (j % (numDiagPerSet + 1) == 0) {
						arr[i * numCols + j] = s[pos++];
//					}
				}
			}
		}

		// display
		for (int i = 0; i < numRows; i++) {
			
			for (int j = 0; j < numCols; j++) {
				char c = arr[i * numCols + j];
				if (c != 0) res += c;
				std::cout << arr[i * numCols + j] << "    ";
			}
			std::cout << std::endl;
		}

		return res;
	}
};