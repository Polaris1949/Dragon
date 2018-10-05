#ifndef _LIBABE_TRANSLATOR_H
#define _LIBABE_TRANSLATOR_H 1

#include <string>
#include <vector>
#include "attribute.h"
#include "relation.h"

namespace abe
{

class attr_translator
{
public:
    using in_type = basic_attribute;
    using out_type = std::string;
    using container_type = std::vector<std::pair<in_type, out_type>>;

private:
    std::string _M_sep;
    container_type _M_data;

public:
    attr_translator();

    container_type& cont();
    const container_type& cont() const;

    std::string& separator();
    const std::string& separator() const;

    attribute from(const std::string& __s) const;
    std::string to(const attribute& __a) const;
};

class rela_translator
{
public:
    using in_type = basic_relation;
    using out_type = std::string;
    using container_type = std::vector<std::pair<in_type, out_type>>;

private:
    std::string _M_sep;
    container_type _M_data;

public:
    rela_translator();

    container_type& cont();
    const container_type& cont() const;

    std::string& separator();
    const std::string& separator() const;

    relation from(const std::string& __s) const;
    std::string to(const relation& __r) const;
};

}

#endif
