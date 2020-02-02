#pragma once
#include "pch.h"

#define _LONGESTPALINDROME_TEST_


// https://leetcode.com/problems/longest-palindromic-substring/
class LongestPalindromeSubstr {

public:
	string getmaxlen(string s, int left, int right) {
		
		while (s[right] == s[left]) {			
			if (left == 0 || right > s.size())
				break;
			right++;
			left--;
		};
		return s.substr(left, right- left + 1);
	}
	
	string longestPalindrome(string s) {

		int size = s.size();
		if (size == 0 || size == 1)
			return s;

		if (size == 2 && s[0] != s[1])
			return s.substr(0, 1);

		if (size > 1000) {
			s.clear();
			return s;
		}

		string max;
		int maxsize = 0;
		string tmp1, tmp2 ,tmp;
		//int len = 0, len1 = 0, len2 = 0;
		//int right = 0, left = 0;
		for (int i = 1; i < size; i++) {
			tmp1 = getmaxlen(s, i, i);
			tmp2 = getmaxlen(s, i, i + 1);
			tmp = tmp1 > tmp2 ? tmp1 : tmp2;
		}

		max = tmp;


		return max;
	}

	inline char * reverse(char *s) {
		if (s == nullptr) return s;

		int size = strlen(s);
		char *p1 = s;
		char *p2 = s + size - 1;
		while (p1 < p2) {
			char t = *p1;
			*p1++ = *p2;
			*p2-- = t;
		}
		return s;
	}

	string longestPalindrome_BruteForce(string s) {

		int size = s.size();

		if (size == 0)
			return s;

		if (size > 1000) {
			s.clear();
			return s;
		}

		string max;
		int maxSize = 0;
		// char *tmp = new char[size + 1];
		 //memset(tmp, 0, size);
		for (int i = 0; i < size; i++) {

			for (int j = size; j > maxSize; j--) {

				if (i + j > size) continue;

				string tmp1 = s.substr(i, j);
				//string tmp2(tmp1.rbegin(), tmp1.rend());
				string tmp2 = tmp1;
				std::reverse(tmp1.begin(), tmp1.end());
				// memset(tmp, 0, size+1);
				 //strcpy(tmp, tmp1.c_str());
				 //char *tmp2 = reverse(tmp);
				 //printf("\n\tafter reverse, tmp1 = %s, tmp2 = %s", tmp1.c_str(), tmp2);
				 //if((strcmp(tmp1.c_str(), tmp2) == 0) && (max.size() < tmp1.size())) {
				if (tmp1 == tmp2 && (maxSize < tmp1.size())) {
					max = tmp1;
					maxSize = max.size();
					//printf("\nmax found so far: %s at i=%d, j =%d", max.c_str(), i, j);
					break;
				}
			}
		}
		// delete[] tmp;
		return max;
	}
};