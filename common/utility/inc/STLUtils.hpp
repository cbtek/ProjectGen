#pragma once

#include "UtilityCommon.hpp"

#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <iostream>
#include <ostream>

BEG_NAMESPACE_CBTEK_UTILITY

namespace STLUtils 
{
	/**
	* @brief Writes array of doubles to stream
	* @param[out] out Reference to output stream
	* @param itemArray Pointer to array of doubles
	* @param count Size of array
	* @param precision Number of decimal places to print
	*/
	inline void toStream(std::ostream &out,
				  double *itemArray,
				  size_t count,
				  int prec)
	{
		out << "raw double array : "<<count<<std::endl;

		for (size_t a1=0;a1<count;++a1)
		{

			out.precision(prec);
			out << "    [" <<a1<<"]: "<< std::fixed
				<< itemArray[a1] << std::endl;
		}
	}

	/**
	* @brief Get vector of all map values
	* @param sourceMap Source map
	* @param[out] valuesOut Reference to vector of values
	*/
	template <typename K,typename V>
	inline void getMapValues(const std::map<K,V> &sourceMap,
					  std::vector<V> &valuesOut)
	{
		typename std::map<K,V>::const_iterator itBeg = sourceMap.begin();
		typename std::map<K,V>::const_iterator itEnd = sourceMap.end();

		while (itBeg!=itEnd)
		{
			valuesOut.push_back(itBeg->second);
			++itBeg;
		}
	}

	/**
	* @brief Get vector of all map keys
	* @param sourceMap Source map
	* @param[out] keysOut Reference to vector of keys
	*/
	template <typename K,typename V>
	inline void getMapKeys(const std::map<K,V> &sourceMap,
					std::vector<K> &keysOut)
	{
		typename std::map<K,V>::const_iterator itBeg = sourceMap.begin();
		typename std::map<K,V>::const_iterator itEnd = sourceMap.end();

		while (itBeg!=itEnd)
		{
			keysOut.push_back(itBeg->first);
			++itBeg;
		}
	}

	/**
	* @brief Get vector of all map keys and values
	* @param sourceMap Source map
	* @param keysOut Reference to vector of keys
	* @param[out] valuesOut Reference to vector of values
	*/
	template <typename K,typename V>
	inline void getMapKeysAndValues(const std::map<K,V> &sourceMap,
							 std::vector<K> &keysOut,
							 std::vector<V> &valuesOut)
	{
		typename std::map<K,V>::const_iterator itBeg = sourceMap.begin();
		typename std::map<K,V>::const_iterator itEnd = sourceMap.end();

		while (itBeg!=itEnd)
		{
			keysOut.push_back(itBeg->first);
			valuesOut.push_back(itBeg->second);
			++itBeg;
		}
	}

	/**
	* @brief This function converts all values in a set to a vector of the
	* same type.
	* @param valueSet The set of values to convert into a vector
	* @param[out] vectorOut Reference to the vector to be populated
	*/
	template <typename T>
	inline void toVector(const std::set<T> & valueSet,
				  std::vector<T> & vectorOut)
	{
		typename std::set<T>::iterator itBeg = valueSet.begin();
		typename std::set<T>::iterator itEnd = valueSet.end();

		while(itBeg!=itEnd)
		{
			vectorOut.push_back(*itBeg);
			++itBeg;
		}
	}

	/**
	* @brief This function converts all values in a
	*        list to a vector of the same type
	* @param valueList The list of values to convert into a vector
	* @param[out] vectorOut Reference to the vector to be populated
	*/
	template <typename T>
	inline void toVector(const std::list<T> & valueList,
				  std::vector<T> & vectorOut)
	{

		typename std::list<T>::iterator itBeg = valueList.begin();
		typename std::list<T>::iterator itEnd = valueList.end();

		while (itBeg != itEnd)
		{
			vectorOut.push_back(*itBeg);
			++itBeg;
		}
	}

	/**
	* @brief Writes vector of type (T) to output stream
	* @param[out] out Reference to output stream
	* @param itemVector Vector to write to stream
	*/
	template <typename T>
	inline void toStream(std::ostream & out,
				  const std::vector<T> & itemVector)
	{
		typename std::vector<T>::const_iterator itBeg = itemVector.begin();
		typename std::vector<T>::const_iterator itEnd = itemVector.end();

		size_t count = 0;    
		out <<std::string("vector : ")<<itemVector.size()<<std::endl;
		while (itBeg != itEnd)
		{
			out << std::string("    [")<<count<<std::string("]: ")<<(*itBeg)<<std::endl;
			++itBeg;
			++count;
		}
	}

	/**
	* @brief Writes set of type (T) to output stream
	* @param[out] out Reference to output stream
	* @param itemSet Set to write to stream
	*/
	template <typename T>
	inline void toStream(std::ostream & out,
				  const std::set<T> & itemSet)
	{
		typename std::set<T>::const_iterator itBeg = itemSet.begin();
		typename std::set<T>::const_iterator itEnd = itemSet.end();

		out <<std::string("set : ")<<itemSet.size()<<std::endl;
		size_t count = 0;
		while (itBeg != itEnd)
		{
			out << std::string("    [")<<count<<std::string("]: ")<<(*itBeg)<< std::endl;
			++itBeg;
			++count;
		}
	}

	/**
	* @brief Writes map of type (K,V) to output stream
	* @param[out] out Reference to output stream
	* @param itemMap Map to write to stream
	*/
	template <typename K, typename V>
	inline void toStream(std::ostream & out,
				  const std::map<K,V> & itemMap)
	{
		typename std::map<K,V>::const_iterator itBeg = itemMap.begin();
		typename std::map<K,V>::const_iterator itEnd = itemMap.end();

		out <<std::string("map : ")<<itemMap.size()<<std::endl;
		while (itBeg != itEnd)
		{
			out <<std::string("    [")<<itBeg->first<<std::string("]: ")<<(itBeg->second)<<std::endl;
			++itBeg;
		}
	}

	/**
	* @brief Writes list of type (T) to output stream
	* @param[out] out Reference to output stream
	* @param itemList List to write to stream
	*/
	template <typename T>
	inline void toStream(std::ostream & out,
				  const std::list<T> & itemList)
	{
		typename std::list<T>::const_iterator itBeg = itemList.begin();
		typename std::list<T>::const_iterator itEnd = itemList.end();

		out <<std::string("list : ")<<itemList.size()<<std::endl;
		size_t count = 0;
		while (itBeg != itEnd)
		{
			out << std::string("    [")<<count<<std::string("]: ")<<(*itBeg)<<std::endl;
			++itBeg;
			++count;
		}
	}
}

END_NAMESPACE_CBTEK_UTILITY
//end namespace
