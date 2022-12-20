#include <deque>
#include <iostream>

#define N_LINES 41
#define N_COLUMNS 77

#define START_X 0
#define START_Y 20

#define END_X 52
#define END_Y 20

static const char* input[N_LINES] =
{
"abccccccccaaaaaaaccaaaaaaaaaaaaaaaaccccccccccccccccccccccccccccccccccccaaaaaa",
"abccccccccaaaaaaaccaaaaaaaaaaaaaaaaccccccccccccccccccccccccccccccccccccaaaaaa",
"abccccccccccaaaaaaccaaaaaaaaaaaaaaaaccccccccccccccccacccccccccccccccccccaaaaa",
"abcccccaaaacaaaaaaccaaaaaaaaaaaaaaaaacccccccccccccccaaaccccaccccccccccccccaaa",
"abccccaaaaacaaccccccaaaaaacaaacaacaaaaaaacccccccccccaaaacccaacccccccccccccaaa",
"abaaccaaaaaaccccaaacaaaacacaaacaaccaaaaaacccccccccccaklaccccccccccccccccccaac",
"abaaccaaaaaaccaaaaaacccccccaaacccaaaaaaaccccccccccckkkllllccccccccccccccccccc",
"abaaccaaaaaaccaaaaaacccccccaaaaacaaaaaaacccccccccckkkklllllcccccccaaaccaccccc",
"abacccccaacccccaaaaacccccccaaaaaccaaaaaaacccccccckkkkpppllllccccccaaaaaaccccc",
"abacccccccccccaaaaacccccccccaaaacccaaaaaaccccccckkkkpppppplllccccddddaaaccccc",
"abccccccccccccaaaaaccccccccccaaaccaaaccccccccccckkkppppppppllllldddddddaccccc",
"abccacccccccccccccccccccccccccccccaaccccccccccckkkopppupppplllmmmmdddddaacccc",
"abccaaacaaaccccccccccccccccccccaaaaaaaaccccccckkkkopuuuuupppllmmmmmmddddacccc",
"abccaaaaaaaccccccccccccccccccccaaaaaaaacccccjjkkkooouuuuuuppqqqqqmmmmddddcccc",
"abccaaaaaacccccccccccccccaaccccccaaaacccccjjjjjjoooouuxuuuppqqqqqqmmmmdddcccc",
"abcaaaaaaaacccccccccccccaaacccccaaaaaccccjjjjoooooouuuxxuuvvvvvqqqqmmmdddcccc",
"abaaaaaaaaaacccccccaaaaaaacaacccaacaaacccjjjooooouuuuxxxxvvvvvvvqqqmmmdddcccc",
"abaaaaaaaaaacccaaacaaaaaaaaaacccacccaaccjjjooootttuuuxxxyyvyyvvvqqqmmmeeecccc",
"abcccaaacaaacccaaaaaaacaaaaaccccccccccccjjjooottttxxxxxxyyyyyyvvqqqmmmeeccccc",
"abcccaaacccccccaaaaaacaaaaaccccaaccaacccjjjnnntttxxxxxxxyyyyyvvvqqqnneeeccccc",
"abccccaacccccccaaaaaaaaacaaacccaaaaaacccjjjnnntttxxxzzzzzyyyyvvqqqnnneeeccccc",
"abcccccccccccccaaaaaaaaacaaccccaaaaaccccjjjnnnttttxxxxyyyyyvvvrrrnnneeecccccc",
"abcccaacccccccaaaaaaaaaccccccccaaaaaacccciiinnnttttxxxyyyyywvvrrrnnneeecccccc",
"abcccaaaaaaccaaaaaaaacccccccccaaaaaaaaccciiiinnnttttxyyywyyywvrrrnnneeecccccc",
"abcccaaaaaaccaaaaaaaacccccccccaaaaaaaacccciiinnnntttxwywwyyywwwrrnnneeecccccc",
"abcaaaaaaaccaaaaaaaaaccccccccccccaacccccccciiinnnttwwwwwwwwwwwwrrnnneeecccccc",
"abcaaaaaaaccaaaaaacccccccccccccccaaccccccaaiiiinnttwwwwwwwwwwwrrrnnnffecccccc",
"abcccaaaaaaccaaaaaccccccccccccccccccccaaaaaciiinnssswwwssssrwwrrrnnnfffcccccc",
"abaacaaccaaccaaaccccccccaacccccccccccccaaaaaiiinnssssssssssrrrrrronnfffcccccc",
"abaccaaccaacccccccccaaacaacccccccccccccaaaaaiiimmmssssssmoosrrrrooonffaaacccc",
"abaaaccccaaaaaaccccccaaaaaccccccccccccaaaaaccihmmmmsssmmmoooooooooofffaaacccc",
"abaaaccccaaaaaacccccccaaaaaacccccccccccccaacchhhmmmmmmmmmoooooooooffffaaccccc",
"abaacccaaaaaaaccccccaaaaaaaaccccaaccccccccccchhhhmmmmmmmgggggooofffffaaaccccc",
"abaacccaaaaaaaccccccaaaaaaaccccaaaaccccccccccchhhhmmmmhggggggggfffffaaaaccccc",
"abccccccaaaaaaacccccaacaaaaacccaaaaccccccccccchhhhhhhhggggggggggfffaacaaccccc",
"abccaacccaaaaaaccccccccaaaaaccaaaaacccccccccccchhhhhhhggaaaaaaccccccccccccccc",
"abccaaaccaaccccccccccccccaaaaaaaaaccccccccccccccchhhhaaaccaaaacccccccccccccaa",
"abaaaaaaaccccccccccccccccaaaaaaaaccccccccccccccccccccaaaccccaaccccccccccccaaa",
"abaaaaaaaccccccccaaaccccacaaaaaacccccccccccccccccccccaaaccccccccccccccccccaaa",
"abaaaaaacccccccaaaaacaaaaaaaaaaacccccccccccccccccccccaaccccccccccccccccaaaaaa",
"abaaaaaacccccccaaaaaaaaaaaaaaaaaaacccccccccccccccccccccccccccccccccccccaaaaaa",
};

