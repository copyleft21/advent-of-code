#include <iostream>
#include <map>
#include <string>

// #define TEST

const std::string input[] =
{
#ifdef TEST
"1=-0-2",
"12111",
"2=0=",
"21",
"2=01",
"111",
"20012",
"112",
"1=-1=",
"1-12",
"12",
"1=",
"122"
#else
"1==02",
"1=--0-2==10",
"10221=-0==-2122==",
"1---=02-112",
"1=01=2=2-1=1=1102",
"1=---220==",
"10",
"12===0",
"1=2020200",
"10--",
"102",
"11-0=0-2",
"1=2-=20-1-=-=20-2112",
"1=-22-2202000-=2=0",
"2-0==122=10000002",
"1=-110-=1-02=1",
"10212-102",
"2--202=2=",
"1=-11=",
"210==-1",
"21-1=002211",
"1-=10-010=020",
"1=2-0002-1=",
"22=0200020--2-",
"10-=22=--1-0",
"21211120=",
"220=1120-222221",
"1020-=01=-1==2",
"1==00-2-210-=-2=2-0",
"2122-",
"2122=2",
"2",
"1===-2",
"220-11=0",
"1021",
"1==2=--12=21-=",
"1==",
"11102=",
"11-02-=1-1=-",
"21=1=2-01=0001=-",
"2--0110022112000=",
"12-2=--11=-021=2-",
"1=01=2",
"210",
"1=121=-=1=-",
"21",
"10==1",
"20220-20-0--0",
"122-=",
"1=1121220-02102-2",
"21=-001110122=0-=",
"1=2-=1",
"12-=122-2110=1021-",
"1=2=2=0=1-===",
"21--21=-0210==",
"1200",
"10=2-222011-0-0=",
"10-==20==",
"1===221",
"12=2-1-2-=020-",
"20=00000010-",
"20-1-02200",
"112-2",
"2122=0-1===2",
"2121-01--10=1-",
"2=0220==0-0",
"10-10111120211",
"1=21=002-002010021",
"1-=1=-",
"1=2000122-0==",
"2=1101=110210-1",
"21-==-01211120",
"1=0==-===0==-21100",
"10-0",
"2=-=02=0",
"2=2",
"2=-2100-=2--01--",
"1110",
"100",
"101=120==20--1",
"1012=01--2-",
"222-0",
"121-1=1221-==00=1-",
"1-20=00=0=",
"110-1010212-01",
"101=2220=000=21=",
"2-",
"1==0-11=1-2=2=0",
"1=-11=1221-10--121",
"2-0=2-1100220--0210",
"1-22-2=",
"10011-=",
"10222-2-20101",
"211",
"112",
"1=-",
"100=2=-0=",
"1=1",
"21-221--22--1",
"1--=1101==02100",
"21-11=-102111",
"1022",
"1=1=211=--",
"10=1-----",
"1-1-",
"222-1-1",
"11=2=-22==2---0-",
"1=-=2-==2=",
"2=2122-",
"10-==112-02-22-02-=",
"202=-0",
"2=",
"2=00=2=211",
"2-1-2====1-=-",
"1=1=1211--="
#endif
};

/*
Decimal result:  -4 -3 -2 -1  0  1  2  3  4
SNAFU   result:  -1 -2 0= 0- 00 01 02 1= 1-
*/

std::map<std::pair<char, char>, std::pair<char, char>> add_table;

void construct_table()
{
    std::string digits("=-012");
    std::string carries("--0000011");
    std::string results("12=-012=-");
    for (int i = -2; i < 3; ++i)
        for (int j = -2 ; j < 3; ++j)
            add_table[{digits[i+2], digits[j+2]}] = {carries[4+i+j], results[4+i+j]};
}

bool add (std::string& accum, const std::string& n, std::string& carry)
{
    bool ret_val = false;

    carry = "0";
    size_t pos_acc = accum.size();
    size_t pos_n = n.size();

    //size_t first = accum.find_first_not_of("0");
    //if (std::string::npos != first) std::cout << accum.substr(first);
    //std::cout << " + " << n << " =" << std::endl;
    while (pos_n > 0)
    {
        pos_n--; pos_acc--;
        auto r = add_table[{accum[pos_acc], n[pos_n]}];
        accum[pos_acc] = r.second;
        ret_val |= r.first != '0';
        carry.insert(0, 1, r.first);
    }

    //std::cout << accum.substr(accum.find_first_not_of("0")) << " + " << carry << std::endl;
    return ret_val;
}

std::string part1()
{
    constexpr size_t work_len = 20 + 115;
    std::string accum(work_len, '0');

    for (const std::string& num : input)
    {
        std::string carry;
        if (add(accum, num, carry))
        {
            std::string n;
            do
            {
                n = carry;
            } while(add(accum, n, carry));
        }
    }

    size_t first = accum.find_first_not_of("0");
    return accum.substr(first);
}

std::string part2()
{
    return "";
}

int main()
{
    construct_table();
    std::cout << "Part 1: " << part1() << std::endl;
    std::cout << "Part 2: " << part2() << std::endl;
    return 0;
}
