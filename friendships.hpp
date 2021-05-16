#ifndef _FRIENDSHIPS_HPP_
#define _FRIENDSHIPS_HPP_

#include <map>
#include <string>

#include "song.hpp"
#include "user.hpp"
#include "bstree.hpp"

using namespace std;

/**
 * Initially, users have no friendships, so a graph cannot be the only
 * data structure used because there will not be edges connecting the users.
 * 
 * We use a map<string, User*> to map the every user's name to his instance.
 * std::map has a O(log(n)) worst-case time complexity.
 * 
 */

class Friendships
{
private:
    // TODO: Implement the user map - key values of string "username" -> User*
    BSTree<User *> users;
public:
    BSTree<User *> *GetUsers() { return &users; }
    void RemoveUser(); // is this required?

    bool Exists(string usr)
    {
        bool found = false;
        users.search(usr, &found);
        return found;
    }

    bool CreateFriendship(string a, string b)
    {
        // Create friendship between a and b
        bool found = false;
        User *userA = users.search(a, &found);
        User *userB = users.search(b, &found);

        if (found)
        {
            // Make sure they are not already friends, we want to prevent duplicates.
            if (userA->IsFriendsWith(userB) || userB->IsFriendsWith(userA)) return !found;

            userA->AddFriend(userB);
            userB->AddFriend(userA);
        }

        return !found; // returns true on error only
    }

    void ShowFriends(string un)
    {
        bool found = false;
        User *usr = users.search(un, &found);

        if (!found) return;
        cout << "User " << *usr << endl;

        vector<User *> *friends = usr->GetFriends();
        cout << (friends == nullptr ? "nullptr" : "valid") << endl;
        for (int i = 0; i < friends->size(); i++)
        {
            cout << "Has friend " << *(*friends)[i] << endl;
        }

    }
    
    
    
};

#endif // !_FRIENDSHIPS_HPP_