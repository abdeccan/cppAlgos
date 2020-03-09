#pragma once
#include "pch.h"

#define INT_TO_ROMAN

class IntToRoman {
public:
	inline void printQ(deque<int> myQ) {
		deque<int>::const_iterator it = myQ.begin();
		cout << "Printing Q " << endl;
		for (; it != myQ.end(); it++) {
			cout << "   " << myQ.front();
			myQ.pop_front();
		}
		cout << "   " << endl;
	}

	inline const char *base(int num) {
		switch (num) {

		case 1: return "I";
		case 2: return "II";
		case 3: return "III";
		case 4: return "IV";
		case 5: return "V";
		case 6: return "VI";
		case 7: return "VII";
		case 8: return "VIII";
		case 9: return "IX";
		case 10: return "X";
		case 20: return "XX";
		case 30: return "XXX";
		case 40: return "XL";
		case 50: return "L";
		case 60: return "LX";
		case 70: return "LXX";
		case 80: return "LXXX";
		case 90: return "XC";
		case 100: return "C";
		case 200: return "CC";
		case 300: return "CCC";
		case 400: return "CD";
		case 500: return "D";
		case 600: return "DC";
		case 700: return "DCC";
		case 800: return "DCCC";
		case 900: return "CM";
		case 1000: return "M";
		case 2000: return "MM";
		case 3000: return "MMM";
		default: return "";
		}
	}

	string intToRoman(int num) {

		string s;

		if (num < 1) return s;

		string tmpS = base(num);
		if (!tmpS.empty()) {
			//cout << "base returned " << tmpS << endl;
			return tmpS;
		}

		int tmp = 0, i = 0;
		deque<int> myQ;
		int factors[] = { 1000, 900, 500, 100, 90, 50, 10, 1 };

		while (num > 0 && i < sizeof(factors) / sizeof(int)) {
			tmp = num / factors[i];
			if (tmp > 0) {
				myQ.push_back(tmp * factors[i]);
				num = num % factors[i];
			}
			i++;
		}

		// printQ(myQ);

		deque<int>::const_iterator it = myQ.begin();
		for (; it != myQ.end(); it++) {
			//cout << "checking for " << myQ.front() << endl;
			s += intToRoman(myQ.front());
			myQ.pop_front();
		}


		return s;

	}

};