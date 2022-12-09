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

using namespace std;

extern const char* input0;
extern const char* input;

bool is_special(string::const_iterator it)
{
  return *it == '[' || *it == ',' || *it == ']';
}

struct Number
{
    unique_ptr<Number> left, right;
    size_t value = 0;
    bool is_pair = false;

    size_t magnitude() const
    {
        if (is_pair)
            return left->magnitude() * 3 + right->magnitude() * 2;
        return value;
    }
};

void explode_right(string& root, string::iterator it, long v)
{
    for (++it; it != root.end(); ++it)
    {
        if (!is_special(it) )
        {
            break;
        }
    }

    if (it == root.end()) return;

    auto end=it+1;
    for (; end != root.end(); ++end)
    {
        if (is_special(end))
        {
            break;
        }
    }

    string s_vv (it, end);
    long vv = atol(s_vv.c_str());
    char s_v[31]{};
    snprintf(s_v, 31, "%d", v + vv);
    root.replace(it, end, s_v);
}

void explode_left(string& root, string::iterator it, long v)
{
    for (--it; it != root.begin(); --it)
    {
        if (!is_special(it) )
        {
            break;
        }
    }

    if (it == root.begin()) return;

    auto beg=it-1;
    for (; beg != root.begin(); --beg)
    {
        if (is_special(beg))
        {
            break;
        }
    }

    ++beg; ++it;
    string s_vv (beg, it);
    long vv = atol(s_vv.c_str());
    char s_v[31]{};
    snprintf(s_v, 31, "%d", v + vv);
    root.replace(beg, it, s_v);
}
bool explode (string& root)
{
    size_t depth = 0;
    auto it = root.begin();
    while (it != root.end())
    {
        // cout << *it << " d=" << depth << " ";
        if (*it == ']') --depth;
        else if (*it == '[') ++depth;
        else if (*it != ',')
        {
            auto comma_it = find(it+1, root.end(), ',');
            auto close_it = find(it+1, root.end(), ']');
            if (close_it < comma_it)
            {
                it = close_it;
                continue;
            }
            auto second_it = comma_it;
            ++second_it;
            if (*second_it == '[')
            {
                it = second_it;
                continue;
            }
            if (depth <= 4)
            {
                it = close_it;
                continue;
            }

            // EXPLODE
            string s_left(it, comma_it);
            string s_right(second_it, close_it);
            long left = atol(s_left.c_str());
            long right = atol(s_right.c_str());
            // cout << "(EXP) " << left << "," << right << endl;
            --it;
            root.replace(it, close_it+1, "0");
            explode_right(root, it, right);
            explode_left(root, it, left);
            // cout << "EXP: " << root << endl;
            return true;
        }
        ++it;
    }

    return false;
}

bool split (string &root)
{
    auto it = root.begin();
    while (it != root.end())
    {
        if (!is_special(it))
        {
            auto beg = it;
            for (++it; it != root.end(); ++it)
                if (is_special(it)) break;
            if (beg + 1 != it)
            {
               string s_v(beg, it);
               long v = atoi(s_v.c_str());
               long v_left = v >> 1;
               long v_right = (v+1) >> 1;
               ostringstream os;
               os << "[" << v_left << "," << v_right << "]";
               root.replace(beg, it, os.str());
               // cout << "SPL: " << root << endl;
               return true;
            }
        }
        ++it;
    }

    return false;
}

void reduce (string& root)
{
    while (explode(root) || split(root)) {}
}

void add_pair(unique_ptr<Number>& pair, string::const_iterator& pos)
{
    pair->is_pair = true;
    pair->left = make_unique<Number>();
    pair->right = make_unique<Number>();

    ++pos;
    if (*pos == '[')
    {
        add_pair(pair->left, pos);
    }
    else
    {
        pair->left->value = *pos - '0';
        ++pos;
    }

    assert(*pos == ',');
    ++pos;
    
    if (*pos == '[')
    {
        add_pair(pair->right, pos);
    }
    else
    {
        pair->right->value = *pos - '0';
        ++pos;
    }

    assert(*pos == ']');
    ++pos;
}

unique_ptr<Number> read(const string& number)
{
    auto ret_val = make_unique<Number>();
    auto pos = number.begin();
    add_pair(ret_val, pos);

    return ret_val;
}

