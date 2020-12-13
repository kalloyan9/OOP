//when declarations and definitions are in one header file
//we use .hpp

//if we separete the declarations and definitons
//we include the declarations' file in the end of the header

#pragma once
#include <iostream> //operator <<
using std::pair;
#include <vector> //std::vector
using std::vector;
#include <string> //std::string
using std::string;

//simple relation
//data class to BinaryRelation
template <typename T, typename U>
class BinaryRelation
{
public:
	BinaryRelation() = default;
	BinaryRelation(vector<pair<T, U>> vec);
	BinaryRelation<T, U>& operator=(const BinaryRelation<T,U>& other);
	//constructor
	void addRel(const T& t, const U& u);
	bool operator()(T t, U u) const;//is (t, u) in r
	template <typename T, typename U>
	friend inline BinaryRelation<U, T> operator!(const BinaryRelation<T, U>& other);//unar operator - must be template
	inline BinaryRelation<T, U> operator+(const BinaryRelation<T, U>& other);//binary operator with the same type
	inline BinaryRelation<T, U> operator^(const BinaryRelation<T, U>& other);
	inline vector<U> operator[](const T& t);
	inline vector<T> operator()(const U& u);
	template <typename T, typename U, typename V>
	friend inline BinaryRelation<T, V> operator* (const BinaryRelation<T, U>& first, const BinaryRelation<U, V>& second);
	vector<T> dom();
	vector<U> ran();
	inline BinaryRelation<T, U>& operator+=(const BinaryRelation<T, U>& rhs);
	template<typename T, typename U>
	friend inline std::istream& operator>>(std::istream& is, BinaryRelation<T, U>& relation);
	template<typename T, typename U>
	friend inline std::ostream& operator<<(std::ostream& os, BinaryRelation<T, U>& relation);
	bool isPartialFunc();
	
private:
	//data
	vector<pair<T, U>> r;

	//helpers
	void copy(const BinaryRelation<T, U>& other);
};



#include "BinaryRelation.ipp" //we include the definition file in the end of the header file