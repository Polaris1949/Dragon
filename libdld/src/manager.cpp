#include "manager.h"
#include <cstdlib>

namespace dld
{

inline bool
manager::
empty() const
{ return this->_M_q.empty(); }

inline const task&
manager::
current() const
{ return this->_M_q.front(); }

inline manager&
manager::
push(const task& __x)
{ this->_M_q.push(__x); return *this; }

inline manager&
manager::
pop()
{ this->_M_q.pop(); return *this; }

bool
manager::
execute()
{
    while (!this->empty())
    {
        task __t{this->current()};
        this->pop();
        std::string __c{"curl -o "};
        __c += __t.loc() + ' ' + __t.url();
        if (system(__c.c_str())) return false;
    }

    return true;
}

bool
manager::
execute_once()
{
    std::string __c{"curl"};

    while (!this->empty())
    {
        task __t{this->current()};
        this->pop();
        __c += " -o " + __t.loc() + ' ' + __t.url();
    }

    return !system(__c.c_str());
}

}
