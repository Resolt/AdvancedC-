#include <iostream>
#include <algorithm>
#include <vector>

void test(std::string &str)
{
	std::cout << str << std::endl;
}

bool match(std::string &str)
{
	return str.size() == 3;
}

void countStrings(std::vector<std::string> &vstr, bool (*match)(std::string &str), int &count)
{
	// count = std::count_if(vstr.begin(), vstr.end(), match);
	count = 0;
	// for (std::vector<std::string>::iterator it = vstr.begin(); it != vstr.end(); it++)
	// {
	// 	count += match(*it);
	// }
	for(auto &str : vstr)
	{
		count += match(str);
	}
}

int main()
{
	// CREATE VOID POINTER INTENDED FOR FUNCTION
	void (*pTest)(std::string &);

	// SET THE POINTER EQUALS THE TEST FUNCTION
	pTest = test;

	// DECLARE STRING OBJECT - OTHERWISE WE CAN'T PASS IT BY REFERENCE
	std::string what = "WHAT";

	// CALL THE FUNCTION VIA THE FUNCTION POINTER
	pTest(what);

	// DECLARE STRING VECTOR
	std::vector<std::string> vstr{"one", "two", "three", "four", "two", "four", "two", "three"};

	// TEST THAT THE MATCH FUNCTION WORKS
	std::cout << match(vstr[0]) << std::endl;

	// TEST THAT COUNT_IF WORKS
	std::cout << std::count_if(vstr.begin(), vstr.end(), match) << std::endl;

	// TEST THAT OUR COUNTSTRINGS FUNCTION WORKS (WHICH USES A VOID POINTER FOR THE FUNCTION INPUT)
	int res;
	countStrings(vstr, match, res);
	std::cout << res << std::endl;

	// DECLARE A FUNCTION (VOID) POINTER FOR THE COUNTSTRINGS FUNCTION
	void (*pCountStrings)(std::vector<std::string> &, bool (*match)(std::string &str), int &);

	// SET THE POINTER
	pCountStrings = countStrings;

	// TEST THAT THIS MONSTROCITY ACUTALLY WORKS
	int res2;
	pCountStrings(vstr, match, res2);
	std::cout << res2 << std::endl;

	return 0;
}
