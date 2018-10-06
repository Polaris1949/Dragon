#include <libabe.h>

int main()
{
    abe::database d;
    d.attr().insert(7);
    d.attr().insert(2);
    d.rela().insert({2, 7, 1});
    abe::file f{abe::make_filename("0")};
    f << d;
}
