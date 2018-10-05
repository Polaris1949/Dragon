#ifndef _LIBABE_ATTRIBUTE_H
#define _LIBABE_ATTRIBUTE_H 1

#include <set>

namespace abe
{

class basic_attribute
{
public:
    using value_type = unsigned int;

private:
    value_type _M_data;

public:
    basic_attribute() = default;
    basic_attribute(const value_type& __v);

    value_type& data();
    const value_type& data() const;

    bool operator == (const basic_attribute& __a) const;
    bool operator != (const basic_attribute& __a) const;
};

struct _Attr_lt_helper
{
    using _Attr_t = basic_attribute;

    bool operator() (const _Attr_t& __x, const _Attr_t& __y) const;
};

class attribute
{
public:
    using value_type = basic_attribute;
    using container_type = std::set<value_type, _Attr_lt_helper>;

private:
    container_type _M_cont;

public:
    bool empty() const;
    void clear();

    container_type& cont();
    const container_type& cont() const;

    bool insert(const value_type& __a);
    bool erase(const value_type& __a);
    bool find(const value_type& __a) const;
};

}

#endif
