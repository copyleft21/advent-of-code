#include <array>
#include <iostream>
#include <set>
#include <string>

//#define TEST

#ifdef TEST

static const std::string input[] =
{
"#.######",
"#>>.<^<#",
"#.<..<<#",
"#>v.><>#",
"#<^v^^>#",
"######.#"
};

constexpr size_t SIZE_X = 8;
constexpr size_t SIZE_Y = 6;

#else 

static const std::string input[] =
{
"#.####################################################################################################",
"#<<v<.^<<<v.^v<>v^^vvv<<v<^><<>^^^v^v<^<v^>>.<v<v>^vv>>vvv<^<v>v^.<v^>>>>v<^^<v^v<v>>v^.v><<^vv^<><>>#",
"#<<v^.<^><.<<v<vv<vv><.<^.><>vv>v<>v^^>vv^<<.<^<>.v>vv>v^v>vv<v>.<<^^<.^...<<v^.^.v>>.<<><^v>vv>>v^^<#",
"#>v<vv>^<^>^^^^^>v<v>v.v.v>v^v^<.^^<^>^<>>^v>v<^.v^^v<^>^>^>vvv<>>.^<>^>^>v>.>.<>v..v>>vvv^>>>vv<^vv>#",
"#<<>v^.>v^>>v<^><v>.^v.<^v^<<<>v><>^><>v<.v>^v^><v^<>>vvv^>>>v.v.<^^.^<v<^.<<v^<<<vv<v<<>>v><v>^<^<v>#",
"#>>vv<v>^^^<vv<>^>>>^.<v^<^^>.v>^<>v<<..v<>^v<v>>vvv..v>v<>>^>>^>>^^^<.^^<^>v<.v<^^v^.>^<v><>.^<^^>>.#",
"#<v<><.<><<<^v<v<<v<>.<^>^v>v^.^.<v>vv>v..^><^.<v<<>v<^>>v<>vvv<vv<<><vv<>>^><.v<v<^^v^>v>>v>v^<vv^^<#",
"#>^^v^><<<^.^<v><><v^^^^.^>>>>.^v.v<.<^v>v><>^.>>.^>v>>^>>^>^><^^^<v^^^>v<^>^^<vvv<^v^<>.^vv<^>.^>^^<#",
"#<<vv^^^><<<v.<v>^>v>^^><v<<><<^<<<v>.<v^<<>><>^>>>><v<.^>>>><^<>>v^vv^<.<>.>>.^v>.v^>.>vvvv^v<><v^<<#",
"#>>v>>^<<v.^v.vvvv<>>><>^v<^<>><v<^vv<.v>v>^<v<>>^<>>>^.>^v<>>vv<vvv^<vv.<<.v<<>.>^^<>^<>^v^^^>>>^.^>#",
"#>><>vv>^>>v^>v>^^v.<<^v.<..>>>^^vvvv..^v>^>.<.v<^<<.><.^>.<v><<>.<v^vv><^<<>v^vv^>v<^.^^>^<<^.<<<>.<#",
"#<>v>>v<>>>.v<<v<^^v<>^v<^^<v.>^<^v>vv>^>v<vv><v<v<^>>vv>>>v.<<<><.<><>.<>>^><<^vvvvv^<<<v<vv>>.<<^<.#",
"#><<.>^v<>^.vv^>^><><.<^>>vv^vvv><v><.>^^^v^..><><.vv<^>v.v<vvv><^^v.<>v<.^v<^>>>v<v^<>^>v<v^v>^v><>>#",
"#><v>.>^<<v>>.<<<<vv^<<^v^>vv<^^v><>><<v<^>vv>^^>v^^^<<v.vv<><^>>>>>>>^>^^.>>^.<>^<^<v.^.<v^^>.>>v^<<#",
"#>><<.<^<.<<>vv<>>v<.<><^^>^<>v^<<^^^>^^<<^<>^<<v<^^^.v>v<^v>.<v<.vv>^>><.>^<.>.>>v^><<v<^<^.><.^.^v<#",
"#>v^^v>v><^><<^^^<<vv>>.v>^<>^^>v>^.v>>v^<^v<v^^>vv^v><>^>><^<v.v>v><<<<>v.<.^>^<v.<<<<v^<<<<>>^>v^<>#",
"#<^^v<<^>v.<<>^vv^^<^<v>>vvv^^<>>^v^v..v^v>v.^<^.<<v<>v><.<^<^v<>^>v<vv>v><<.vv^.>^>v..>><<.v<^v^>>^.#",
"#>v^v.v^v><>vv<^v^<v^v<>v<v<<>>..^.<vv^v>v.>^<vv>><^>v>>^^v^vv<^<^>>v^v>^^^><v.>>^^.v.^>><<><.vv.^>>>#",
"#.^>>.<^v.>vvv<v>>^<.v<v<<v^v>v.>.>v<^.<^.v.<.>vvv^vv><.^^v>>>v>^>^vv<<.<^<>>vv.^>vvvvv^><><v^<^v^>v.#",
"#<>v^^^.>^>>>^>v.<^.<<^^<>>v>vv.v.^.><v^<v^v<^>^>><vv>^.^.<^^<<<<v>^.>.<<.>.>^><v.v^.^<><^>^v><.vv^<<#",
"#>>vv^^<v<<v<.>v>^...>vv..^v^>^<>v^^^<<<.>^v>>>>.>^<.v><v><^^^vv>.v^>v.>v^>>><^v<>vv>v>v.^><^v<^^<vv>#",
"#>^<><<.>.>>v>>v<<^^v^.v^>.>>vv^.><<v^<v^>>>vvv<v<.<>^>>>>v>^^^.v^<.v><<v><.<v^<<<^>v^v^^^.>>>^>>v<><#",
"#<^v<^<<^<v^>^^<.<..vvv^^v^^><<.>^v<<vv<<>v<>><<>>v^.<v><>.<^vv<<>>>>^><v<<^v^vv.v.<vv^>^>><<^<<<v^^>#",
"#<v>^><><^^v>><<^>>^>><.>>v<^v>^v.<<v^>^<v>vv^^<<v><vvv>^.<v^v<^v^.^<<^<v>v^v>v.>v<>><v.v.><<^vvv^>.<#",
"#>><.<><>>>v...v<><v>v<^>><vv^<^^<v<v^<v>^.<^v><>>v<v^v>v^>>v<^>v<>.vv<<^^^v<>v<<^><^<v^.<^<^.>v^..><#",
"#><<>^vv.v<<v<<^v.><>^.<.<<<^^.v^<v^<vvv^v^>^>><^<>^>>^>^vv.^>vvvv<^<v.>^<.^vvv<><.^^>>^..v<^^<><<>><#",
"#<.><v<><^.><<.^<^^v^v><>^>.<^>.<v^^^>><^vv^vv<<>v.vv<^.^>^>.>>.<<^v>>^^.vv>vvv<vv>^>>>v^<>v.>.>v<>>.#",
"#<v>>>>^><^v^>^^vvv^<<v<v<<^^><^<vv><v>>v<>v^^>v>.<>v>^>v>>v.>.>>>^^^vv<<<>^><^<><v<^^^^^.<^vvv^<<<.<#",
"#.<v^<>>vv<^v^<v>>v<><.>.^^>^<v^>>v<<.<>v>^^v^v<>vv^^v>v>vvvvv>v^^<<^<><^v<v>>^<<v>>^.^v<^<<<<^v<.<><#",
"#<.^v>^vv^>^v<>>^^v.v<vvv.v<<^.>v><^vv>><.^<><v>..><>>.vv>>>.>v<v><v^..<v<<<^^><v<v<.v^..<v.^v<>>><^>#",
"#>vv.<..>^vv<^><>v>^vv<^.>^.<v^<v>vvv>>><<^v<>^<^v>^v.^v^v^><^><^<v.^vv<>^v>^<<^v^^>^^>^.v<>.<>v>>.^>#",
"#<v^^v<.<<vv.<>v^<^>^.<^<v<v^<<v<v.<^^>^>^v>>.<v.>^v.^v.^><<^>v<v.^vv^.^^>>>^<<>>^^<vv>v.<>^.v>^v.>v>#",
"#<>v>>^^<<>^^>><^vvv^^<<><><vv<vv>v>>>^><^.<v<^.>>v<<<vv.^<<^^><v><^.<><<v>^v^<^><>v..><<...<^.v.^v.>#",
"#>.>^>v><..^<^^^v^v<v><<^.^>.^v^v<^>>v><<.>v^<<^<<>^<.>>>v<.>>v>^^.<<>>^><v..v<vvvvv^v.<<<v..^^>.<^<<#",
"#<v>>.^<..>><>v^^>^^>.^^v^vv<>.<<v>><^<^<.^>^^>^<<.v^<<v^.^>v^^>>>.v><>^^<<><^<vv>^v.<^<v<<vv^v.<<<v<#",
"#.^^^<<v>v^vv^vv^>v^<v<^.v<^^>v^.^^^^>^<<^^>.>^^>^v<.vv>><v^v<vvv^>^>^<^^<v<>.v>^<v.<v^>.<v^.^>v^vv<>#",
"####################################################################################################.#"
};

