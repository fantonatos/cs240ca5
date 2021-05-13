#include <iostream>
#include <vector>

#include "friendships.hpp"
#include "maxheap.hpp"
#include "bstree.hpp"
#include "song.hpp"
#include "user.hpp"
#include "parser.hpp"
#include "WordTokenizer.hpp"

#define OP(operation)   parser.getOperation() == operation
#define ARG1(arg1)      parser.getArg1() == arg1
#define ARG2(arg2)      parser.getArg2() == arg2

using namespace std;

void            BSTree_test();
string          vtos(vector<string>);
bool            file_exists(string path);
vector<Song *>  fileread();

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

bool file_exists(string path)
{
    ifstream ifs;
    ifs.open(path);
    if (ifs) return true;
    return false;
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

        if (OP("useradd"))
        {
            string username = parser.getArg1();
            if (username != "")
            {
                cout << "Added user " << username << endl;
                user_tree.insert(new User(username));
            }else cout << "Syntax: useradd <username>" << endl;
        }
        else if (OP("show") && ARG1("users")) user_tree.print();
        else if (OP("exit") || OP("quit")) break;
        else if (OP("debug_heap")) song_plays.debug_print();
        else if (parser.getOperation() != "") cout << "Input not recognized.\n";
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