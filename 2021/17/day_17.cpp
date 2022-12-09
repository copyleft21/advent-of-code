#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

struct Input
{
   int x0, x1;
   int y0, y1;
};

Input input0 {20, 30, -10, -5};
Input input {257, 286, -101, -57};

int part1 (Input& in)
{
    int vy = -(in.y0 + 1);
    return vy * (vy + 1) / 2;
}

int part2 (Input& in)
{
    int dx = in.x1 - in.x0;
    int dy = in.y1 - in.y0;
    int nx = sqrt(2*in.x1);
    int ny = sqrt(-2*in.y0);
    int max_n = max(nx, ny);

    cout << "nx=" << nx << " ny=" << ny << " max_n=" << max_n << endl;
    
    set<pair<int, int>> shoots;
    for (int n = 1; n <= 20*max_n; ++n)
    {
        for (int x=in.x0; x<=in.x1; ++x)
        {
            int nnx = min(n, nx);
            if (0 == ( (x + (nnx-1)*nnx / 2) % nnx) )
            {
                int vx = (x + (nnx-1)*nnx / 2) / nnx;
                for (int y=in.y0; y<=in.y1; ++y)
                {
                    if (0 == ( (y + (n-1)*n / 2) % n) )
                    {
                        int vy = (y + (n-1)*n / 2) / n;
                        shoots.insert({vx,vy});
                    }
                }
            }
        }
    }

    //for (auto& item : shoots)
    //  cout << item.first << "," << item.second << endl;

    return shoots.size();
}

int main()
{
    Input &in = input;

    cout << "Part 1: " << part1(in) << endl;
    cout << "Part 2: " << part2(in) << endl;
    return 0;
}
