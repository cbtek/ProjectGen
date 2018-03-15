/*
    RangeBasedIterator.hpp    
*/
#pragma once
#include <string>

#include "UtilityCommon.hpp"

BEG_NAMESPACE_CBTEK_UTILITY
template <typename Value, typename ValueContainer>
class CBTEK_UTILITY_DLL RangeBasedIterator
{
public:
    RangeBasedIterator(const ValueContainer& container, size_t index = 0)
                : m_container(container),
                  m_index(index)
        {}

    // Required
    bool operator!=(const RangeBasedIterator& other)
    {
        return (m_index != other.m_index);
    }

    // Required
    const RangeBasedIterator& operator++()
    {
        m_index++;
        return *this;
    }

    // Required
    const Value& operator*() const
    {
        return m_container[m_index];
    }
private:
    const ValueContainer& m_container;
    size_t m_index;
};
END_NAMESPACE_CBTEK_UTILITY
