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
    map<string, User*> list;
    BSTree<User *> users;
    
public:
    BSTree<User *> *GetUsers() { return &users; }

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



    // Removed the friendship between two users
    void RemoveFriendship(string a, string b)
    {
        bool found = false;
        User *userA = users.search(a, &found);
        User *userB = users.search(b, &found);

        if (found) RemoveFriendship(userA, userB);
    }

    void RemoveFriendship(User *a, User *b)
    {
        a->RemoveFriend(b);
        b->RemoveFriend(a);
    }

    void ShowFriends(string un)
    {
        bool found = false;
        User *usr = users.search(un, &found);

        if (!found) return;
        cout << "User " << *usr << endl;

        vector<User *> *friends = usr->GetFriends();
        cout << (friends == nullptr ? "nullptr" : "valid") << endl;
        for (int i = 0; i < (int)friends->size(); i++)
        {
            cout << "Has friend " << *(*friends)[i] << endl;
        }
    }
    
    /**
     * It is unsafe to directly call remove on the BinarySearchTree
     * because we will then have dangling pointers
     */
    bool RemoveUser(string username, BSTree<User *> *primary_user_friends)
    {
        bool found = false;
        User *usr = users.search(username, &found);
        if (!found) return 1;
        else {
            // remove all his friendships
            vector<User *> *friends = usr->GetFriends();
            cout << "Fotis: Number of friends: " << friends->size() << endl;
            for (int i = 0; i < (int)friends->size(); i++) ((*friends)[i])->RemoveFriend(usr);

            // remove friendship with primary user
            primary_user_friends->remove(username);

            // remove him from the system's user collection
            users.remove(username);
        }

        return 0;
    }
    
    
    
};

#endif // !_FRIENDSHIPS_HPP_