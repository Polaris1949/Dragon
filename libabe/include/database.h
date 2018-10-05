#ifndef _LIBABE_DATABASE_H
#define _LIBABE_DATABASE_H 1

#include "attribute.h"
#include "relation.h"

namespace abe
{

class database
{
public:
    using attribute_type = attribute;
    using relation_type = relation;

private:
    attribute _M_attr;
    relation _M_rela;

public:
    database() = default;
    database(const attribute& __a, const relation& __r);

    bool empty() const;
    void clear();

    attribute& attr();
    const attribute& attr() const;

    relation& rela();
    const relation& rela() const;
};

}

#endif