struct Point {size_t x,y,cost;};

bool can_move(size_t x, size_t y, const Point& p)
{
    return input[y][x] >= input[p.y][p.x] - 1;
}

template<typename EndCondition>
size_t traversal(EndCondition f)
{
    size_t distance[N_COLUMNS][N_LINES];
    bool finished[N_COLUMNS][N_LINES];

    for (size_t i = 0; i < N_COLUMNS; ++i)
    {
        for (size_t j = 0; j < N_LINES; ++j)
        {
           distance[i][j] = N_LINES * N_COLUMNS;
           finished[i][j] = false;
        }
    }

    distance[END_X][END_Y] = 0;
    std::deque<Point> nodes;
    nodes.emplace_back(END_X,END_Y,0);

    while(!nodes.empty())
    {
        Point p = nodes.front();
        nodes.pop_front();

        if (f(p))
            return distance[p.x][p.y];

        finished[p.x][p.y] = true;
        // std::cout << std::endl << "(" << p.x << "," << p.y << "," << p.cost << ") ";
        p.cost++;

        auto evaluate = [&] (size_t x, size_t y)
        {
            if (!finished[x][y] && can_move(x, y, p) && distance[x][y] > p.cost)
            {
                distance[x][y] = p.cost;
                nodes.emplace_back(x,y,p.cost);
            }
        };
        if (p.x > 0) evaluate(p.x-1, p.y);
        if (p.y > 0) evaluate(p.x, p.y-1);
        if (p.x < (N_COLUMNS-1)) evaluate(p.x+1, p.y);
        if (p.y < (N_LINES-1)) evaluate(p.x, p.y+1);
    }

    return 0;
}

size_t part1()
{
    return traversal([](const Point& p){return p.x == START_X && p.y == START_Y;});
}

size_t part2()
{
    return traversal([](const Point& p){return input[p.y][p.x] == 'a';});
}

int main()
{
    std::cout << "Part 1: " << part1() << std::endl;
    std::cout << "Part 2: " << part2() << std::endl;
    return 0;
}
