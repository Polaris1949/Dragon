#include "task.h"

namespace dnl
{

task::
task(const std::string& __url, const std::string& __loc)
    : _M_url{__url}, _M_loc{__loc}
{}

const std::string&
task::
url() const
{ return this->_M_url; }

const std::string&
task::
loc() const
{ return this->_M_loc; }

}
