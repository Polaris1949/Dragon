#ifndef _LIBDLD_MANAGER_H
#define _LIBDLD_MANAGER_H 1

#include <queue>
#include "task.h"

namespace dld
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
    bool execute_once();
};

}

#endif
