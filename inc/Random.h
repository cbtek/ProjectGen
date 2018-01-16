/**
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>

#include "UtilityCommon.hpp"

BEGIN_NAMESPACE_CBTEK_COMMON_UTILITY
/**
 * @brief The Random class provides support for generating integer and floating point
 * random numbers.
 */
class CBTEK_UTILS_DLL Random
{
public:
    /**
     * @brief Constructor that takes in optional seed
     * @param seed optional seed
     */
    Random(unsigned int seed=0xCB1022);

    /**
     * @brief reseed Reseeds the random number generator
     * @param seed Optional seed
     */
    void reseed(unsigned int seed = time(NULL));


    /**
     * @brief random Returns random floating point value between 0 and 1
     * @return
     */
    double random() const;

    /**
     * @brief Returns random integer between min and max(inclusive)
     * @param min The smallest random number to return
     * @param max The largest random number to return
     * @return
     */
    int next(int  min, int max) const;

    /**
     * @brief next Returns random integer between 0 and max(inclusive)
     * @param max The largest random number to return
     * @return
     */
    int next(int  max) const;

    /**
     * @brief next
     * @return
     */
    int next();

    /**
     * @brief generate
     * @param total
     * @param min
     * @param max
     */
    std::vector<int> generate(int total, int min, int max);


    /**
     * @brief generate
     * @param total
     * @param min
     * @param max
     */
    std::vector<int> generateUnique(int total, int min, int max);

private:
    std::vector<int> m_values;
    unsigned int m_seed;
    size_t m_next_value;
};
END_NAMESPACE_CBTEK_COMMON_UTILITY
