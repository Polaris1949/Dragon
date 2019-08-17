#ifndef _LIBDNL_MANAGER_H
#define _LIBDNL_MANAGER_H 1

#include <queue>
#include "task.h"

namespace dnl
{

class manager
{
    std::queue<task> _M_q;

public:
    bool empty() const;
    const task& current() const;
    manager& push(const task& __x);
    manager& pop();
    bool execute();
    bool execute_all();
};

}

#endif
