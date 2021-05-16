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
    MaxHeap song_plays(songs);
    string input_str;
    BSTree<Song *> p_song_tree;
    BSTree<User *> p_friends_tree;
    
    // Populate song_tree from the song vector
    for (int index = 0; index < (int)songs.size(); index++)
        song_tree.insert(songs[index]);

    for (;;)
    {
        cout << "\n: " << flush;
        getline(cin, input_str);
        Parser parser(input_str);
        const string arg1 = parser.getArg1(), arg2 = parser.getArg2();

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
            
            // 2 Usernames provided
            if (a != "" && b != "")
            {

                bool error = network.CreateFriendship(a, b);
                if (error)
                    cout << "Failed to create friendship." << endl;
                else
                    cout << "Created friendship between " << a << " and " << b << "." << endl;
                
            }
            // 1 username provided
            else if (a != "" && b == "")
            {
                bool found = false;
                User *usr = network.GetUsers()->search(a, &found);

                if (found) p_friends_tree.insert(usr);
                else cout << a << " does not exist." << endl;

            }else cout << "Syntax: friend <username> <username>\n"
                          "Creates friendship between two users. OR\n"
                          "Syntax: friend <username>\n"
                          "Creates a friendship between the primary user and others.\n";
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
                // TODO: Also add the song to the MaxHeap
                cout << parser.getArg1() << " added to system" << endl;
            }
            else {
                cout << "Error song not added, specify title" << endl;
            }
        }
        else if (OP("removefriend")) {
            string a = parser.getArg1(), b = parser.getArg2();
            
        
            if (a != "" && b != "")
            {
                bool found = false;
                User *usr1 = network.GetUsers()->search(a, &found);
                if(!found){
                    cout << "User not found" << endl;
                    continue;
                }
                bool found2 = false;
                User *usr2 = network.GetUsers()->search(b, &found2);
                usr1->removeFriend(usr2);
                usr2->removeFriend(usr1);
                cout << "Friendship of " << a << " and " << b << " removed " << endl;
            }
            
            // removing friend from primary user
            else if (a != "" && b == "")
            {
                //p_friends_tree.remove()
                cout << "remove PU friend" << endl;
            }   else cout << "Syntax: removefriend <username> <username>\n"
                          "Removes friendship between two users. OR\n"
                          "Syntax: friend <username>\n"
                          "Removes a friendship between the primary user and others.\n";

        }
        else if (OP("show") && ARG1("users")) network.GetUsers()->print();
        else if (OP("show") && ARG1("friends") && arg2 == "") cout << "Primary User's Friends: " << endl, p_friends_tree.print();
        else if (OP("show") && ARG1("friends") && arg2 != "") network.ShowFriends(parser.getArg2());
        else if (OP("show") && ARG1("songs")) song_tree.print();
        else if (OP("exit") || OP("quit")) break;
        else if (OP("debug_heap")) song_plays.debug_print();
        else if (parser.getOperation() != "") cout << "Input not recognized.\n";
    }

    return 0;
}