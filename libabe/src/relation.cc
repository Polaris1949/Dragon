#include "relation.h"

namespace abe
{

basic_relation::
basic_relation(const attribute_type& __l, const attribute_type& __r,
        const value_type& __v)
    : _M_left{__l}, _M_right{__r}, _M_data{__v}
{}

basic_attribute&
basic_relation::
left()
{ return this->_M_left; }

const basic_attribute&
basic_relation::
left() const
{ return this->_M_left; }

basic_attribute&
basic_relation::
right()
{ return this->_M_right; }

const basic_attribute&
basic_relation::
right() const
{ return this->_M_right; }

unsigned int&
basic_relation::
data()
{ return this->_M_data; }

const unsigned int&
basic_relation::
data() const
{ return this->_M_data; }

bool
basic_relation::
operator == (const basic_relation& __r) const
{
    return this->left() == __r.left() && this->right() == __r.right()
        && this->data() == __r.data();
}

bool
basic_relation::
operator != (const basic_relation& __r) const
{ return !this->operator == (__r); }

bool
relation::
empty() const
{ return this->cont().empty(); }

void
relation::
clear()
{ this->cont().clear(); }

std::set<basic_relation, _Rela_lt_helper>&
relation::
cont()
{ return this->_M_cont; }

const std::set<basic_relation, _Rela_lt_helper>&
relation::
cont() const
{ return this->_M_cont; }

bool
relation::
insert(const value_type& __r)
{ return this->cont().insert(__r).second; }

bool
relation::
erase(const value_type& __r)
{ return this->cont().erase(__r); }

bool
relation::
find(const value_type& __r) const
{ return this->cont().count(__r); }

bool
_Rela_lt_helper::
operator() (const _Rela_t& __x, const _Rela_t& __y) const
{
    return __x.left() == __y.left() ? __x.right() == __y.right() ?
        __x.data() < __y.data() : _Attr_lt_helper{}(__x.right(), __y.right())
        : _Attr_lt_helper{}(__x.left(), __y.left());
}

}
