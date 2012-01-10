#ifndef BOOL_HEADER
#define BOOL_HEADER

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

struct m_true       //true-def
{
    enum{value = true};
};
struct m_false      //false-def
{
    enum{value = false};
};


tpl<bool b>    //bool; default false
struct m_bool
{
    td m_false type;
};

tpl<>          //spez true
struct m_bool<true>
{
    td m_true type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //BOOL_HEADER
