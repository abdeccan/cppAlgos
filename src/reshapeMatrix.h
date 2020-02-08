#pragma once
#include "pch.h"

#define _RESHAPEMATRIX_TEST_

// https://leetcode.com/problems/reshape-the-matrix/

class ReshapeMatrix {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		size_t inRows = nums.size();
		size_t inCols = 0;
		if (inRows > 0) {
			inCols = nums[0].size();
		}
		else {
			return nums;
		}

		if (inCols == 0) return nums;

		if (inCols > 1000 || inRows > 1000 || r <= 0 || c <= 0) return nums;

		if (inRows * inCols != r * c) return nums;

		vector<int> tmp;

		vector<vector<int>> res;

		for (int idx = 0; idx < inRows; idx++) {
			for (int idy = 0; idy < inCols; idy++) {
				tmp.push_back(nums[idx].at(idy));
				//printf("tmp[%d] : %d",inCols*idx + idy, tmp[inCols*idx + idy] );
			}
		}

		for (int idx = 0; idx < r; idx++) {
			vector<int> tmp1;
			for (int idy = 0; idy < c; idy++) {
				tmp1.push_back(tmp[c * idx + idy]);
				if (idy == c - 1) {
					res.push_back(tmp1);
				}
			}
		}

		return res;

	}
};