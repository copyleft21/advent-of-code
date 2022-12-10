#include <iostream>

struct Cmd
{
   int cycles, v;
};

#define noop },{1,0
#define addx },{2,

const Cmd input[] =
{
// addx 1
{2, 1
addx 4
noop
noop
addx 30
addx -24
addx -1
noop
addx 4
addx 1
addx 5
addx -4
addx 5
addx 4
addx 1
noop
addx 5
addx -1
addx 5
addx 3
noop
addx -38
addx 9
addx -4
noop
addx 3
noop
addx 2
addx 3
noop
addx 2
addx 3
noop
addx 2
addx 3
noop
addx 2
addx -17
addx 22
addx -2
addx 5
addx 2
addx 3
addx -2
addx -36
noop
addx 5
noop
addx 3
noop
addx 2
addx -5
noop
addx 10
addx 3
addx -2
addx 3
addx 2
addx 4
noop
noop
noop
noop
addx 3
noop
noop
addx 7
addx 1
noop
noop
addx -38
addx 39
addx -32
noop
noop
noop
addx 5
addx 2
addx -1
addx 4
noop
addx 5
addx -2
addx 5
addx 2
addx -26
addx 31
addx -2
addx 4
addx 3
addx -18
addx 19
addx -38
addx 7
noop
noop
addx 34
addx -39
addx 8
addx 5
addx 2
addx 10
addx -5
addx -2
addx 5
addx 2
addx 11
addx -6
noop
addx 3
noop
addx 2
addx 3
addx -2
addx -38
noop
noop
noop
addx 5
addx 11
noop
addx -3
noop
noop
noop
addx 2
noop
addx -11
addx 16
noop
addx 3
addx 2
addx 8
noop
noop
noop
noop
noop
addx 4
addx 3
noop
addx -20
noop}

};

#undef addx
#undef noop

int part1()
{
    int cycle = 1;
    int x = 1;
    int result = 0;

    for (const Cmd& cmd : input)
    {
        for (int i = 0; i < cmd.cycles; ++i)
        {
            if ( 0 == ((cycle - 20) % 40))
            {
                result += cycle * x;
            }
            ++cycle;
        }

        x += cmd.v;
        if (cycle > 220) break;
    }

    return result;
}

void part2()
{
    int x = 1;
    int xpos = 0;

    for (const Cmd& cmd : input)
    {
        for (int i = 0; i < cmd.cycles; ++i)
        {
            std::cout << ((abs(x-xpos) <= 1) ? "#" : ".");
            xpos = (xpos + 1) % 40;
            if (xpos == 0) std::cout << std::endl;
        }

        x += cmd.v;
    }
}

int main()
{
    std::cout << "Part 1: " << part1() << std::endl;
    part2();
    return 0;
}
