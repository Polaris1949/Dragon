#ifndef _LIBDNL_TASK_H
#define _LIBDNL_TASK_H 1

#include <string>

namespace dnl
{

class task
{
    std::string _M_url;
    std::string _M_loc;

public:
    task() = default;
    task(const std::string& __url, const std::string& __loc);
    const std::string& url() const;
    const std::string& loc() const;
};

}

#endif
