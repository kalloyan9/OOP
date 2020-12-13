#pragma once
#include <vector>
using std::vector;

#include "BinaryRelation.hpp"//class BinaryRelation <T, U>

template <typename T, typename U>
class KnowledgeBase
{
public:
	KnowledgeBase() = default;
	void add(const string& name, BinaryRelation<T, U>* rel);
	//BinaryRelation<T, U>& kb(const string& name); TODO
	template <typename T, typename U>
	friend inline std::ostream& operator<<(std::ostream& os, KnowledgeBase<T, U>& kb);

private:
	size_t len;
	vector<string> names;
	vector<BinaryRelation<T, U>*> br;
};


template<typename T, typename U>
inline void KnowledgeBase<T, U>::add(const string& name, BinaryRelation<T, U>* rel)
{
	names.push_back(name);
	br.push_back(rel);
	++len;
}

//template<typename T, typename U>
//inline BinaryRelation<T, U>& KnowledgeBase<T, U>::kb(const string& name)
//{
//	for (size_t i = 0; i < len; i++)
//		if (names.at(i) == name)
//			return *br.at(i);
//}

template<typename T, typename U>
inline std::ostream& operator<<(std::ostream& os, KnowledgeBase<T, U>& kb)
{
	for (size_t i = 0; i < kb.len; i++)
		cout << kb.names.at(i) << " " << *(kb.br.at(i));

	return os;
}
