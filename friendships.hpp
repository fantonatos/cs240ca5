#ifndef _FRIENDSHIPS_HPP_
#define _FRIENDSHIPS_HPP_

#include <map>
#include <string>

#include "song.hpp"
#include "user.hpp"

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
    map<string, User*> users;
public:
    void AddUser();
    void RemoveUser(); // is this required?
};

#endif // !_FRIENDSHIPS_HPP_