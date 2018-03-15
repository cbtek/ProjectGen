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

#include "Random.h"

namespace cbtek {
namespace common {
namespace utility {

Random::Random(unsigned int seed)
{
    reseed(seed);    
}

void Random::reseed(unsigned int seed)
{
    m_seed = seed;
    srand(m_seed);
}

double Random::random() const
{

    long m_ix=rand();
    long m_iy=rand();
    long m_iz=rand();
    double m_mx=1/30269.0;
    double m_my=1/30307.0;
    double m_mz=1/30323.0;
    m_ix = fmod(171 * m_ix, 30269);
    m_iy = fmod(172 * m_iy, 20207);
    m_iz = fmod(170 * m_iz, 30323);
    double modValue = ((static_cast<double>(m_ix))* m_mx) +
                       (static_cast<double>(m_iy) * m_my) +
                       (static_cast<double>(m_iz) * m_mz);

    double value = fmod(modValue,1.);

    if (value < 0)
    {
        value *= -1;
    }
    return value;
}

int Random::next(int mn, int mx) const
{
	if (mn==mx)return mn;
    int max=mx;
    int min=mn;
    max++;
    if (min < 0)
    {
        min*=-1;
        max = max + min;
        double rng=random();
        int value = static_cast<int>(((rng*(max))));
        return (value-min);
    }

    double rng=random();
    return static_cast<int>((rng*(max-min))+min);
}

int Random::next(int max) const
{
    return next(0,max);
}

}}}//namespace
