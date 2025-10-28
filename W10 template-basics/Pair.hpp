#pragma once

#include <iostream>

using namespace std;

namespace MyNameSpace
{
	template <typename T> // class for typename
	class Pair
	{
		T first;
		T second;

	public:
		Pair(T, T);
		T getFirst();
		T getSecond();
		void setPart(T, T);
		void print(ostream &); // no T
	};

	template <typename T>
	Pair<T>::Pair(T first, T second)
	{
		this->first = first;
		this->second = second;
	}

	template <typename T>
	T Pair<T>::getFirst()
	{
		return first;
	}
	template <typename T>
	T Pair<T>::getSecond()
	{
		return second;
	}

	template <typename T>
	void Pair<T>::setPart(T first, T second)
	{
		this->first = first;
		this->second = second;
	}
	template <typename T>
	void Pair<T>::print(ostream &out) // no T
	{
		out << "Pair: <";
		out << first << ", " << second << ">" << endl; // What if first/second are objects?
													   // operator<<(); stream insertion operator
	}
}