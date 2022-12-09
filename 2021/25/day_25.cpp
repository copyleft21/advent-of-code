#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <limits>
#include <map>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

#include <boost/multiprecision/cpp_int.hpp> 

using namespace std;
using namespace boost::multiprecision;

extern const char* input0;
extern const char* input;

void print(const vector<uint256_t>& empty,
           const vector<uint256_t>& east,
           const vector<uint256_t>& south)
{
    cout << "--- EMPTY ---" << endl;
    for (const uint256_t& v : empty) cout << v << endl;
    cout << "--- EAST ---" << endl;
    for (const uint256_t& v : east) cout << v << endl;
    cout << "--- SOUTH ---" << endl;
    for (const uint256_t& v : south) cout << v << endl;
}


uint256_t rol(const uint256_t& n,
              size_t width,
              const uint256_t& mask)
{
  return mask & ((n<<1) | (n>>(width-1)));    
}

uint256_t ror(const uint256_t& n,
              size_t width,
              const uint256_t& mask)
{
  return mask & ((n>>1) | (n<<(width-1)));    
}

void rol(vector<uint256_t>& v,
         size_t width,
         const uint256_t& mask)
{
    for (auto& elem : v) elem = rol(elem, width, mask);
}

void ror(vector<uint256_t>& v,
         size_t width,
         const uint256_t& mask)
{
    for (auto& elem : v) elem = ror(elem, width, mask);
}

void do_and(vector<uint256_t>& v,
            const vector<uint256_t>& op,
            size_t offset=0)
{
    size_t n_lines = v.size();
    for (size_t i = 0; i < n_lines; ++i) v[i] &= op[(i + offset) % n_lines];
}

void do_or(vector<uint256_t>& v,
           const vector<uint256_t>& op,
           size_t offset=0)
{
    size_t n_lines = v.size();
    for (size_t i = 0; i < n_lines; ++i) v[i] |= op[(i + offset) % n_lines];
}

void do_xor(vector<uint256_t>& v,
            const vector<uint256_t>& op,
            size_t offset=0)
{
    size_t n_lines = v.size();
    for (size_t i = 0; i < n_lines; ++i) v[i] ^= op[(i + offset) % n_lines];
}

void move_east(vector<uint256_t>& empty,
               vector<uint256_t>& east,
               size_t width,
               const uint256_t& mask)
{
    auto tmp = empty;
    rol(tmp, width, mask);
    do_and(tmp, east);
    do_xor(east, tmp);
    do_xor(empty, tmp);
    ror(tmp, width, mask);
    do_or(east, tmp);
    do_xor(empty, tmp);
}

void move_south(vector<uint256_t>& empty,
                vector<uint256_t>& south)
{
    auto tmp = south;
    do_and(tmp, empty, 1);
    do_xor(south, tmp);
    do_xor(empty, tmp);
    do_or(south, tmp, empty.size() - 1);
    do_xor(empty, tmp, empty.size() - 1);
}

void step_1(vector<uint256_t>& empty,
            vector<uint256_t>& east,
            vector<uint256_t>& south,
            size_t width,
            const uint256_t& mask)
{
    move_east(empty, east, width, mask);
    // print(empty, east, south);
    move_south(empty, south);
    // print(empty, east, south);
}

void part_1(
    size_t n_bits,
    const vector<uint256_t>& i_empty,
    const vector<uint256_t>& i_east,
    const vector<uint256_t>& i_south)
{
    auto empty = i_empty;
    auto east = i_east;
    auto south = i_south;

    uint256_t mask = 1;
    mask = (mask << n_bits) - 1;
    cout << n_bits << ":" << std::hex << std::showbase << mask << endl;

    // print(empty, east, south);
    auto tmp = empty;
    size_t n_steps = 0;
    do
    {
        ++n_steps;
        tmp = empty;
        step_1(empty, east, south, n_bits, mask);
    } while (tmp != empty);
    cout << "Part 1: " << std::dec << n_steps << endl;
}


void problem(const char* in)
{
    vector<uint256_t> empty;
    vector<uint256_t> east;
    vector<uint256_t> south;
    size_t n_bits = 0;

    istringstream is(in);
    while(!is.eof())
    {
        string s;
        is >> s;
        n_bits = s.size();
        size_t i;
        uint256_t n(1), n_empty=0, n_east=0, n_south=0;
        for (i=0, n=n << (n_bits-1); i<n_bits;++i,n>>=1)
        {
            switch(s[i])
            {
                case '>': n_east |= n; break;
                case 'v': n_south |= n; break;
                default: n_empty |= n; break;
            }
        }
        empty.push_back(n_empty);
        east.push_back(n_east);
        south.push_back(n_south);
    }

    part_1(n_bits, empty, east, south);
}

int main()
{
    // problem("...>>>>...");
    problem(input);
    return 0;
}

/*
const char* input0 = R"INPUT(..........
.>v....v..
.......>..
..........)INPUT";
//*/

//*
const char* input0 = R"INPUT(v...>>.vv>
.vv>>.vv..
>>.>v>...v
>>v>>.>.v.
v>v.vv.v..
>.>>..v...
.vv..>.>v.
v.v..>>v.v
....v..v.>)INPUT";
//*/

