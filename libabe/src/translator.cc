#include "translator.h"
#include <string_view>

namespace abe
{

attr_translator::
attr_translator()
    : _M_sep{" + "}, _M_data{}
{}

std::vector<std::pair<basic_attribute, std::string>>&
attr_translator::
cont()
{ return this->_M_data; }

const std::vector<std::pair<basic_attribute, std::string>>&
attr_translator::
cont() const
{ return this->_M_data; }

std::string&
attr_translator::
separator()
{ return this->_M_sep; }

const std::string&
attr_translator::
separator() const
{ return this->_M_sep; }

attribute
attr_translator::
from(const std::string& __s) const
{
    std::string::size_type __i{}, __j{};
    attribute __a;

    while (true)
    {
        if (!__i && __j == std::string::npos) break;
        __j = __s.find(this->separator(), __i);
        std::string_view __x{__s.data() + __i, __j - __i};

        for (const auto& [__in, __out] : this->cont())
            if (__x == __out) __a.insert(__in);

        __i = ++__j;
    }

    return __a;
}

std::string
attr_translator::
to(const attribute& __a) const
{
    std::string __s;
    bool __f{true};

    for (auto __it{__a.cont().begin()}; __it != __a.cont().end(); ++__it)
        for (const auto& [__in, __out] : this->cont())
            if (*__it == __in)
            {
                if (__f) __f = false;
                else __s += this->separator();

                __s += __out;
            }

    return __s;
}

rela_translator::
rela_translator()
    : _M_sep{" + "}, _M_data{}
{}

std::vector<std::pair<basic_relation, std::string>>&
rela_translator::
cont()
{ return this->_M_data; }

const std::vector<std::pair<basic_relation, std::string>>&
rela_translator::
cont() const
{ return this->_M_data; }

std::string&
rela_translator::
separator()
{ return this->_M_sep; }

const std::string&
rela_translator::
separator() const
{ return this->_M_sep; }

relation
rela_translator::
from(const std::string& __s) const
{
    std::string::size_type __i{}, __j{};
    relation __r;

    while (true)
    {
        if (!__i && __j == std::string::npos) break;
        __j = __s.find(this->separator(), __i);
        std::string_view __x{__s.data() + __i, __j - __i};

        for (const auto& [__in, __out] : this->cont())
            if (__x == __out) __r.insert(__in);

        __i = ++__j;
    }

    return __r;
}

std::string
rela_translator::
to(const relation& __r) const
{
    std::string __s;
    bool __f{true};

    for (auto __it{__r.cont().begin()}; __it != __r.cont().end(); ++__it)
        for (const auto& [__in, __out] : this->cont())
            if (*__it == __in)
            {
                if (__f) __f = false;
                else __s += this->separator();

                __s += __out;
            }

    return __s;
}

}
