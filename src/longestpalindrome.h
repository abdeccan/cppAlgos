#pragma once
#include "pch.h"

#define _LONGESTPALINDROME_TEST_


// https://leetcode.com/problems/longest-palindromic-substring/
class LongestPalindromeSubstr {

public:
	// helper method
	int getMaxLen(string s, int left, int right) {
		int len = 0;
		while (right < s.length() && left >= 0 && s[left] == s[right]) {
			len = right - left + 1;
			right++;
			left--;
		}

		return len; // max len of string so far
	}

/*
	NOTES:
	* Brute force computation  "longestPalindrome_BruteForce" works but runs out of time, even with minor optimizations.
	* Need a strategy change - exploring 2n-1 method where pick a pivot character and start expanding right and left char if they are same.
	   *  getMaxLen - use this method twice - once for odd len palindrome & second for even length
	   *  keep tracking the max length and accordingly calculate start and end. Actually may not be needed.
	   *  This approach still is O(n^2) but better than brute force which is O(n^3)
*/
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

		int start = 0, end = 0, len = 1;

		for (int i = 0; i < size; i++) {
			int len1 = getMaxLen(s, i, i);
			int len2 = getMaxLen(s, i, i + 1);

			if (len < max(len1, len2)) {
				len = max(len1, len2);
				std::cout << "i value " << i << " len1 " << len1 << " len2 " << len2 << " max len chosen " << len << std::endl;
				if (len % 2 == 0) {
					start = i - (len - 1) / 2;
					end = i + len / 2;
				}
				else {
					start = i - len / 2;
					end = i + len / 2;
				}
			}
		}
		std::cout << "Start final value " << start << " and end final " << end << " len final " << len << std::endl;
		return s.substr(start, len);
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