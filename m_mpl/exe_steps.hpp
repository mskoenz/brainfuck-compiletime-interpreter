// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 22:09:56 CET
// File:   bf_exe_steps.hpp

#ifndef EXE_STEPS_HEADER
#define EXE_STEPS_HEADER

#include "if.hpp"
#include "bf_chars.hpp"

#include "pair.hpp"
#include "quartett.hpp"

#include "vector.hpp"
#include "move_on_vector.hpp"
#include "find_if.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

tpl<tn what, tn q4, tn bra> //never used, bc all operation spez
struct bf_exe_steps;

//======================================================================
tpl<tn q4, tn bra>          //spez print .
struct bf_exe_steps<bf_print, q4, bra>
{
    tdn m_qrt_chng_fourth<q4
                        , tn m_push_back<tn q4::fourth, tn q4::second::item>tp
                        >tp type;
};

//======================================================================
tpl<tn q4, tn bra>          //spez read ,
struct bf_exe_steps<bf_read, q4, bra>
{
    td m_quartett<tn q4::first
                , m_vector<   tn q4::second::prev 
                            , tn q4::third::item
                            , tn q4::second::index
                            , tn q4::second::next
                            >
                , tn m_advance<tn q4::third>tp
                , tn q4::fourth
                > type;
};

//======================================================================
tpl<tn q4, tn bra>          //spez advance >
struct bf_exe_steps<bf_advance, q4, bra>
{
    tdn m_qrt_apply_second<q4, m_save_advance>tp type;
};

//======================================================================
tpl<tn q4, tn bra>          //spez back <
struct bf_exe_steps<bf_back, q4, bra>
{
    tdn m_qrt_apply_second<q4, m_back>tp type;
};

//======================================================================
tpl<tn q4, tn bra>          //spez plus +
struct bf_exe_steps<bf_plus, q4, bra>
{
    tdn m_qrt_apply_second<q4, m_increase>tp type;
};

//======================================================================
tpl<tn q4, tn bra>          //spez minus -
struct bf_exe_steps<bf_minus, q4, bra>
{
    tdn m_qrt_apply_second<q4, m_decrease>tp type;
};

//======================================================================
tpl<tn q4, tn bra>          //spez bra_open [
struct bf_exe_steps<bf_bra_open, q4, bra>
{
    tdn q4::first::index pos;
    tdn m_find_if<bra
                , pos
                , m_get_first
                , m_get_second
                >tp trg;
    
    tdn m_if< tn m_equal<tn q4::second::item, m_int<0> >tp
            , tn m_qrt_chng_first<   q4
                                    , tn m_goto<tn q4::first, trg >tp
                                    >tp
            , q4
            >tp type;
};

//======================================================================
tpl<tn q4, tn bra>          //spez bra_colse ]
struct bf_exe_steps<bf_bra_close, q4, bra>
{
    tdn q4::first::index pos;
    tdn m_find_if<bra
                , pos
                , m_get_second
                , m_get_first
                >tp trg;
    
    tdn m_if< tn m_equal<tn q4::second::item, m_int<0> >tp
            , q4
            , tn m_qrt_chng_first<   q4
                                    , tn m_goto<tn q4::first, trg >tp
                                    >tp
            >tp type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //EXE_STEPS_HEADER
