#include <iostream>
#include <vector>
#include <assert.h>

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

string          vtos(vector<string>);
bool            file_exists(string path);
vector<Song *>  fileread();

vector<Song *> fileread()
{
    assert(file_exists("./songs/songs.txt"));

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
    return (ifs) ? true : false;
}

// Converts a vector of strings, into one string
string vtos(vector<string> vector)
{
	string str = "";
	for (int i = 0; i < (int)(vector.size()) - 1; i++) str += vector[i] + " ";
	str += vector[vector.size() - 1];
    str = str.substr(0, str.size()-2);
	return str;
}

int main()
{
    cout << "Welcome to CA5" << endl;

    Friendships network;
    vector<Song *> songs = fileread();
    BSTree<Song *> song_tree;
    // BSTree<User *> user_tree;
    MaxHeap song_plays(songs);
    string input_str;
    BSTree<Song *> p_song_tree;
    // Populate song_tree from the song vector
    for (int index = 0; index < (int)songs.size(); index++)
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
                network.GetUsers()->insert(new User(username));
            }else cout << "Syntax: useradd <username>" << endl;
        }
        else if (OP("friend"))
        {
            string a = parser.getArg1(), b = parser.getArg2();
            if (a != "" && a != "")
            {
                bool error = false;
                network.CreateFriendship(a, b, &error);
                if (!error) {
                    cout << "Created friendship between " << a << " and " << b << "." << endl;
                }else
                {
                    cout << "Failed to create friendship." << endl;
                }
            }else cout << "Syntax: friend <username> <username>\n"
                          "Creates friendship between two users.\n";
        }
        else if (OP("search") && ARG1("user"))
        {
            bool found = false;
            User *usr = network.GetUsers()->search(parser.getArg2(), &found);
            if (found) cout << "User " << *usr << " exists." << endl;
            else cout << "User not found" << endl;
        }
        else if (OP("search") && ARG1("song"))
        {
            bool found = false;
            Song *s = song_tree.search(parser.getArg2(), &found);
            if (found) cout << "Song " << *s << " exists." << endl;
            else cout << "Song not found" << endl;
        }
        else if (OP("addsong"))
        {
            if (parser.getArg1() != "\0"){
                song_tree.insert(new Song(parser.getArg1()));
                cout << parser.getArg1() << " added to system" << endl;
            }
            else {
                cout << "Error song not added, specify title" << endl;
            }
        }
        else if (OP("show") && ARG1("users")) network.GetUsers()->print();
        else if (OP("show") && ARG1("songs")) song_tree.print();
        else if (OP("exit") || OP("quit")) break;
        else if (OP("debug_heap")) song_plays.debug_print();
        else if (parser.getOperation() != "") cout << "Input not recognized.\n";
    }

    return 0;
}