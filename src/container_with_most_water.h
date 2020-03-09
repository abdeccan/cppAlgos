#pragma once
#include "pch.h"

#define WATER_CONTAINER

class WaterContainer {
public:

	inline int min(int a, int b) {
		return a < b ? a : b;
	}

	int maxArea(vector<int>& height) {

		if (height.size() < 2) return 0;

		// brute force approach

		//int start = 0, end = 0;

		int max = 0, tmp = 0;

		for (int i = 0; i < height.size(); i++) {
			for (int j = i; j < height.size(); j++) {
				tmp = (j - i) * min(height[i], height[j]);
				if (tmp > max) {
					//start = i;
					//end = j;
					max = tmp;
					//cout << "Detected max at " << i << " " << j << " " << tmp << endl;
				}
			}
		}
		return max;
	}
}; #pragma once
