#ifndef _LIBABE_RELATION_H
#define _LIBABE_RELATION_H 1

#include <set>
#include "attribute.h"

namespace abe
{

class basic_relation
{
public:
    using value_type = unsigned int;
    using attribute_type = basic_attribute;

private:
    attribute_type _M_left;
    attribute_type _M_right;
    value_type _M_data;

public:
    basic_relation() = default;
    basic_relation(const attribute_type& __l, const attribute_type& __r,
        const value_type& __v);

    attribute_type& left();
    const attribute_type& left() const;

    attribute_type& right();
    const attribute_type& right() const;

    value_type& data();
    const value_type& data() const;

    bool operator == (const basic_relation& __r) const;
    bool operator != (const basic_relation& __r) const;
};

struct _Rela_lt_helper
{
    using _Rela_t = basic_relation;

    bool operator() (const _Rela_t& __x, const _Rela_t& __y) const;
};

class relation
{
public:
    using value_type = basic_relation;
    using container_type = std::set<value_type, _Rela_lt_helper>;

private:
    container_type _M_cont;

public:
    bool empty() const;
    void clear();

    container_type& cont();
    const container_type& cont() const;

    bool insert(const value_type& __r);
    bool erase(const value_type& __r);
    bool find(const value_type& __r) const;
};

}

#endif
