#ifndef _USER_HPP_
#define _USER_HPP_

#include <string>

#include "song.hpp"
#include "user.hpp"

using namespace std;

class User
{
private:
    string username;
public:

    /**
     * User class constructor.
     */
    User(string _username)
    {
        username = _username;
    }
};

#endif // !_USER_HPP_