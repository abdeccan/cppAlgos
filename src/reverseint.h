#pragma once
#include "pch.h"
#include "list"
#include <iostream>

#define _REVERSEINT_

class reverseint {
public:

	int reverse(int x) {
		int intmax = std::pow(2, 31) - 1;
		int intmin = 0 - std::pow(2, 31);
		int intmaxlimit = 147483647; // (intmax - 2000000000) we need this because the final addition would result in overflow!
		if (x == intmax || x == intmin) return 0;

		int cnt = 0;
		int result = 0;
		list<int> res;
		bool isNeg = x < 0;
		if (isNeg) x = 0 - x;
		while (x >= 10) {
			res.push_back(x % 10);
			x = x / 10;
		}

		res.push_back(x);

		while (!res.empty() && result < intmax) {
			// why we need special handling for cnt > 8??
			// because when the final digit is being added i.e. final_digit * 1 billion (1,000,000,000) it
			// could result in overflow!!
			if (cnt > 8) {
				if (res.back() > 2) return 0;

				else if (res.back() == 2) {
					if (result > intmaxlimit) return 0;
				}
			}
			int tmp = std::pow(10, cnt++) * res.back();

			result += tmp;
			res.pop_back();
		}

		return isNeg ? 0 - result : result;
	}
};