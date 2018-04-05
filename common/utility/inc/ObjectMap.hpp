#pragma once

#include <map>
#include <cstdint>

#include "UtilityCommon.hpp"
#include "ObjectList.hpp"

BEG_NAMESPACE_CBTEK_UTILITY

template <typename K,typename V>
class CBTEK_UTILITY_DLL ObjectMap : public std::map<K,V>
{

public:

    ObjectList<K> getKeys() const;

    ObjectList<V> getValues() const;

    void insert(const K & key,const V & value);      

    V getValue(const K & key) const;   

    bool getValueRef(const K & key,V & value) const;

    ObjectMap &  operator<<(const std::pair<K,V> & keyValue);

    bool contains(const K & key);

    bool contains(const K & key)const;

    size_t removeAllWhereValueEquals(const V & value);

    bool removeFirstWhereValueEquals(const V & value);

    V & first();

    V & last();

    K firstKey() const;
    K lastKey() const;

    void iterReset();
    void iterNext();
    bool iterValid();    
    V iterValue();    
    K iterKey();    
    V & iterValueRef();    
    K & iterKeyRef();

    void constIterReset() const;
    void constIterNext() const;
    bool constIterValid() const;
    V constIterValue() const;
    K constIterKey() const;
    V & constIterValueRef() const;
    K & constIterKeyRef() const;

    typedef typename std::map<K,V>::iterator iterator;
    typedef typename std::map<K,V>::const_iterator const_iterator;

private:

    typename std::map<K,V>::iterator m_iter;
    mutable typename std::map<K,V>::const_iterator m_constIter;
};



template <typename K,typename V>
V & ObjectMap<K,V>::first()
{
    this->iterReset();
    return this->iterValueRef();
}

template <typename K,typename V>
ObjectList<K> ObjectMap<K,V>::getKeys() const
{

    ObjectList<K> keys;
    typename std::map<K,V>::const_iterator itStart = this->begin();
    typename std::map<K,V>::const_iterator itEnd = this->end();

    while(itStart!=itEnd)
    {
        keys<<itStart->first;
        ++itStart;
    }
    return keys;
}

template <typename K,typename V>
ObjectList<V> ObjectMap<K,V>::getValues() const
{
   ObjectList<V> values;
   typename std::map<K,V>::const_iterator itStart = this->begin();
   typename std::map<K,V>::const_iterator itEnd = this->end();

   while(itStart!=itEnd)
   {
       values<<itStart->second;
       ++itStart;
   }
   return values;

}

template <typename K,typename V>
void ObjectMap<K,V>::insert(const K & key,const V & value)
{
    std::map<K,V>::insert(std::pair<K,V>(key,value));
}

template <typename K,typename V>
ObjectMap<K,V> &  ObjectMap<K,V>::operator<<(const std::pair<K,V> & keyValue)
{
    this->insert(keyValue);
    return (*this);
}

template <typename K,typename V>
size_t ObjectMap<K,V>::removeAllWhereValueEquals(const V &value)
{
    typename std::map<K,V>::iterator itStart = this->begin();
    typename std::map<K,V>::iterator itEnd = this->end();
    size_t count=0;
    while(itStart!=itEnd)
    {
        if (value==itStart->second)
        {
            this->erase(itStart);
            ++count;
        }
        ++itStart;
    }
    return count;
}

template <typename K,typename V>
K ObjectMap<K,V>::firstKey() const
{
    if (this->size()==0)return K();
    return this->begin()->first;
}

template <typename K,typename V>
K ObjectMap<K,V>::lastKey() const
{
    if (this->size()==0)return K();
    this->rbegin()->first;
}

template <typename K,typename V>
bool ObjectMap<K,V>::removeFirstWhereValueEquals(const V &value)
{
    typename std::map<K,V>::iterator itStart = this->begin();
    typename std::map<K,V>::iterator itEnd = this->end();
    while(itStart!=itEnd)
    {
        if (value==itStart->second)
        {
            this->erase(itStart);
            return true;
        }
        ++itStart;
    }
    return false;
}


template <typename K,typename V>
bool ObjectMap<K,V>::contains(const K & key)
{
    return this->count(key);
}

template <typename K,typename V>
bool ObjectMap<K,V>::contains(const K & key) const
{
    return this->count(key);
}

template <typename K,typename V>
V ObjectMap<K,V>::getValue(const K & key) const
{
    typename std::map<K,V>::const_iterator itStart  = this->find(key);
    if (itStart!=this->end())
    {
        return itStart->second;
    }
    return V();
}

template <typename K,typename V>
bool ObjectMap<K,V>::getValueRef(const K &key,V & value) const
{
    typename std::map<K,V>::const_iterator itStart  = this->find(key);
    if (itStart!=this->end())
    {
        value = itStart->second;
        return true;
    }
    return false;
}

template <typename K,typename V>
void ObjectMap<K,V>::iterReset()
{
    m_iter=this->begin();
}

template <typename K,typename V>
void ObjectMap<K,V>::iterNext()
{
    if (m_iter!=this->end())
    {
        ++m_iter;
    }
}

template <typename K,typename V>
bool ObjectMap<K,V>::iterValid()
{
    return m_iter!=this->end();
}


template <typename K,typename V>
K ObjectMap<K,V>::iterKey()
{
    return m_iter->first;
}

template <typename K,typename V>
K & ObjectMap<K,V>::iterKeyRef()
{
    return m_iter->first;
}

template <typename K,typename V>
V ObjectMap<K,V>::iterValue()
{
    return m_iter->second;
}

template <typename K,typename V>
V & ObjectMap<K,V>::iterValueRef()
{
    return m_iter->second;
}

template <typename K,typename V>
void ObjectMap<K,V>::constIterReset() const
{
    m_constIter=this->cbegin();
}

template <typename K,typename V>
void ObjectMap<K,V>::constIterNext() const
{
    if (m_constIter!=this->cend())
    {
        ++m_constIter;
    }
}

template <typename K,typename V>
bool ObjectMap<K,V>::constIterValid()const
{
    return m_constIter!=this->end();
}


template <typename K,typename V>
K ObjectMap<K,V>::constIterKey()const
{
    return m_constIter->first;
}

template <typename K,typename V>
K & ObjectMap<K,V>::constIterKeyRef()const
{
    return m_constIter->first;
}

template <typename K,typename V>
V ObjectMap<K,V>::constIterValue()const
{
    return m_constIter->second;
}

template <typename K,typename V>
V & ObjectMap<K,V>::constIterValueRef()const
{
    return m_constIter->second;
}

typedef ObjectMap<std::uint64_t,std::uint64_t> UInt64Map;
typedef ObjectMap<std::uint32_t,std::uint32_t> UInt32Map;
typedef ObjectMap<std::uint16_t,std::uint16_t> UInt16Map;
typedef ObjectMap<std::uint8_t,std::uint8_t> UInt8Map;
typedef ObjectMap<std::int64_t,std::int64_t> Int64Map;
typedef ObjectMap<std::int32_t,std::int32_t> Int32Map;
typedef ObjectMap<std::int16_t,std::int16_t> Int16Map;
typedef ObjectMap<std::int8_t,std::int8_t> Int8Map;
typedef ObjectMap<std::string,std::string> StringMap;

END_NAMESPACE_CBTEK_UTILITY