#ifndef _LIBABE_FILE_H
#define _LIBABE_FILE_H 1

#include <string>
#include "database.h"

namespace abe
{

class file
{
public:
    using database_type = database;
    constexpr static const char* ext = "abe";

private:
    std::string _M_path;

public:
    file() = default;
    explicit file(const std::string& __path);

    const file& operator >> (database& __db) const;
    const file& operator << (const database& __db) const;
};

file make_filename(const std::string& __name);

}

#endif