constexpr size_t SIZE_X = 102;
constexpr size_t SIZE_Y = 37;

#endif

enum ELEM : unsigned int
{
    EMPTY = 0,
    LEFT = 1 << 0,
    RIGHT = 1 << 1,
    UP = 1 << 2,
    DOWN = 1 << 3,
    WALL = 1 << 4
};

using Field = std::array<std::array<unsigned int, SIZE_Y>, SIZE_X>;
using Pos = std::pair<size_t, size_t>;

void init_field(Field& field)
{
    for (size_t x = 0; x < SIZE_X; ++x)
    {
        for (size_t y = 0; y < SIZE_Y; ++y)
        {
            switch (input[y][x])
            {
            case '#': field[x][y] = WALL; break;
            case '<': field[x][y] = LEFT; break;
            case '>': field[x][y] = RIGHT; break;
            case '^': field[x][y] = UP; break;
            case 'v': field[x][y] = DOWN; break;
            default:
            case '.': field[x][y] = EMPTY; break;
            }
        }
    }
}

constexpr size_t left(size_t x)
{
    return ((x-1 + SIZE_X - 3) % (SIZE_X - 2)) + 1;
}

constexpr size_t right(size_t x)
{
    return (x % (SIZE_X - 2)) + 1;
}

constexpr size_t up(size_t y)
{
    return ((y-1 + SIZE_Y - 3) % (SIZE_Y - 2)) + 1;
}

