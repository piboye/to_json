#include "to_json.hpp"
#include <stdio.h>

struct A
{
    struct D {
	    int v;
	    DEF_TO_JSON_MEM1(v)
    };
    D a;
    struct B {
        int i;
        std::string name;
        std::vector<std::string> other;
        DEF_TO_JSON_MEM3(i, name, other)
    };

   DEF_TO_JSON_MEM3(a, b, c)
   std::vector<int> b;
   B c;
};

DEF_TO_JSON3(A, a, b, c)

int main(int argc, const char *argv[])
{
    A a;
    a.a.v = 1;
    a.b.push_back(2);
    a.b.push_back(3);
    a.b.push_back(4);
    a.c.i=4;
    a.c.name="dady";
    a.c.other.push_back("hello");
    a.c.other.push_back("world");

    std::string out = to_json(a);
    printf("%s\n", out.c_str());

    return 0;
}
