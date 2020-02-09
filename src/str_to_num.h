#pragma once
#include "pch.h"

#define STR_TO_NUM

class str_to_num {
	const char WHITE = ' ';
	inline bool isNum(int x) {
		return x >= 48 && x <= 57;
	}

public:

	int myAtoi(string str) {
		// first trim the whitespaces at start
		int idx = 0;
		for (; idx < str.size(); idx++) {
			if (str[idx] != WHITE) break;
		}

		char nonWhiteSpace = str[idx];
		int nonWhiteSpaceNum = (int)nonWhiteSpace;
		bool isNeg(false);
		if (nonWhiteSpace == '-') {
			isNeg = true;
			idx++;  // we now point to the chars after the neg
		}
		else if (nonWhiteSpace == '+') {
			isNeg = false;
			idx++;  // we now point to the chars after the neg
		}
		else if (!isNum(nonWhiteSpaceNum)) {
			// eliminate the non numeric starting chars
			return 0;
		}

		nonWhiteSpace = str[idx];   // check after the neg sign
		nonWhiteSpaceNum = (int)nonWhiteSpace;
		if (!isNum(nonWhiteSpaceNum)) {
			// eliminate the non numeric starting chars
			return 0;
		}

		int num = 0;
		list<int> digitlist;
		int nonZeroIndex = -1;
		// now we have only numbers
		for (int i = idx; i < str.size(); i++) {
			nonWhiteSpaceNum = (int)str[i];
			if (!isNum(nonWhiteSpaceNum)) {
				break;
			}
			
			if (nonZeroIndex == -1 && nonWhiteSpaceNum == 48) continue; // skip adding zeros

			if (nonZeroIndex == -1 && nonWhiteSpaceNum > 48) nonZeroIndex = i; // store the first non-zero index so that we can filter out out of range values

			if (i - nonZeroIndex > 9) return isNeg ? INT_MIN : INT_MAX;
			
			digitlist.push_back(nonWhiteSpaceNum - 48);
		}

		int cnt = 0;
		int tmp = 0;
		const int intmaxcap = INT_MAX - 2 * std::pow(10, 9);
		while (!digitlist.empty()) {
			tmp = digitlist.back();
			if (cnt > 8) {
				if (tmp > 2 && !isNeg) return INT_MAX;
				if (tmp > 2 && isNeg) return INT_MIN;
				if (tmp == 2) {
					if (num > intmaxcap && !isNeg) return INT_MAX;
					if (num - 1 >= intmaxcap && isNeg) return INT_MIN;
				}
				// tmp = 1 is safe here
			}
			num += std::pow(10, cnt++) * digitlist.back();
			digitlist.pop_back();
		}

		return isNeg ? 0 - num : num;
	}
};