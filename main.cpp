#include <iostream>
#include <vector>

#include "song.hpp"
#include "friendships.hpp"
#include "maxheap.hpp"
#include "bstree.hpp"
#include "user.hpp"
#include "parser.hpp"

#define OP(operation)   parser.getOperation() == operation
#define ARG1(arg1)      parser.getArg1() == arg1
#define ARG2(arg2)      parser.getArg2() == arg2

using namespace std;

void BSTree_test();

int main(int argc, char **argsv)
{
    cout << "Welcome to CA5" << endl;
    //BSTree_test();

    Friendships network;
    vector<Song *> songs;
    
    // Just for testing
    // songs.push_back(new Song("aaa", "", "", false));
    // songs.push_back(new Song("bbb", "", "", false));
    // songs.push_back(new Song("ccc", "", "", false));
    // songs.push_back(new Song("ddd", "", "", false));

    BSTree<Song *> song_tree();
    BSTree<User *> user_tree();
    MaxHeap song_plays(songs); // Init heap by passing it our vector of songs
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


void BSTree_test()
{
    BSTree<Song *> tree;

    Song *one = new Song("bbb", "", "", false);
    Song *two = new Song("aaa", "", "", false);
    Song *three = new Song("ccc", "", "", false);
    Song *four = new Song("abb", "", "", false);

    tree.insert(one);
    tree.insert(two);
    tree.insert(three);
    tree.insert(four);

    tree.print();
}