constexpr size_t down(size_t y)
{
    return (y % (SIZE_Y - 2)) + 1;
}

void move_currents(Field& field)
{
    Field next_field{ {EMPTY} };

    for (size_t x = 0; x < SIZE_X; ++x)
    {
        for (size_t y = 0; y < SIZE_Y; ++y)
        {
            unsigned int current = field[x][y];
            if (WALL == current)
            {
                next_field[x][y] = WALL;
            }
            else
            {
                next_field[left(x)][y] |= current & LEFT;
                next_field[right(x)][y] |= current & RIGHT;
                next_field[x][up(y)] |= current & UP;
                next_field[x][down(y)] |= current & DOWN;
            }
        }
    }

    field = next_field;
}

#ifdef DEBUG
void print(const Field& field, const std::set<Pos>& /*positions*/)
{
    std::string dbg_chars = ".<>2^223v2232334#";
    std::cout << std::endl;
    for (size_t y = 0; y < SIZE_Y; ++y)
    {
        for (size_t x = 0; x < SIZE_X; ++x)
        {
            std::cout << dbg_chars[field[x][y]];
        }
        std::cout << std::endl;
    }
}
#else
#define print(field,positions) do {} while(0)
#endif

void explore(const Field& field, std::set<Pos>& positions)
{
    std::set<Pos> old_positions(positions);
    positions.clear();

    for (const Pos& p : old_positions)
    {
        auto [x, y] = p;
        if ((x > 0) && (EMPTY == field[x - 1][y]))
        {
            positions.insert({ x - 1,y });
        }
        if ((x < (SIZE_X - 1)) && (EMPTY == field[x + 1][y]))
        {
            positions.insert({ x + 1,y });
        }
        if ((y > 0) && (EMPTY == field[x][y - 1]))
        {
            positions.insert({ x,y - 1 });
        }
        if ((y < (SIZE_Y - 1)) && (EMPTY == field[x][y + 1]))
        {
            positions.insert({ x,y + 1 });
        }
        if (EMPTY == field[x][y])
        {
            positions.insert({ x,y });
        }
    }
}

size_t traverse(Field& field, const Pos& initial, const Pos& target)
{
    size_t minutes = 0;
    std::set<Pos> positions;
    positions.insert(initial);
    while (!positions.contains(target))
    {
        minutes++;
        move_currents(field);
        explore(field, positions);
        print(field, positions);
    }
    return minutes;
}

size_t part1()
{
    Field field;
    init_field(field);
    return traverse(field, { 1, 0 }, { SIZE_X - 2, SIZE_Y - 1 });
}

size_t part2()
{
    return 0;
}

int main()
{
    std::cout << "Part 1: " << part1() << std::endl;
    std::cout << "Part 2: " << part2() << std::endl;
    return 0;
}
