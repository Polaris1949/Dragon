#include "file.h"
#include <fstream>
#include <polaris/byte_stream>

namespace abe
{

file::
file(const std::string& __path)
    : _M_path{__path}
{}

const file&
file::
operator >> (database& __db) const
{
    pol::byte_stream<std::ifstream> __fs;
    __fs.open(this->_M_path, std::ios_base::in);

    if (!__fs.is_open()) return *this;
    __db.clear();

    // Read file header
    {
        char __ch;

        __fs >> __ch;
        if (__ch != 'A') return *this;
        __fs >> __ch;
        if (__ch != 'B') return *this;
        __fs >> __ch;
        if (__ch != 'E') return *this;
        __fs >> __ch;
        if (__ch != '?') return *this;
    }

    // Read attribute configurations
    {
        unsigned int __x;

        while (__fs >> __x)
        {
            if (!__fs || !__x) break;
            __db.attr().insert(__x);
        }
    }

    // Read relation configurations
    {
        unsigned int __l;
        unsigned int __r;
        unsigned int __x;

        while (__fs >> __l >> __r >> __x)
        {
            if (!__fs || !__l || !__r || !__x) break;
            __db.rela().insert({__l, __r, __x});
        }
    }

    __fs.close();
    return *this;
}

const file&
file::
operator << (const database& __db) const
{
    pol::byte_stream<std::ofstream> __fs;
    __fs.open(this->_M_path, std::ios_base::out | std::ios_base::trunc);

    if (!__fs.is_open()) return *this;

    // Write file header
    {
        char __ch;

        __ch = 'A';
        __fs << __ch;
        __ch = 'B';
        __fs << __ch;
        __ch = 'E';
        __fs << __ch;
        __ch = '?';
        __fs << __ch;
    }

    // Write attribute configurations
    {
        for (auto __it{__db.attr().cont().begin()};
                __it != __db.attr().cont().end(); ++__it)
            __fs << __it->data();
        __fs << (unsigned int){0};
    }

    // Read relation configurations
    {
        for (auto __it{__db.rela().cont().begin()};
                __it != __db.rela().cont().end(); ++__it)
            __fs << __it->left() << __it->right() << __it->data();
        __fs << (unsigned int){0};
    }

    __fs.close();
    return *this;
}

file
make_filename(const std::string& __name)
{ return file{__name + '.' + file::ext}; }

}
