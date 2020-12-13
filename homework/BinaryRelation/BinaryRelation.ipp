#include "BinaryRelation.hpp"
//definition file for template classes must be something different of .cpp
//we usually use .ipp files
//the compile doesnt know for this file
//linker do the job
//thats why its hard to see the mistakes
//and we must test each function in main func

template<typename T, typename U>
inline BinaryRelation<T, U>::BinaryRelation(vector<pair<T, U>> vec)
	:r(vec)
{}

template<typename T, typename U>
inline BinaryRelation<T, U>& BinaryRelation<T, U>::operator=(const BinaryRelation<T,U>& other)
{
	if (this != &other)
		copy(other);

	return *this;
}

//definitions
//BinaryRelation
template<typename T, typename U>
inline void BinaryRelation<T, U>::addRel(const T& t, const U& u)
{
	r.push_back(pair<T, U>{t, u});
}

template<typename T, typename U>
inline bool BinaryRelation<T, U>::operator()(T t, U u) const
{
	pair<T, U> newRel{ t, u };
	for (size_t i = 0; i < r.size(); ++i)
		if (newRel == r.at(i))
			return true;

	return false;
}

template<typename T, typename U>
inline BinaryRelation<T, U> BinaryRelation<T, U>::operator+(const BinaryRelation<T, U>& other)
{
	vector<pair<T, U>> vec = this->r;
	for (size_t i = 0; i < other.r.size(); ++i)
		vec.push_back(other.r.at(i));
	
	return BinaryRelation<T, U>(vec);
}

template<typename T, typename U>
inline BinaryRelation<T, U> BinaryRelation<T, U>::operator^(const BinaryRelation<T, U>& other)
{
	vector<pair<T, U>> vec = this->r;
	for (size_t i = 0; i < other.r.size(); ++i)
		if (!other(other.r.at(i).first, other.r.at(i).second))
			vec.push_back(other.r.at(i));

	return BinaryRelation<T, U>(vec);
}

template<typename T, typename U>
inline vector<U> BinaryRelation<T, U>::operator[](const T& t)
{
	vector<U> vec;
	for (size_t i = 0; i < this->r.size(); ++i)
		if (this->r.at(i).first == t)
			vec.push_back(this->r.at(i).second);

	return vector<U>(vec);
}

template<typename T, typename U>
inline vector<T> BinaryRelation<T, U>::operator()(const U& u)
{
	vector<T> vec;
	for (size_t i = 0; i < this->r.size(); ++i)
		if (this->r.at(i).second == u)
			vec.push_back(this->r.at(i).first);

	return vector<T>(vec);
}

template<typename T, typename U>
inline vector<T> BinaryRelation<T, U>::dom()
{
	vector<T> t;
	for (size_t i = 0; i < this->r.size(); i++)
		t.push_back(this->r.at(i).first);

	return vector<T>(t);
}

template<typename T, typename U>
inline vector<U> BinaryRelation<T, U>::ran()
{
	vector<T> u;
	for (size_t i = 0; i < this->r.size(); i++)
		u.push_back(this->r.at(i).second);

	return vector<U>(u);
}

template<typename T, typename U>
inline BinaryRelation<T, U>& BinaryRelation<T, U>::operator+=(const BinaryRelation<T, U>& rhs)
{
	for (size_t i = 0; i < rhs.r.size(); ++i)
		this->r.push_back(rhs.r.at(i));

	return *this;
}

template<typename T, typename U>
inline bool BinaryRelation<T, U>::isPartialFunc()
{
	const int N = this->r.size();
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = i+1; j < N; j++)
		{
			if (this->r.at(i).first == this->r.at(j).first)
				return false;
		}
	}
	return true;
}

template<typename T, typename U>
inline void BinaryRelation<T, U>::copy(const BinaryRelation<T, U>& other)
{
	this->r = other.r;
}

template<typename T, typename U>
inline BinaryRelation<U, T> operator!(const BinaryRelation<T, U>& other)
{
	vector<pair<U, T>>vec;
	for (size_t i = 0; i < other.r.size(); i++)
		vec.push_back({ other.r.at(i).second, other.r.at(i).first });

	return BinaryRelation<U, T>(vec);
}

template<typename T, typename U, typename V>
inline BinaryRelation<T, V> operator*(const BinaryRelation<T, U>& first, const BinaryRelation<U, V>& second)
{
	vector<pair<T, V>> vec;
	pair<T, V> p;
	for(size_t i=0; i < first.r.size(); ++i)
		for(size_t j=0; j < second.r.size(); ++j)
			if (first.r.at(i).second == second.r.at(i).first)
			{
				p.first = first.r.at(i).first;
				p.second = second.r.at(i).second;
				vec.push_back(p);
			}

	return BinaryRelation<T, V>(vec);
}

using std::cin;
using std::cout;

template<typename T, typename U>
inline std::istream& operator>>(std::istream& is, BinaryRelation<T, U>& relation)
{
	size_t n;
	cin >> n;
	pair<T, U> p;
	for (size_t i = 0; i < n; i++)
	{
		cin >> p.first >> p.second;
		relation.r.push_back(p);
	}
	return is;
}

template<typename T, typename U>
inline std::ostream& operator<<(std::ostream& os, BinaryRelation<T, U>& relation)
{
	cout << "{";
	for (size_t i = 0; i < relation.r.size(); i++)
	{
		cout << "(" << relation.r.at(i).first << ", " << relation.r.at(i).second << ")";
		if (i < relation.r.size() - 1)
			cout << ", ";
	}
	cout << "}";
	return os;
}
