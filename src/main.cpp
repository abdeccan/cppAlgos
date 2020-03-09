// cpp01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include "longestpalindrome.h"
//#include "reshapeMatrix.h"
//#include "zigzag.h"
//#include "reverseint.h"
//#include "str_to_num.h"

#include "regex.h"

int main()
{

#ifdef _LONGESTPALINDROME_TEST_
	DWORD dwStart = GetTickCount();
	LongestPalindromeSubstr lp;
	string s = "rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip";
	string s1 = "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir";
	string s2 = "babad";
	string s3 = "cbba";
	string s4 = "absosba";
	string s5 = "bb";
	string s6 = "sos";

	string l2 = lp.longestPalindrome(s2);
	string l3 = lp.longestPalindrome(s3);
	string l4 = lp.longestPalindrome(s4);
	string l5 = lp.longestPalindrome(s5);
	string l6 = lp.longestPalindrome(s6);
	string l7 = lp.longestPalindrome(s);
	string l1 = lp.longestPalindrome(s1);


	DWORD dwTime = GetTickCount() - dwStart;

#endif	//_LONGESTPALINDROME_TEST_

#ifdef _RESHAPEMATRIX_TEST_
	vector<int> row1 = {1,2};
	vector<int> row2 = { 3,4 };
	vector<vector<int>> nums;
	nums.push_back(row1);
	nums.push_back(row2);

	int r = 1, c = 4;
	ReshapeMatrix rs;
	vector<vector<int>> res = rs.matrixReshape(nums, r, c);
#endif	//_RESHAPEMATRIX_TEST_

#ifdef _ZIGZAGTEST_
	Zigzag z;
	string inStr("HelloWorld");
	string outStr = z.convert(inStr, 3);
	cout << "Outstr " << outStr.c_str() << endl;

	inStr = "PAYPALISHIRING";
	cout << "Outstr " << z.convert(inStr, 3).c_str() << endl;
	cout << "Outstr " << z.convert(inStr, 4).c_str() << endl;

	inStr = "HelloWorlds";
	cout << "Outstr " << z.convert(inStr, 2).c_str() << endl;
#endif//_ZIGZAGTEST_

#ifdef _REVERSEINT_
	reverseint ri;
	int rev= ri.reverse(1563847412);
#endif//_REVERSEINT_

#ifdef STR_TO_NUM
	str_to_num s2n;
	int n = s2n.myAtoi("20000000000000000000");
	n = s2n.myAtoi("  0000000000012345678");
	n = s2n.myAtoi("-42");
	n = s2n.myAtoi("-2147483648");
	n = s2n.myAtoi("2147483648");
	n = s2n.myAtoi("21474836487");
	n = s2n.myAtoi("-2147483650");
	n = s2n.myAtoi("");
	n = s2n.myAtoi("   ");
	n = s2n.myAtoi("abc");
	n = s2n.myAtoi("  123words");
	n = s2n.myAtoi("  w1");
#endif//STR_TO_NUM

#ifdef REGEX
	Regex myRegex;
	bool isMatch = myRegex.isMatch("mississippi", "mis*is*p*.");
	isMatch = myRegex.isMatch("aa", "a*");
	isMatch = myRegex.isMatch("ab", "a*");
	isMatch = myRegex.isMatch("aaa", "ab*ac*a");
	isMatch = myRegex.isMatch("aa", ".");
	isMatch = myRegex.isMatch("bbbba", ".*a*a");
	isMatch = myRegex.isMatch("a", ".*..a*");
#endif//REGEX
}