#pragma once
#include "pch.h"

// https://leetcode.com/problems/longest-palindromic-substring/
class LongestPalindromeSubstr {

public:

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
		string tmp;
		for (int i = 1; i < size; i++) {
			// pivot
			for (int p = 1; p <= i; p++) {
				if (s[i - p] == s[i + p] && (maxsize < 2 * p + 1)) {
					max = s.substr(i - p, 2 * p + 1);
					maxsize = max.size();
					printf("\n max str found: %s with size: %d", max.c_str(), maxsize);
					continue;
				}
				else if (/* s[i-p] == s[i+p+1] &&*/ s[p] == s[i + p] && (maxsize < 2 * p + 2)) {
					max = s.substr(i - p, 2 * i + 2);
					maxsize = max.size();
					printf("\n max str found: %s with size: %d", max.c_str(), maxsize);
					continue;
				}
				break;
			}
		}


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
class longestpalindrome {
public:
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

	string longestPalindrome_brteuf(string s) {

		int size = s.size();

		if (size == 0)
			return s;

		if (size > 1000) {
			s.clear();
			return s;
		}

		string max;
		int maxSize = 0;
		char *tmp = new char[size + 1];
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
				//if ((strcmp(tmp1.c_str(), tmp2) == 0) && (max.size() < tmp1.size())) {
				if (tmp1 == tmp2 && (max.size() < tmp1.size())) {
					max = tmp1;
					maxSize = max.size();
					//printf("\nmax found so far: %s at i=%d, j =%d", max.c_str(), i, j);
					break;
				}
			}
		}
		delete[] tmp;
		return max;
	}
};