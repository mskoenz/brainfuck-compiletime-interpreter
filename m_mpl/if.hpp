#ifndef IF_HEADER
#define IF_HEADER

#include "bool.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

tpl <tn cond, tn if_true, tn if_false>   //if; default false
struct m_if
{
    td if_false type;
};

tpl <tn if_true, tn if_false>              //spez true
struct m_if<m_true, if_true, if_false>
{
    td if_true type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //IF_HEADER
