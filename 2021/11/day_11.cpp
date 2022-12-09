#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

extern const char* input0;
extern const char* input;

size_t inc(string* field, size_t row, size_t col);
size_t flash(string* field, size_t row, size_t col);

size_t inc(string* field, size_t row, size_t col)
{
  ++field[row][col];
  if (field[row][col] > '9')
    return flash(field, row, col);
  return 0;
}

size_t flash(string* field, size_t row, size_t col)
{
    size_t flashes = 1;
    field[row][col] = 0;

    if (row > 0)
    {
        flashes += inc(field, row-1, col);
        if (col > 0)
          flashes += inc(field, row-1, col-1);
        if (col < 9)
          flashes += inc(field, row-1, col+1);
    }
    if (row < 9)
    {
        flashes += inc(field, row+1, col);
        if (col > 0)
          flashes += inc(field, row+1, col-1);
        if (col < 9)
          flashes += inc(field, row+1, col+1);
    }
    if (col > 0)
      flashes += inc(field, row, col-1);
    if (col < 9)
      flashes += inc(field, row, col+1);
    return flashes;
}

size_t step(string* field)
{
    size_t flashes = 0;
    for (size_t row=0; row<10; ++row) {
      for (size_t col=0; col<10; ++col) {
        flashes += inc(field, row, col);
      }
    }
    for (size_t row=0; row<10; ++row) {
      for (size_t col=0; col<10; ++col) {
        if (field[row][col] < '0')
          field[row][col] = '0';
      }
    }
    return flashes;
}

int main()
{
    istringstream is(input);

    string field[10];
    for (size_t i=0; i<10; ++i)
      is >> field[i];

    size_t n_flashes = 0;
    for(size_t turn=1; ; ++turn)
    {
        size_t current = step(field);
        n_flashes += current;
        if (turn == 100)
        {
            cout << "Turn 100 = " << n_flashes << endl;
        }
        if (current == 100)
        {
            cout << "All flash = " << turn << endl;
            break;
        }
    }
    return 0;
}

const char* input0 = R"INPUT(5483143223
2745854711
5264556173
6141336146
6357385478
4167524645
2176841721
6882881134
4846848554
5283751526)INPUT";

const char* input = R"INPUT(8548335644
6576521782
1223677762
1284713113
6125654778
6435726842
5664175556
1445736556
2248473568
6451473526)INPUT";