const char* input = R"INPUT(v>..v.v>.>..>.......>v>v>v.vvv>..v...vv.>>......v..>...v....>>v...v..v.v...>v..>v>>..>v>.v..>>v...vv.v>..>vvv..>v...>.vv>vv.v>>.....v>v.v.>
>v.>.v.v.....>v>>v..v...>.>..>.>.vvvv..>vv.>.>v>.....v>>v>v.....>.v.>...>....v>......>v>>vv>v......v>.vv.>v.v.v..v.vv>vvvv>..v.>.v...v.>>.>
v.>...>....vv.v>.>.v.v...v.v>...>.vv..>>v>>>..>>.v..vv>.>..>.vv.>vv.v....vvv>.vv.vv.>..>>....>>>.>.>..>.v.v.v...>.v..v.>..>..v.v...v.v>.>>.
.>..>>.>.....vv..vvv...>>>v.>v..v.>.v..>.v..vv..>....>........v.v>v..v>..v>>v>v>v.vvv.v>>vv.vv.>>...vv.>>..>......>v>>>>.v...>..>.....v.v.v
>v>>..>.v........>....>v>.v.....v.v.v...v>..vv.v.>..>....>..v>.v....>>>v>v.v...vvv>v..>.....>>>vv>>vv..v.>v>....>>..>.v>...v.vv.>>v..v>>v.v
..>>v>....>..v>v..v.v..>.....v.>vv....v>....v.v>.>v>....v>.>..>>.vv.>>>..v.v>v..v.v..v>v.>v.>v.>v..>v.>...v...vv>>.>>....vvv....vv>>v..>.vv
..>..>.v>>...>.>>v...>>.v>vv.>>.>v>.v....v>vv.v>>v.vvv......vvv>...vvv>>v..>.vv.>vv..>>..>..>v...>v..v>v.v.vv>.....>.vv>..>>..v>>....>>vvv>
..>.>>v.>>..v.>vv.>.....>.....v..>>.>......>>..v>...v....v..v.v.v..v..>..v...>>>v.....v...>.v>...v>vv.vv>.vv>.vv>.v.vvvvv>vv>..>..>>.v>v..v
..v>.v..v>...>.>.>v.>..>...>>v..v>.......vv.>......>>.v...v.v.v.v..>>>>..>.v..>vv.>.v.vv.>>v>vvvv.v>v>..>>.v..v.>..>>....>v.....>>..v.v>v.>
v>>.v.vvv>.>.>>>vv.vv..>>.>>>vv.v.>.>.>..>>vv>vvv>v>..>.v.v>>vvv>>>vv.v>>>>.v>>.v>>..v>>........>v>.v.v..>>.v>vv....vv>v..vv.>v.>....>v..v.
..v.vvvvv.>vv.v.v>.vv>.>>>>vvv..>>>....v.>..v...>..>.....>vvv>vv........v>>>.>v.>>>v...v..>>v.....v..>.v>.v>v......v>.>.vv....v.vv...v>>.>.
v...>..v.v>...>.v.v.>vv>>v.v.>>.>..vv>>>.......>..v.>v..v.>.>.>..vvv.v.>.>.v.vv>.>.v...>v.....vvv.>v>>>v.v..>v..vv>..>..v..v..>..>.>v>.v.>v
..>v..>.>..>.>>>.v.vv>...v>.>.v.v.vv>v>.>>.....v......>vv>v>.>v.v.v...vv.vv.....>>>>vv>v.v....>...v>>.v>.vv.>.v..v..>v>>.v>...v.v..>..>>..>
>>.v.vv......v>>.vv....v>>.v>>.v..>v>..v>>v..v...v..>.v....>.>.vv>>..vv>>.v..v..>...>vvvv....>v>.>..>..v>>...v>...vv.v>...v....>v...>...vv.
....>.>.v>.v.>...vv>.vvv.>v...v.v...v>.>.>>.>v>..>v..>..>..>.v..v>vv..v.>.v..v>>vv>>.v..v.>v>>>v>..>>v>>.>.>.>>..>>..v.v>.>..v>.>v..v>v.>..
>.v.>v.....vv.>>>>>>.v..v>...v.>.....vv>>v>.>.v.vv..v.v.vvv.>.v.v.>>..>..>..>..v.>..v.v>>..>...vv.>v>vv>.>v>.>..>...v>>>>.>v.v>>>..v....>.>
.>..v..>..v......v...v.>.vv..v..>v.>.....v.v.v.v....vvv>vvv.>..>>.>.vv>v....>...>.vvv.v>v..>.v..>>...v...>v.v.vv..v.v.>..>..>.....>.>..>>..
..vv>...v.>>....>.vvv..v.....>v.....>>v.v.>..v..>>>v...>>.>.vv>......>v...v>.>v.>.v>.vv...>..v.>..v.....v>.vv....>.>v...v.>v>..v>v>.....v.>
v.v.v>..>vvv>..>.vv.>>.>>v>v>..vv>.>vv.v.vv.>.v>vv>vvvv.vv>..>.v>>.>.vv.v...v.vv.v..>vv>..v.v.>..v.>.v>.v....>.>..>v.v.>..vv.vv...v....>>..
..>...v..>v..>.v..v>vv.v.>>v.......v>v.....>...>>.>>....>...>v>>..>vvvv>vv..vv.....vv.>......v>>.>>vv>>>...>>v>>..v>..>>.>.v>vv.>vv.>..>..>
v>..v.vv...v..v.>>..vv.v.v.v.v..v...>....>>>vv>>..>..>.v..v.>.v..>vv.....>>..>.>..v>v.>..>>..v.vvv..>vv.>...v..>v>...>>.>..>>>..vv.>>>vv...
v>.>v......>v.>.>..v>..>..>v.>vv...>..v.v>.v..v.v...>..>.>>v...v.>>.vv>...vv..v>>..>v.>>>v>>.v.>..v.>vv........v>.>vv..>v>>..v..>v.>v>.vv>.
v>..>.v.v.>.>..v>.>>>>>..>.>vv>v.>.v>>.v.vv...>>.>....>...v.>.>v>>.>..>..>vv.>>>v..v>.>v.v>v>vv>.......v>>v.>..vvv.>v>v>v.>...v>.>>.v.v.v.>
v..v>>.v>>.vv.>.....v..v>...v>v.>v.>..>>.v.v.v>......>>...v.v>..>..v.>vvv>..>.>vvv>>....>>>>>.>.>.v>>>>.v......>>>>.vv....>...>.>>....>>v>.
.>.>.vv.....>v.v>v.v.>v...v.vv.>.>.v.v>v>>>.vv..>>.v>vv..>>>.>>>>.v..>vvv....>.v>..>.v>.vv...>>v.>>..v.>...>..vv>..>>>>..vv>v.>.>.>>v>.v...
.v....>..>v......>..>>....>v.v..vv...v...vv...>>..>..vv..>v>.>.vv..v.v.v.>.v>.>>>.>....>v...v>.vv>..vv....>v.....>..>..vv.>>>v.>v.vv..>>>v.
.v>>>..>>.>>>.v>>.>v.v>.v....vv...v..>>..>>v>>..>v>v>..vvv...v>.v.>.>...vv.v>..v>.>......v>.v>>...>.v......>>v.v...v..v.v>.>..>.>.v.>>.vv.v
..vv.vv.>....>..>..vv>v>>v>vv>v.v..v...>.v>v>.....>..v>.>.>>..>..>...v>.>.v...>>..v>.>>v.>vv.v.vvv>>..vv>>.v.>.>vv...v..v.v..v.vv...>>.....
>>>..v>............v>..v.vv..>..>>.v>.>..>....v>...>......v.>.v...v.>..vv......>>>.>...>.v.>v>>v>>.vv..vv>.v.>.>.vv.v>.>..v.....>...v.v..>>
>>......>>v.v.vv..>.>>...>v..>.vvv..>>v...v...v.v......v.v...v.vv....>.>.>v..v.v..v>v.v>v.v>vv>.v.v.....>>.>.v>.>vvv..>vv..>>...v>>.v.>>>>.
v>v..vvvv.v.>....vvvvv.vv>.>v.>.v>.vvv.>..v....vvv..>v>v.v.>>.v>v>.>.......>v....>.....vv.v.v>v>>vv>.v.>>..>..vvvv>.>vv...>>..vv..>.>.v>vv.
.vv..>.>>...........>.v>.v.>v.>>>.....>>>v.v.vv.v....v.v.>..v....v>>.>v>v.v...v>.v.v.vv>.....v>....>..>v>>v.vv..........v...v>...vv..>v>.v.
>...vvv>vv>.v>>....v.v..>v.v..>>.v.>vv.>v.>..v..vvvv..v>vvv......v....>.v.>.v>.>v.vvv.>...>.vvv.>........v>v>v...>>.vv>.>.>v.>v.v.>...>v.>v
>..>>.>..>..>.v>vv>v...>v..v..>v..>.....v.....v..>.v>..>v>.v.>v...v>.v..v.v.....v>.>v>.....v>vvv>>v>.vv..v>>.>.>..>>vv...>vv>>.>v.v>>>>..>.
.v>...>>>.>.>.>..>..v>.v.>..v.>>v....v..v.v.>....>.>....v>.........v>>...>>>.>.v.>>.vv..vvv.>...>.>>>....>vv...v>.v.v>.>>.v..v>.v..>.>>>.v.
>.>..>v..>..vvv>.>.v.>>......>.v>..>>.>.v.>.v.vv....>v.v>...vv.>v.>...>vvv.vvvv.>>>>>v.>v..v>v....>v>...v>>.vvv>...v....>>vv....>>v.>.>.>.>
......v.>........>.v>.v.>>v...>v>...>.>v>..>>>....v.vv..vv>.>>>.v>>...>v...>.v>.>v...>.>vv.vvv>..>.>..vv..vv>.>.>>....>.v>>v>..>v.>>.vv...>
v....v.>.vv.vv...v..v.>v>..>.v..v.>.>.v...v>>..v.v.>.v......v..>...>.>.......v.v...v.vv.>v..v..>vv...>.v.v>v>.>...v....v........>....v.v>..
>>..>>.>..v..v...v>v....>v.>.>..v.>.v>.v>vv>.v.>>vv.v>.>.>>v>.>>>..vv.>>>...v..v.>vv.v...>>>>vv.v>.>..v>.v>..vv>v.>...>.v...v.v>...vv>..v..
v.>....>>..v..v>.>v.v>v>>.v.>v.>v..v...>v.>..>....v>vvv>>.......>v.v.v>>vv.>.....v>v..vvv....>.v.vv...v>>v>..v>.>.v..v..v...>..>.>v.>vv>>.v
..v.>>v..v>v.>v>.v...v.v.v.>v....>v..v..>..>...>..v.v.>.>..>v.v>v>>>v>>v>.....>.>>.v>....>vv>v.v.>>.v>>>.>v...vv..vv>>vv>>.>>>vvv.>>..>v.v.
>v...>....>.>......>>>vv..>vvv..>..>>..>vv>..v.>.v>vv>..v>.v>>.....v>>..>..v...>.vv>vv.v.v>v.>.v..>.v.>.v>>v>..>>>>.v.v>...>.>.>.v.>..v.>v.
>....v.v>>.>.>vv.>...>.vvv>.>.v.>..>.v>>>..v>>v>vvvvvvvv...>..v..v.vvv.>vvv...vvvv..v>>>v>>v>>v>...>vv>v...v>>.>.>.>>v>.>.v>vv....vv..>..>.
..v.v.>.vv>..v...vv..v..v...>.>.>.>>..v.....>........>...v.....v..v>.v.>.>.>v..>>v..v.v.>...>vvv.v..v>.vvv>.>.>>.>vv..v.vv>.vv.v..>.v>...v.
..>...v..v>v>>v>vv....>.....>v...vvvv....vv.v..vv.>.v.>>.>..>v>.>>..>...>..>......>.>.vv.>v>...>>.v>.>.v>........>>>>>>.>.v...v>.>..>.>..v.
.vvv>..v>>....v.....v.v.vv..>v.v>>....v>v..>>>.>....vv.v.v>.>....v>>>.>.v....v.>v..>vv>...>..vv...v.v...>v.>..v.vv..>.v.v>>..>.vv>v...v>.v.
..>>..v..v.v..v>v..v.>v>...v>..>>v.>v.v>v.v..>>v.v...vvvvvv>vvvv...>.>..>>>>.v.v>.v..v>...v..v.>v......v>>>....>vv...v...>vv...>.>>>>>v>.>.
vv>v..>.vvv..>>>>...v>...v>.v>>...>>>.v>>...v>..v..vv.vvv.v>.>>v>..v>.v>v.v..v...v.vv>v......>........>...v>v>...v>.v.>v..>>v...>...>.v.>>>
vv..>>......v.>.>>>.>>>vv>>>.>...v....>...>>vv..v..>>>..v>.v>...>.>v>>vv>...>>>.v..>.v.>...>.v...v.>..v..>v.v..v..v.v.v.v....>>v..>.v.v>>v.
..>>v.vv...v>>v..>v.>v>>..v..>.>.....>.vvv....>>>...v>...>v>vv..>...v....>..v>.v..>.v.>.>.>.>...>v..>..>v>..>>...v>>>v....>..>>..>>.v.....>
..v...>v.>>v.>..>v.v.>>vv..>..>.v.vv.v...v....>v>....v>.>..>>.v.v.v......v.>.v>v>>>.>...>>..vvv.>...v.>..v>.v.vvvv....v.v.>.v.....>...v..v.
...>..v>..vv...>>..v>>>..>..>.>.>vv.>..v...>..>.>.>v...v>..v..vvv.vvv.v........>>>v..v..>.>>.....>v>v.vv.v>v..v>>v>>v.v>.v.>..v..>vv>.v>.>.
v..>v>v...>..>>>>>.....v...>..v>>.>..v>..>>...vv..>>>.>.>vv....>...v.>...>vv>.v.>>..vv......v..>.>vvv..>v>.>>..v..v>>...v>vvv.>>.v..>v.>.>>
..>.>v>>>v.>vv>..v>..>v..v..>..>.v.v.>v>.>.vvv>vv.>.>v.>>v..>>.vv..>v>.>>..v.>vv..>>vv.>>vv>>....>.v..>.....v.>vv..v.vv>>.>.>>>...>.>v..v.v
..>vv....vv....v..>.v..vv..>>vvvv...>.vvv.>v>.v.v.>>.v.v>.>.v.>>>..v...v..>..v...vv.>v>>v>vv...v.v...v.vv.vvv..v.>>....>v>...v.>...v.v>..v.
..v>>...>.....>>v..v>..>.v..>vv.>>>.v>v..v>.v>.>..v.>....>>v.>>v.>..>..v>..>.>>..>.vv.>>...v>vv.v.v.>>.>>>.v.>v....v...>>>>v>...v..>v..>v.>
...>>v.v...>......v...>v.v.>>...v...v>>..>vv....>v....>...>>..>>..>v.>v>>>.v.>..v>>.v.v..>.>>..v.vv......vv.vv.v.v>.v>.v..v>v>>..v.vvv..>>>
.>>.vv>.>...v>vv>...v.>..vv..v..>vv..v.>.>.vv.>vv..>...>vv..>vvv>v>v...>..>vv...>>>.v..>..vvv.......v>.v......v...>.....>..v.v..v....v.v..>
....v>>...>vv>v>>v>..>...v..>...>>v.>vvv.>.>.vvv..v...>.....v.>>..v>vvv>..v...>>......v..>....v.v..vv>>>...vv>..>.>..vv>...vvv...v...v.....
..>v.>....>>...>..>......>.>v..v.>.vv..v..>v..v>vv>>...>v....>.vv>.>.>>>.>......vv..>>>v>>vv....vv..v..>...v.>>......v>v.vv>.>>...v>.v....v
v...v..>>v.....v..>..>v>.>>>.>>v.v.>.v..>v.v.v.v.v>v..>.>...v.>>vvv...vvv.>>>>vvv>.v>..vv>........v..vvv>.>v>.>.v...v>v..>>...>..>>>>>>>vv.
.>.v.v.vv.>vvvv>.v..>.>.v.vv.>...v..v..>vv..v.v...v>......>..v>v>.v.....v...vv>>v.v.............>>.>>......v>>.vvvvv>vvv..v....>v......v>>.
>v..vvv..>...v.>>..v.>.>.vv.v.>v..>vv.v>v...vv>>>.v.>vvv>....v>>>vv..v>.>.>>...v.>...v...>>..vvv....>>.v.v.>..v.>..vv..>.vv>>vvvv>..>.>....
...vv.v.vv..>...>..>>>>>...>......v.>.>..>..vv.v..v.v..>>>>.>v>v.>v>v.>.>>v......v..v>>vv...vv.v>vv.v.>..>v>.>..v>.v....vvv>v.>.>>v.vv.>>.v
>v.....>v>v.>...>.....vvv.>.>....>.v....>..>>v>v>>>vv...vv.>v..vvvv>..v.v.v...vvv.>>>....v....vv....v....>..v.v>v>.v.>.v.v.vv>>..v.vvv>..v.
>..>.vv>..vv>.>v.vv.>.>v.>.v>>>>vvv.>.>v>..>vv.v.>>.v>v.>v...vv..vv.vv..v.>....v>.>v.>v.v>..>..>>.vv>..>v.>>.....>>v.vv...v>.>.>>>v...>>v..
.vv.>..v>>.v>vv.v...v>v.......v...vv.>.>v.>>vv..>v.>.>v.v>..>v.v>.>.vv.v>>..v..>.>>..>...>.v.>vv>>vv.>>.v.v>.>.....v>..>.>.vvvv>>.>v...v..v
...>...>>..>v...>........>v..>..>v...>..v>v.>v>v.>v>>.v...>......>>..vvv>>...vv.>v.>v..v.vv....v>v>v.>...>.>...v.v>.>vv..>>....>>..v>...>>.
>......>..v.>>.>..>.vv....>.>.v.v.>.v..>.....v.>>v..vv.>v.v....v...v>..vv.>>.v.v>.vv>....>v>.v.>..vv..vv..vv.....>...>..vv.>.vv>vv.v>v>>>..
.v>.vv>>vv..vv....v>..>v..>.v.>.>..>.>>v..vvv>....>.>vvvv>v......v.vv>>>.v.>.v..>v>.....vv....vv>>.....>.>>..v...>.v...>.v>.v>.>..>..>v>>v.
..v..>vv..v.vv........v.>....v..vv...>.>.>v..v..>>v>.>v.>v..v..v.v>v..v.vv..v...vv...>v..v..v.>..>>v..v....>v...>>>>.v>v.>v...>v....v......
...>>.v..>vvv>.vv>..vvv..vvv>.....v...>>v..>.>v...vv.>v>.vvv..>.>.....>>...vv>>v>..>.v.v.>>.v.>.v....>>..>.v.v..vv>......vv>.>.v..vv.>....v
v.>>>>v...>>..v>v.>v>..>v.>.>.>.>..v...>>.>v>>.>>.v.v......>v..v...>v.v>.>>..>..>..v..>.v..>v>v.>>....>.>.v.>vv.vv>v.>>>...v.>>..v.>....v>.
v>>v.v..>.....>.vvv>....v>>.....v.vv.>.>>.v>>>..v.v>.>>..v.vv.vv.v....v..>>.>.>.......>..v.>.v.v.v>vv..>vv>.v.v.v.v>v>v...>>.......>vv>v.v>
>vv.vv.>>>..vv.>v>v.>vvv.>.>>>>>.vvv.>..>v.v>v..>.>...v>.....v>..vv...v>...v.v..>.>>v.>.>vvvv>..v...>>..vvv.>.>....vv..>.>v.v>..>vvv.>..>>>
.>v.v>...v.....v.>...v.v>.>v>.>...v..>.>.>.>v>.>...>v...v......>>v>vvv>.>v>.>.vv.>v>v.v>.>v.>..vv.v>v..>.v>..>v.v..>..>v.v.>v.v.>.>vv>.>>.>
.>>.vv.vv>>.vv>......v..>....>>..v.>v.vvv>>v.v..>v.v.>...v>v.>.>v.v.v..v>vv>.>...>>v>..vvv........>v...>>v>>v...>v.>......v..v>>v.v...>v>..
v.>v.>...>..vv......v....>.v..>.>>vv>v..v..v>v.>..>..vv....vv.vv.>.>>.>.vv.....vvvv..v>..>.v.>>>.v>.vv>...vvv>..>....v.v.>..vvvv>.v>...v.vv
..>v.......v>>vv.v......>v>..v.>v.v.>.vv.>..v...>.v>..v>v.>v>>v>.v..v.v.v..v.v>..vv.>v>>.>>v>>.>.>.>>..vv>.>>...>...v>vv.>.....>.>>>>.v..v.
.v>..>v>v.>vv>v>>v>v....>v..v.>v.>...v...v.>...v.v..vv.v..v...v........v>.>vv.>vvv.>.>....>..>>.>>v..v.>>.>>v>...>vv..>v>>v>vv....>.v>v.>.v
..v.>>v.vv...vvvv..>...v.>>....vv...>>vv.v...>..v...v.>.vvvv..vvv..v>v>..v...v....>.>.>vv>..>.>.......v...v.>.v.>.v...v...>v......vv.vv>v.>
v>vv>>.v....v.>....v..v.>.>.>>>v.>.....>..>...v.>..v..v.>>...>.v>v.....v>.v.....v...v...vv.>>.v>>vv..v.>v.v>..>v.v>.>....v.vv..>>....v.....
v>vv..v......>v.>...v.....>vv.>>>>..>.>v.v>...>>>..>vv>..>.>....>.>v>v>...>...vv.>.>...v>>vvvvv>v>..vv>.v.v.>>..>vv>...v>..v>v..>.>v>v>>..v
>>.v>...vv.>>vv..v>>>..>v>.v...>vv......>v...>.>.v.v..v>..v.v..>..vvvv......v..>>..vv.>>>v>.>.>v>>>v>...v...vv..>.v.>..vvv>>vv>v.v.>v>.....
.v..>..v..>.>v.>v.v>..>v>.>v..>>..>.>.>.vv>vvv>.....>...vv>>....>v>...>>..v...v.v..v>v.>>v.vvv.>>.>...v..>>>>.>.v.>>.>v>.>v.v>>vv.>....>vv.
..........>v>vvv..v...>>.>>..v..>>.v..v>...>.v.>..>>>>...vv..vv.vv>>>vv.v.v.>....>.>..v.v>....>.>..>vv.vvv.>....v..>.v>>..v.>>v.>>..>..>>..
.v.>..vv...vv....>v>..>v>v....v.v....>v..v>>vv..>>vv......>..vvv...vv.v>......>>.>v>v.v..v....v.>.v.>.>......v....>.....>v>>....v>v>.v>v..v
v.>>>v..vvv>v.>.>.....v..v>...>v>......>vv>..v...v.>..v.>>>..>>....>..v.v...vvv....>>>>..>>.v.v.....>...>>.v.vvv.>.>>>>..>.v>..>>>>..>v.>vv
..v..v>v.v>>v>..>v.v....>v.v.>>>.>..v....v..>>.v>.....>...vv..>v...v.vv...>.v.>.v....v..>>.vvv>>v..>.>.....>.vv..v..v.>...>....>..>..>vvvv.
>v.v>..>..v.>>.>>..>>>..>v>>....>.>vv..>>v>...vv..>v...>..>.v.>.>v>.>.....>.vv.v.v...>>>vv>>.vv.v......v...v.vv.>>.>>>v..v.>>v...v...v>.>>v
v.vv....v.>>..>....>.v.>.....>.>.vvv.v.....>.>..>.v>..v>.vv.>...>vv...>.>...>.>v.>.>.v..>.v..v..v..vv>v....>v..vv>v>vvv.v>vv..>>v>>v.>v...v
..>..>.>>.>vvv.>v>v>.v...>..v..>v.....v>>....>vv>>>..>.vvv>.v.v.v>v>...>.>.v..v..v.>vv...v.....v>.>.>v>.>>>v>..>....v.>>>v....>>.v..>..v>v.
>>..v.>>>>...vvv..v.vv.......vvv>..>>>.v..v.>v.....>vv>v....>......>..>v>..>vv>v..>v..v....v>>...>.>v..>v.>...v>.>v.>.v>.v.v...vvv>>.v>>>..
.>v.v>v.v......v>...>>v>vv>...v>>v..vv>>v.v..v..v>v>..>.v>v.>...v>..v....v>..>...vv......v..>..vv...>.>>.v.v..vv...>.v>.>..v>vv>>.v>...>>.v
.>.>.>>.>....v>...>...v>.vvv.>..>..v>>v...v>.....v.v..>..>>....v..v..>v>..>>v..>v..v..>>>v..v...>.vv.>vv>vvv.v...v.>v.>.>>>.>>>..vvv>>.>.v>
..>.v...v.>.>.v>v.v.>v..v..v>..vv..v...>vvv>>.v>v.>.>.>vvvvv..>>v.>.>...v.......v>.v..>>..v>.....v>.>.>.>.>.>v..v.v..v.v>>..v>.v....>...v.v
..v..v..>.v>v.v.v..v....v>...>..v>vv..>.>.v>.v>vv>v...vv.v.>>....v>vv...v..>.>v...v.vv>v..v..>v...>.v.v..>..vv>..v>...>..>v...v>.>>.>..v.>>
...v...>.vv...>>v..v.v....v.v>v..v.vvv.....>.........vv..>.v.>v...>...v..v..>>..vv.>.vvv>v...vv>>...v.vvv...vvv.>..>>vv.vvv.>.v.>.>.v>>vv..
.v>>vv.v.v>>>>.>>v.....v>........>..v..>.v>>.>..v>..>v..v>.....>vv>v>v..>>>>...v.vv.>....>.v>>.>v>>>v.>.v....v...>vv..>...>>..>>.>>>v...v>v
.....>>v.v.>>..v>v.vv.v>..>...>>..>v.vvvv.>..>.vvv.>..vv.....>...v>v.v....v....v>v.>>>>.v..>>>>vv.v.vv>v.>>...vv...v...vv>...>>.>>..>v..v.v
....>.v>.v>>v>v>.>>...>>v>..>>.v>v>>..v..v>.v.vv>v.v>v......>>>>v...>.>>...>>....>vv>>>>v..>....v..v>vvv.>....v>.vv..v>.vvv..>v..>.v.v>>...
v.>...>v.>>..>v.v.v.>.>vv>..v>.>.>v>>>>v...>.v>>>>>vv>v.>.vv.....vvv>>.v.>.>>.v...v...>...v>>>v.v>v.>.>vv>.>>v..>>>v.v...>..v>.v.>...vv...v
...v..............v.v..v>>>v>.>....>..>v.>v.v...>>>v.v...>>.>.>.v.v.>>.v.>>....>..>>>v>.v..v>....>.vv..>.>vv>>v.v>..v.>..>vvv..>>...>.>v..v
.v>..>v>>...vv.vvv.>.vvv>>v>.v..>.>...>v..v>.>v>.>v.>....>.vv.v.vvv>..v>..v.v..>v>.v.>....>>v.v.v.>.>>>..v>...>v>>>>.v....vv>>>>v..vvv..v.>
.v>v....>.>>.>....>v>>.>.>..>>>.v.....>.>.v>>.>v....v>...>>.>.>v....>..v>v..v>>.>v..vvv>vv>v...v..vv.v>...>.....>....>>v>>vv..>.v.>vv...vvv
>....v....v>v>v...>.vv...v>.>..>>...>v....vv.v....>v...v..>......v..v>..>v...>vvvv.v.v>v>>vv>.>vv.>>..vvv......>vvv>...>>.v..v.>.>v>...>>vv
.....v>.>.....>v>.v...>>>...vvv.>v.......>>..>..v>..>v..v....v>v.>..v.v...vv>>.......v>>......v...>.>>vv>v..v..>.vvv.>...v>>.>v>..vv..>....
..v........>>..v>>..v>>v>v....v.>..>.>>.>.>..v.>>>>.>>..v.>v>>v>v.>.v..>.vv.>>....>.vv>..v.>>..v>vvvv.v>..>>........v.>>...>>>...>...>v.>.v
>>>vv...>.>.>....>v.v>v>.>v.>....v..>vv...>.>v.>v..>v>v>v.>>>.v..>>..v..v>..v.>.>v>v.v>>v>..v..vv......v.>.>..v>>>v>v.>.v...>v...>vvv..v.>.
....v.>.>.>v.>v..>v>>...>.....>..v>v>>...>..v...v>....>>...v.v.>v>...v...>..vvv..v.>.>>vv.v....>v>.>.>.v>>...>v.>vv.v>.v>v....>.>..>.>v.>>v
>v....>>....>..>..v.v.....>v.v..>.v.....v>>>.>.v>.vvvv.>v.v..>v..>>v.>>vvv...>..>>.vvv....v.v....>.>v..>v....v>>.vv.v>.v..>v.....v.>..v...v
.>v.v.>vv>v....v..vv..v.>..>........v..v>v.>vv...v.v.v.......v>v>.vv..>>..vv>>.>>...>...vv...>vvv..v>.>>....>>.>.>....v...vv.vv>>..>.>....>
.v...v.....v.>....v>>....v>..>>>......>..vvv..v>>.vv>.>vv.v.>.vv>.>>....>v.>.>...vv.>...vv.vvv.......>....v.>v>>>v..>v..v.v.vvv...>.>...>>>
v.>.v>>vv>>...vvvv>>vv>.>v..vv>v>..v....>...>...>>>......vv.v>v..v..v>v.v>v>.v>>....>v.v.>.vv..vv.>>....vv..>..v....v..v>v..v>>.v..v.v>.>v>
vv>v..v>.v..>v.v.v.vv.>v.v.......v.v>v...>..>>>>.vv>..>.>>.v..>vv.v...v..v.v.vv...v...>..v>.>....>>.>>..v.>..v...>v..>>>..>>>v...v>.....v.>
..vv>>>...>.v.v....v.>>v>.>..>v.v.>vvv>v...>.v>..v.....v>v..>v>...v>.v.>..vv......v>v.vv.v>..>v>v>..v..v.>..v..>v.v>>...>...>>..v...>v>..v.
.>>v>v..v>...>v>.>..v>.v....>>v..vv.>vv...>v...>.v...vv.>v..>..v>>.>.v>v.v.v.>v....v...>>v.>..>...>.>vv.v.>>..v>>....v..>>......>>>.>.v...v
vv>....>>>>.>>v...vv...>>.v.v.v..>.v>.v>v>.v.>vv.vv...>>.>.>v...vv...v.>>......vvv>..>..>...>>......>...>>vv..>>>>.........v>v...vv.v>v...>
>...v>.v....>...v>v>v>......v......v>>>.vv..vv>....v.......>.>..>.v>.>.>v.v...v>v>>.>.>.....>>.>>v>..vv..vvv...v>...v....>..v.>v.>>.>v.vv..
v>v.>v.vv>v.>>...v>>.>..v.v.v.vv.v..>v>..>...>>v>.>.>.v>..>>........>....v.>.v.v>.>.v.>.v>.>.vvvvv...>v.>>vv.>..v>...>...v>.v>>v.>.v>vv..v.
v>..v....v.>...>.......>.v.v.>>>..>..v>.>>.>v>vvv..>....v>v.v.v>.........v.v.v>...>>..>.>...>v....v.>vv.......v..>.>>..vvv...v...>v>vvv>.vv
..v.v..vv.>...>v.v>>..>..v.v..>>v.v>>.v>v..vvvv>>.vv...>v.>>....>..>.vv......>.>>>v.>>.>.vv>....v.>.....>v..v.....vvvv.v.....vv..v...v>.v.v
.v..vv..v..>v..v.v>.>..v...>.vv..vv>..>..>.v..>>.vv..v...>>....>.>>.vv..>>.v...v>...>v>.>vv>v>>...vv>>v..v..>..vvv..>>>.>>v>..vv>.>v..>.v.>
>..v..v..v>.v>..vvv..v>.>..v...>>v>v>..vv....v.v>.v..v...>.......v>.>.v.>.vvvv...v..vv.v.v...v.v.>...>..vv>.v.v>vv.vv>>.....>.>v.v.v>>.vv>>
vv.v...v.v.>..v>.>>.v>v>..v...>...>v..>...v..>..v>vv.v>.>>v...v.vvv.>v....>.>v>..>v>vv..>.vv..>.>.v..>.v.>.v...v>>v..>v>vvv...v.>vv........
v.>.>>v.v.>.>.>v>v.v>......>v....vv.vv.>vvv>.>.>...vv..v>..v>...vv>...v...>>v..>...v>>>vv..v>>..v.v>>>vv.>.>>..>.v.vvv>>v>.>.vvvv.v.>.v....
.v..v.>v>.v.v..>vv..>.....v>.>>v..v.v.>.>>vv>>>....v>>.....v>>.>>.>v.>.v>>.>>.v>v.>>..>>...v>...v...>.v...v.v.>>v..>..>v..>>v...v.v.v.vv>.v
.>v>v.>>.v......v..>..v..>.vv..>v....>>..>>v.>v...>v>>.>>.>>v..v.>v...>>..v>>v.....v>>v..vv.>..vv...v>....>>>..v.>v.v.....v>.>>>>...v....v.
.v>.vv..v...>v.>..>....v..v..v.>....v..v.>>..>v..>.......v....>...>.>v...v...vv>v>....v......>.>>.v>>>>>>..>>v>v..vv.....>.>.vv...>v>..>.vv
.v....vv>>..v>.>v.>v.vvv>..v.>....>vv..>vvv>>>v>.>v.>>v..>>v.v..vv..>.v....>v..>vvv>.v.v>.>.>v>vvvv.vv.>.v.>>>>>.v..v.....v...>vv>>..v.>..v
.>vv...v.v..v......v.>>>..vv.>>vv>.vv.v...>v>>...>>v>.....>>>>>...>>>>v.v>vv>v.v>.v.>>v..>>.>>.>>v>.v.v>..>v........v>....>.>.v.v.vv>v.v>>v
.>>.>.v>vv..>v....vv>..>>>v>.>v.v.v.v....v>.>v.v...>....v......>.v.v.>...v..v>.vv>.vv..vv.>...>.v...>.v..v.>>vvv.>v...v...>>.vvv>>.vv.>.v..
.>.vv>v..v.v..v>>>>..v..>....>v>.>.....>..>>v.vv..v>>...>>.v>vvv>...v>v>>>vv.>...v........>..>.>>>..>v>v>v..v>.....>.....vv.>v.v>..vv>..v..
....>v>.vv..v.v>..v..vv>.>.>.v>>v>>..>..>.>..>v.>.>.v.>>vv....>v.>>..v..vv.>.>.>.v..>>v......v>>..>..>..>v.....>v.>.>..>.>v....>.v.v.vv.v.v
.vv.>.>v.v.v>..v..v..v...>>>>.........vv>>..>.....>v>.>.v.....v..v>...>>>>.>>......>>>v.>>>vvv>v>>>..vv..>>.v..>.v>.v.>..v.v.>..v>..>>>.v.>
.>vvvvvv.vvv..>.>.v>v..>>>.....>v..v...vv>v.....>.v>.v.v....vv>>....>.>vvv.>>>.v...vvv.v>.......v.>.>.....v.v.v.v>.v.>.>.>...>..v>>..v.>.>.
v..v>>..v....>v>.v>...vvv.>...v>.vv>vv>v>vv.....v>.>v.>.v..>v.>>..v>>>.>..>v......>>....v...v..>..vv>v.v.v.>>>vv>.>v.>.v.v.>>.>>>>..v...>..)INPUT";
