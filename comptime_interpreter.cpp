#include "m_mpl/bf_chars.hpp"

#include "m_mpl/int.hpp"
#include "m_mpl/bool.hpp"
#include "m_mpl/if.hpp"

#include "m_mpl/ugly_init.hpp"
#include "m_mpl/examples.hpp"
#include "m_mpl/check_brackets.hpp"

#include "m_mpl/interpreter.hpp"
#include "m_mpl/exe_steps.hpp"

#include "m_mpl/readable_print.hpp"

#include "m_mpl/vector.hpp"
#include "m_mpl/find_if.hpp"
#include "m_mpl/move_on_vector.hpp"

#include "m_mpl/pair.hpp"
#include "m_mpl/quartett.hpp"



#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

int main()
{
    tdn m_ugly_init<',','>',',','.'
                    ,'[','>','+','<','-',']'
                    ,'.','>','.'
                    >tp wrong;
    
    tdn m_fast_int_init<19,21>tp input;
    
    tdn bf_interpreter<wrong, input>tp results1; //returns a quartett (instr/world/input/output)
    
    //~ m_print_vector_fwd<tn results1::fourth>();
    readable_runtime_print_int<tn results1::fourth>();
    
    tdn bf_interpreter<hello_world, input>tp results2;
    readable_runtime_print_char<tn results2::fourth>();
    
    tdn bf_interpreter<adder, input>tp results3;
    readable_runtime_print_int<tn results3::fourth>();
};
#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp
