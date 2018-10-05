#include "database.h"

namespace abe
{

database::
database(const attribute& __a, const relation& __r)
    : _M_attr{__a}, _M_rela{__r}
{}

bool
database::
empty() const
{ return this->attr().empty() && this->rela().empty(); }

void
database::
clear()
{ this->attr().clear(); this->rela().clear(); }

attribute&
database::
attr()
{ return this->_M_attr; }

const attribute&
database::
attr() const
{ return this->_M_attr; }

relation&
database::
rela()
{ return this->_M_rela; }

const relation&
database::
rela() const
{ return this->_M_rela; }

}