void problem(const char* in)
{
    istringstream is(in);

    vector<string> lines;

    string line;
    is >> line;
    lines.push_back(line);
    string root = line;

    while (!is.eof())
    {
        is >> line;
        lines.push_back(line);
        root = "[" + root + "," + line + "]";
        reduce(root);
        // cout << root << endl;
    }

    // cout << root << endl;
    auto num = read(root);
    cout << "Part 1: " << num->magnitude() << endl;

    size_t max_magnitude = 0;
    for (auto& num1 : lines)
        for (auto& num2 : lines)
        {
            root = "[" + num1 + "," + num2 + "]";
            reduce(root);
            auto num = read(root);
            auto mag = num->magnitude();
            max_magnitude = max(max_magnitude, mag);
        }
    
    cout << "Part 2: " << max_magnitude << endl;
}

int main()
{
    problem(input);
    return 0;
}

/*
const char* input0 = R"INPUT([[[[4,3],4],4],[7,[[8,4],9]]]
[1,1])INPUT";
//*/
/*
const char* input0 = R"INPUT([[[[7,7],[7,8]],[[9,5],[8,7]]],[[[6,8],[0,8]],[[9,9],[9,0]]]]
[[2,[2,2]],[8,[8,1]]])INPUT";
//*/
//*
const char* input0 = R"INPUT([[[0,[5,8]],[[1,7],[9,6]]],[[4,[1,2]],[[1,4],2]]]
[[[5,[2,8]],4],[5,[[9,9],0]]]
[6,[[[6,2],[5,6]],[[7,6],[4,7]]]]
[[[6,[0,7]],[0,9]],[4,[9,[9,0]]]]
[[[7,[6,4]],[3,[1,3]]],[[[5,5],1],9]]
[[6,[[7,3],[3,2]]],[[[3,8],[5,7]],4]]
[[[[5,4],[7,7]],8],[[8,3],8]]
[[9,3],[[9,9],[6,[4,9]]]]
[[2,[[7,7],7]],[[5,8],[[9,3],[0,2]]]]
[[[[5,2],5],[8,[3,7]]],[[5,[7,5]],[4,4]]])INPUT";
//*/

