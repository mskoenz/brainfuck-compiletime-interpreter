#ifndef BF_CHARS_HEADER
#define BF_CHARS_HEADER

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

struct bf_print {};
struct bf_read {};
struct bf_bra_open {};
struct bf_bra_close {};
struct bf_back {};
struct bf_advance {};
struct bf_plus {};
struct bf_minus {};


tpl <char const c>   //conversion tpl: char-->type 
struct m_char_to_type
{
    td void type;
};
tpl <>                     //spez: .
struct m_char_to_type<'.'>
{
    td bf_print type;
};
tpl <>                     //spez: ,
struct m_char_to_type<','>
{
    td bf_read type;
};
tpl <>                     //spez: [
struct m_char_to_type<'['>
{
    td bf_bra_open type;
};
tpl <>                     //spez: ]
struct m_char_to_type<']'>
{
    td bf_bra_close type;
};
tpl <>                     //spez: <
struct m_char_to_type<'<'>
{
    td bf_back type;
};
tpl <>                     //spez: >
struct m_char_to_type<'>'>
{
    td bf_advance type;
};
tpl <>                     //spez: +
struct m_char_to_type<'+'>
{
    td bf_plus type;
};
tpl <>                     //spez: -
struct m_char_to_type<'-'>
{
    td bf_minus type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //BF_CHARS_HEADER
