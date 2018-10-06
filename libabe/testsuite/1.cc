#include <libabe.h>
#include <iostream>

int main()
{
    abe::database d;
    abe::file f{abe::make_filename("0")};
    f >> d;
    for (auto& e : d.attr().cont())
        std::cout << e.data() << '\n';
    std::cout << '\n';
    for (auto& e : d.rela().cont())
        std::cout << e.left().data() << ' ' << e.right().data() << ' ' << e.data() << '\n';
    std::cout << '\n';
}
