#pragma once
#include "pch.h"

#define THREE_NUM_SUM


class three_num_sum {
public:

	static inline bool int_compare(int a, int b) {
		return a > b;
	}





	vector<vector<int>> threeSum_approach1(vector<int>& nums) {

		vector<vector<int>> result;
		typedef multimap<int, int>::iterator mmit;
		if (nums.size() < 3) return result;

		multimap<int, int> val_to_index_map;

		for (int i = 0; i < nums.size(); i++) {
			val_to_index_map.insert(make_pair(nums[i], i));
		}

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				pair<mmit, mmit> mmItr = val_to_index_map.equal_range(0 - (nums[i] + nums[j]));
				if (mmItr.first != mmItr.second) {
					//vector<int>::iterator it = std::find(nums.begin(), nums.end(), 0 - (nums[i] + nums[j]));
					// we may have a match!
					//int index = std::distance(nums.begin(), it);
					int index = -1;
					for (mmit itTmp = mmItr.first; itTmp != mmItr.second; itTmp++) {
						if (itTmp->second != i && itTmp->second != j) {
							index = itTmp->second;
							break;
						}
					}
					//if(index != i && index != j) 
					if (index != -1)
					{
						//cout << "Have a match at index is " << index << " i is " << i << " j is " << j << endl;
						// we have a match at i, j and index
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[index]);
						std::sort(tmp.begin(), tmp.end(), three_num_sum::int_compare/*[](int a, int b) {return a > b;}*/);
						vector<vector<int>>::iterator res_it = std::find(result.begin(), result.end(), tmp);
						if (res_it == result.end()) result.push_back(tmp);
					}
				}
			}
		}

		return result;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {

		typedef multimap<int, pair<int, int>> mm;
		typedef multimap<int, pair<int, int>>::iterator mmit;

		vector<vector<int>> res;

		if (nums.size() < 3) return res;

		mm sum_idx_map;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				sum_idx_map.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
			}
		}

		set<vector<int>> myset;
		for (int k = 0; k < nums.size(); k++) {
			pair<mmit, mmit> it = sum_idx_map.equal_range(0 - nums[k]);
			if (it.first != it.second) {
				for (mmit itTmp = it.first; itTmp != it.second; itTmp++) {
					if (itTmp->second.first != k && itTmp->second.second != k) {
						// we have a match for 3-sum
						vector<int> tmp;
						tmp.push_back(nums[k]);
						tmp.push_back(nums[itTmp->second.first]);
						tmp.push_back(nums[itTmp->second.second]);
						sort(tmp.begin(), tmp.end(), [](int a, int b) {return a < b; });
						myset.insert(tmp);
					}
				}
			}
		}

		for (vector<int> v : myset) {
			res.push_back(v);
		}


		return res;
	}
};