const char* input = R"INPUT([6,[[5,[7,7]],[[8,2],2]]]
[[8,[0,0]],[[[1,4],[2,0]],[[2,3],[8,2]]]]
[[[7,[6,1]],[9,[7,9]]],[[6,6],2]]
[[5,[2,0]],[[[9,4],[6,8]],[3,9]]]
[[[3,[0,3]],[5,[9,8]]],[[5,[8,1]],[1,2]]]
[[[5,[8,5]],[[6,3],3]],[[1,[0,9]],[[3,0],[7,3]]]]
[[[[1,2],0],[8,[6,6]]],[6,[7,5]]]
[[[[0,9],[5,3]],[[9,7],8]],[9,[[1,9],1]]]
[[4,[6,[0,8]]],[[2,9],1]]
[[[5,1],[6,[9,5]]],8]
[[[4,[7,0]],1],[3,3]]
[2,[[3,4],6]]
[[[[0,5],[7,1]],[[7,0],[1,7]]],2]
[[3,[7,8]],[[1,0],[[1,7],6]]]
[[[7,[6,3]],1],[4,[1,[6,8]]]]
[[[[5,5],[3,5]],[5,[2,6]]],[3,[1,[3,2]]]]
[[8,2],9]
[[8,[[1,9],2]],[[8,[8,4]],3]]
[[[[8,7],9],5],[[[0,6],5],[6,5]]]
[[2,6],[0,[[9,8],6]]]
[[[[7,9],0],[[1,5],9]],[[[2,2],1],[3,1]]]
[[8,[1,[9,1]]],[0,[0,[2,4]]]]
[[[[0,2],3],[[9,4],9]],[[3,2],[[5,7],[4,8]]]]
[[[[8,0],3],[9,[5,9]]],[4,3]]
[2,[7,[[3,3],[7,9]]]]
[3,[[[6,4],0],5]]
[[1,[[9,9],9]],[[[0,3],[0,6]],0]]
[[7,[[2,3],4]],[6,[9,9]]]
[3,5]
[[[[2,3],2],[1,[9,9]]],[[8,2],[1,[2,0]]]]
[[[[7,2],[3,6]],[[9,7],[8,9]]],[[[5,3],[5,1]],6]]
[8,[[7,0],[[8,2],5]]]
[[[1,[1,0]],[[3,7],[4,5]]],[[[6,5],2],1]]
[8,[[5,0],3]]
[[[4,1],9],[1,5]]
[[9,[5,[3,7]]],[[0,4],4]]
[[[[9,6],4],[8,[7,5]]],[[6,9],5]]
[[[7,[2,5]],0],[8,[0,7]]]
[8,[[4,[1,8]],[[8,9],3]]]
[[[[3,7],[7,3]],[[5,3],1]],[[[6,7],[2,7]],[[2,6],[9,0]]]]
[[[9,[5,4]],[[1,7],2]],[[1,0],[[2,6],0]]]
[[[[3,2],[5,3]],[9,[2,0]]],[[7,6],[[8,2],[0,7]]]]
[[[4,0],0],[9,0]]
[[[[9,4],[0,9]],[2,3]],8]
[[2,[8,[6,7]]],[[[6,1],[5,1]],[3,[1,1]]]]
[[6,[[8,2],7]],5]
[[[[7,3],[9,7]],5],[[[0,9],4],[3,[0,3]]]]
[[2,[6,7]],[[[9,0],[6,7]],4]]
[[[[3,1],5],[7,[5,1]]],[[[8,4],9],[[2,7],[4,6]]]]
[[8,8],[[[1,4],[7,3]],[[9,6],5]]]
[[[[3,0],8],[[5,1],[7,8]]],[[[5,0],[2,2]],[[9,0],[0,7]]]]
[[1,1],7]
[[4,3],[[9,[7,3]],[2,3]]]
[[[5,[3,5]],3],7]
[[[5,[3,2]],1],[[[3,2],8],[8,5]]]
[[7,[6,5]],[[[9,8],7],6]]
[[[7,9],0],[3,4]]
[[[[5,6],[7,4]],[4,[1,7]]],[[[8,2],7],[6,[4,5]]]]
[[[[8,5],1],[[7,0],[9,7]]],[[[5,2],3],2]]
[[[[7,3],9],7],[[[8,1],9],3]]
[[[6,5],[4,[6,1]]],7]
[[[[4,0],1],[4,4]],[[1,7],[3,0]]]
[9,[[2,[9,0]],6]]
[[[[0,0],9],2],[9,3]]
[5,[5,[[6,6],[2,6]]]]
[[[[8,2],[8,9]],[[8,4],[8,0]]],[[[9,5],6],4]]
[[[3,[6,1]],[3,[6,9]]],[3,4]]
[[[7,[6,3]],[[6,7],1]],[[1,1],2]]
[[[[1,2],[7,1]],[[7,7],4]],3]
[[[[7,2],4],[[4,7],[2,4]]],[1,[[6,2],4]]]
[4,[[0,4],5]]
[[[4,6],[0,[8,2]]],[[4,[8,7]],[[7,9],0]]]
[[[9,2],[5,2]],7]
[[9,[2,2]],4]
[[[6,2],[[4,3],[3,9]]],[[4,1],[[9,4],4]]]
[[[7,[4,2]],4],[[8,[9,3]],[[9,0],[5,4]]]]
[[[[4,1],[4,6]],[2,[4,5]]],[[1,[1,5]],9]]
[[[[5,2],8],6],[1,[[8,9],4]]]
[[[6,[4,2]],[6,[5,5]]],[0,3]]
[[7,[5,[7,0]]],[[[7,2],0],[[7,3],8]]]
[[3,[[2,3],[2,8]]],[5,7]]
[[[[8,0],[6,4]],[[3,7],3]],[[[7,3],[9,8]],[[8,0],8]]]
[[2,[5,2]],[[[0,9],[4,1]],[[8,8],4]]]
[[[[4,1],[6,5]],[[2,7],[5,8]]],[[[7,1],[2,3]],2]]
[[3,5],2]
[[9,2],[[6,[1,9]],[9,5]]]
[[4,[3,8]],[[4,[0,3]],[1,1]]]
[[[6,[0,7]],[[0,4],[6,1]]],[[8,5],[[5,2],[7,2]]]]
[[[[8,8],[6,3]],[[0,2],[6,5]]],[[[7,6],[5,4]],[4,[7,1]]]]
[[[[7,6],[5,8]],[6,1]],[0,[[0,8],9]]]
[[[6,[2,2]],[5,2]],6]
[[[7,9],[[1,5],8]],2]
[[[3,3],[5,6]],[[3,[3,6]],[2,[5,9]]]]
[[[[0,8],[0,1]],[[8,6],4]],[[0,[1,3]],4]]
[[6,[4,4]],[4,[0,4]]]
[[[3,4],[4,1]],8]
[[0,[[4,6],[5,1]]],[[0,[4,3]],[6,9]]]
[[[0,7],2],[[4,9],[1,6]]]
[[1,0],[[[4,9],9],[[5,4],9]]]
[8,[[[1,4],[5,5]],[1,[0,9]]]])INPUT";