#include <iostream>
#include <fstream>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;
namespace lambda = boost::lambda;

typedef pair<int, int> pair_type;
typedef vector<pair_type>::iterator myit;

bool char_mod;

bool valid(const char c)
{
    if( c == '.' or 
        c == ',' or 
        c == '[' or 
        c == ']' or 
        c == '<' or 
        c == '>' or 
        c == '+' or 
        c == '-')
        return true;
    else
        return false;
}

int read_in (vector<char>& op, vector<std::pair<int, int> >& bracket, char* filename)
{
    
    ifstream is(filename, ifstream::binary);
    if(is.is_open())
    {
        stack<int> open_brc;
        char c;
        unsigned pos = 0;
        
        while(is.good())
        {
            
            c = is.get();
            if(valid(c))
            {
                op.push_back(c);
                
                if(c == '[')
                    open_brc.push(pos);
                if(c == ']')
                {
                    if(open_brc.size() == 0)
                    {
                        cout << "mismatching brackets @ " << pos << endl;
                        return 1;
                    }
                    else
                    {
                        bracket.push_back(make_pair(open_brc.top(), pos));
                        open_brc.pop();
                    }
                }
                ++pos;
            }
        }
        if(open_brc.size() != 0)
        {
            cout << "mismatching brackets @ end" << endl;
            return 1;
        }
        
        cout << "-----input------" << endl;
        for_each(op.begin(), op.end(), cout << lambda::_1);
        cout << endl;
        return 0;
    }
    else
    {
        cout << "file doesn't exist" << endl;
        return 1;
    }
}

int interpret(vector<char> op, vector<std::pair<int, int> > bracket, vector<int> world)
{
    unsigned pointer = 0;
    for(unsigned pos = 0; pos < op.size(); ++pos)
    {
        switch(op[pos])
        {
            case '.':
                if(char_mod)
                    cout << char(world[pointer]);
                else
                    cout << world[pointer] << " ";
                break;
            case ',':
                cin >> world[pointer];
                break;
            case '<':
                if(pointer == 0)
                {
                    cout << "in negative range-error @ " << pos << endl;
                    return 1;
                }
                else
                    --pointer;
                break;
            case '>':
                ++pointer;
                if(pointer == world.size())
                    world.push_back(0);
                break;
            case '+':
                ++world[pointer];
                break;
            case '-':
                if(world[pointer]==0)
                {
                    cout << "negative value-error @ " << pos << endl;
                    return 1;
                }
                else
                    --world[pointer];
                break;
            case '[':
                if(!world[pointer])
                {
                    myit it = find_if(bracket.begin(), bracket.end(), boost::bind(&pair_type::first, _1) == pos);
                    pos = (*it).second;
                }
                else
                    ;//nothing
                break;
            case ']':
                if(world[pointer])
                {
                    myit it = find_if(bracket.begin(), bracket.end(), boost::bind(&pair_type::second, _1) == pos);
                    pos = (*it).first;
                }
                else
                    ;//nothing
                break;
            default:
                return 1; //just in case
                break;
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        cout << "please name a file" << endl;
        return 1;
    }
    else
    {
        char_mod = false;
        if(argc > 2)
        {
            cout << argv[2] << endl;
            if(string(argv[2]) == "-char")
                char_mod = true;
        }
        vector<char> vec;
        vector<pair_type> bracket;
        
        if(read_in(vec, bracket, argv[1]) != 0)
            return 1;
        
        
        vector<int> world;
        world.push_back(0);
        cout << "-----output-----" << endl;
        if(interpret(vec, bracket, world) != 0)
            return 1;
        cout << endl << "----finished----" << endl;
    }
}
