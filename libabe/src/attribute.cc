#include "attribute.h"

namespace abe
{

basic_attribute::
basic_attribute(const value_type& __v)
    : _M_data{__v}
{}

unsigned int&
basic_attribute::
data()
{ return this->_M_data; }

const unsigned int&
basic_attribute::
data() const
{ return this->_M_data; }

bool
basic_attribute::
operator == (const basic_attribute& __a) const
{ return this->data() == __a.data(); }

bool
basic_attribute::
operator != (const basic_attribute& __a) const
{ return !this->operator == (__a); }

bool
attribute::
empty() const
{ return this->cont().empty(); }

void
attribute::
clear()
{ this->cont().clear(); }

std::set<basic_attribute, _Attr_lt_helper>&
attribute::
cont()
{ return this->_M_cont; }

const std::set<basic_attribute, _Attr_lt_helper>&
attribute::
cont() const
{ return this->_M_cont; }

bool
attribute::
insert(const value_type& __a)
{ return this->cont().insert(__a).second; }

bool
attribute::
erase(const value_type& __a)
{ return this->cont().erase(__a); }

bool
attribute::
find(const value_type& __a) const
{ return this->cont().count(__a); }

bool
_Attr_lt_helper::
operator() (const _Attr_t& __x, const _Attr_t& __y) const
{ return __x.data() < __y.data(); }

}
