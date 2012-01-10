// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 19:54:50 CET
// File:   interpreter.hpp

#ifndef INTERPRETER_HEADER
#define INTERPRETER_HEADER

#include "quartett.hpp"

#include "vector.hpp"
#include "move_on_vector.hpp"

#include "check_brackets.hpp"
#include "exe_steps.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

tpl<tn q4, tn bra>
struct bf_exe_action
{
    tdn bf_exe_steps<tn q4::first::item
            , q4
            , bra
            >tp type;
};

//======================================================================
tpl<tn q4, tn bra>  //  recursion of the interpreter
struct bf_interpreter_impl
{
    tdn bf_exe_action<q4, bra>tp new_q4;
    tdn bf_interpreter_impl<  tn m_qrt_apply_first<new_q4, m_advance>tp
                            , bra
                            >tp type;
};

tpl<tn world, tn in, tn out, tn bra>    //recursion_break
struct bf_interpreter_impl<m_quartett<m_vector_end, world, in, out>, bra>
{
    td m_quartett<m_vector_end
                , world
                , in
                , out
                > type;
};

//======================================================================
tpl<tn instr, tn in> //init interpreter
struct bf_interpreter
{
    //     instructions, world,     input, output
    td m_quartett<instr, tn m_init_vector<m_int<0> >tp, in, m_vector_end> q4;
    tdn m_check_brackets<instr>tp bra;
    
    tdn bf_interpreter_impl<q4, bra>tp type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //INTERPRETER_HEADER
