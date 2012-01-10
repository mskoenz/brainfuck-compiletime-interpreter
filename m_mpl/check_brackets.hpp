// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 14:52:05 CET
// File:   check_brackets.hpp

#ifndef CHECK_BRACKETS_HEADER
#define CHECK_BRACKETS_HEADER

#include "bf_chars.hpp"
#include "pair.hpp"

#include "vector.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif
//======================================================================
tpl<tn vec, tn bra, tn stack>   //general recursion
struct m_check_brackets_impl
{
    tdn m_check_brackets_impl<tn vec::next
                            , bra
                            , stack
                            >tp type;
};

tpl<tn pre, tn id, tn nex, tn bra, tn stack> // spez if [
struct m_check_brackets_impl<m_vector<pre, bf_bra_open, id, nex>, bra, stack>
{
    tdn m_check_brackets_impl<nex
                            , bra
                            , tn m_push_back< stack
                                            , id>tp
                             >tp type;
};

tpl<tn pre, tn id, tn nex, tn bra, tn stack> // spez if ]
struct m_check_brackets_impl<m_vector<pre, bf_bra_close, id, nex>, bra, stack>
{
    tdn m_check_brackets_impl<nex
                            , tn m_push_back< bra
                                            , m_pair<tn m_top<stack>tp, id> >tp
                            , tn m_pop<stack>tp
                             >tp type;
};

tpl<tn bra, tn stack>   //recursion-break
struct m_check_brackets_impl<m_vector_end, bra, stack>
{
    td bra type;
};

//======================================================================
tpl<tn vec>         //nice interface
struct m_check_brackets
{
    tdn m_check_brackets_impl<vec
                            , m_vector_end
                            , m_vector_end
                            >tp type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //CHECK_BRACKETS_HEADER
