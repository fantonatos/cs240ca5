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
    void AddUser();
    void RemoveUser(); // is this required?
    void CreateFriendship(string a, string b, bool *error)
    {
        // Create friendship between a and b

        User *userA = users.search(a, error);
        User *userB = users.search(b, error);
        *error = !error; // because search returns true if found.

        if (*error)
        {
            userA->AddFriend(userB);
            userB->AddFriend(userA);
        }
    }
};

#endif // !_FRIENDSHIPS_HPP_