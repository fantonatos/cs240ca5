#include <iostream>
#include <vector>

#include "song.hpp"
#include "friendships.hpp"
#include "maxheap.hpp"
#include "bstree.hpp"
#include "user.hpp"
#include "parser.hpp"
#include "WordTokenizer.hpp"
#define OP(operation)   parser.getOperation() == operation
#define ARG1(arg1)      parser.getArg1() == arg1
#define ARG2(arg2)      parser.getArg2() == arg2

using namespace std;

void    BSTree_test();
string  vtos(vector<string>);

vector<Song *> fileread(){
    WordTokenizer info_reader = WordTokenizer("./songs", "songs.txt");
    vector<Song *> songs;
    vector<string> nextline;
    do {
        nextline = info_reader.nextLine();

        if (nextline.size() == 0) break;

        songs.push_back(new Song(vtos(nextline)));
    } while(nextline.size() > 0);

    return songs;
}

// Converts a vector of strings, into one string
string vtos(vector<std::string> vector)
{
	string str = "";
	for (int i = 0; i < vector.size() - 1; i++) str += vector[i] + " ";
	str += vector[vector.size() - 1];
    str = str.substr(0, str.size()-2);
	return str;
}

int main(int argc, char **argsv)
{
    cout << "Welcome to CA5" << endl;
    //BSTree_test();

    Friendships network;
    vector<Song *> songs = fileread();
    BSTree<Song *> song_tree;
    BSTree<User *> user_tree;
    MaxHeap song_plays(songs); // Init heap by passing it our vector of songs
    string input_str;

    // Add every song to the song_tree
    for (int index = 0; index < songs.size(); index++)
        song_tree.insert(songs[index]);

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

/*
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
}*/