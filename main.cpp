#include <iostream>

#include "song.hpp"
#include "friendships.hpp"
#include "maxheap.hpp"
#include "user.hpp"
#include "parser.hpp"

#define OP(operation)   parser.getOperation() == operation
#define ARG1(arg1)      parser.getArg1() == arg1
#define ARG2(arg2)      parser.getArg2() == arg2

using namespace std;

int main(int argc, char **argsv)
{
    cout << "Welcome to CA5" << endl;

    Friendships network;
    MaxHeap song_plays(20); // Init heap with 20 songs
    string input_str;

    for (;;)
    {
        cout << "\n: " << flush;
        getline(cin, input_str);
        Parser parser(input_str);

        if (OP("exit") || OP("quit")) break;
        if (OP("debug_heap")) song_plays.debug_print();
    }

    return 0;
}