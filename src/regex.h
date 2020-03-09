#pragma once
#include "pch.h"

#define REGEX

class Regex {
public:
	bool isMatch(string s, string p) {
		if (s.size() == 0) return true;

		if (p.size() == 0) return false;

		if (p == ".*") return true;

		if (p == "." && s.size() > 1) return false;

		if (p == "." && s.size() == 1) return true;

		if (s.find("**") != string::npos) return false;

		if (s.find("*") != string::npos && s.find(".") != string::npos) return false;

		if (p.find("*") == string::npos && p.find(".") == string::npos) return s.compare(p) == 0;

		if (p[0] == '*') return false;

		// check for upper case here!

		bool match(true);
		bool matchPending(true);
		int j = 0;  // for s
		for (int i = 0; i < p.size(); i++) {
			if (p[i + 1] == '*') {
				bool innerMatch(false);
				std::cout << "Wild card char detected at i = " << i + 1 << " and current j = " << j << std::endl;
				// start searching for p[i]
				for (int k = j; k < s.size(); k++) {
					if (s[k] != p[i] && p[i] != '.') {
						if (innerMatch) j = k;
						matchPending = true;
						std::cout << "   Breaking out of innermatch for " << p[i] << " at k = " << k << " and j = " << j << " and i = " << i << std::endl;
						break;
					}
					else {
						std::cout << "   Inner match found for " << s[k] << " at k = " << k << " and j = " << j << " and i = " << i << std::endl;
						innerMatch = true;
						matchPending = false;
						if (k == s.size() - 1) j = k;
					}
				}
				if (i < p.size()) i++;   // to account for *
				std::cout << "    Advancing i value to " << i << std::endl;
			}
			else if (p[i] == '.') {
				std::cout << "Single letter match (.) found at " << i << std::endl;
				j++;
				matchPending = false;
				continue;
			}
			else if (s[j] == p[i]) {
				//j = i;
				//if(j == s.size()) break;
				std::cout << "Direct letter match found for " << s[j] << " at j = " << j << " and i = " << i << std::endl;
				j++;
				if (j == s.size() - 1 && i == p.size() - 1) matchPending = true;
				else matchPending = false;

			}
			else if (s[j] != p[i]) {
				std::cout << "No match found for " << s[j] << " at j = " << j << " and i = " << i << std::endl;
				match = false;
				matchPending = true;
				break;
			}
		}

		if (matchPending) match = false;

		if (j < s.size() - 1) match = false;

		return match;
	}

	int HandleCharMatch(string s, char c, int pos) {
		if (s[pos] == c) return pos + 1;
		return pos;
	}
};