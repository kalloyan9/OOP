#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "BinaryRelation.hpp"
using STRING = string;
using N = int;
#include "KnowledgeBase.hpp"

int main()
{
	//test constructors
	BinaryRelation<N, N> test, test3;
	BinaryRelation<STRING, N> test2;
	test.addRel(2, 3);
	test3.addRel(9, 7);
		
	//test addRel and operator()
	//cout << test(2, 3) << endl;
	//test operator!
	//test operator!
	//BinaryRelation<N, N> _test = !test;
	//cout << _test(3, 2) << endl;
	//BinaryRelation<N, N> testUnion = test + test3;//testing operator+
	//BinaryRelation<N, N> testUnion = test ^ test3;//testing operator^
	//cout << testUnion(9, 7) << " " << testUnion(2, 3) << " " << testUnion(1, 1) << endl;
	//test += test3;//testing operator+=
	//cout << test(9, 7);
	cout << (test += test3) << endl;
	BinaryRelation<string, double> a;
	a.addRel("Levski", 19.14);
	a.addRel("sw", 1999);
	cout << a << endl;

	KnowledgeBase<N, N> kb;
	kb.add("testKB", &test);
	kb.add("testKB3", &test3);
	cout << kb << endl;

	KnowledgeBase<string, double> testA;
	testA.add("godina na suzdavane", &a);
	cout << testA << endl;

	return 0;
}
