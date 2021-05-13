#ifndef _USER_HPP_
#define _USER_HPP_

#include <string>
#include <vector>

#include "song.hpp"
#include "user.hpp"

using namespace std;

class User
{
private:
    string username;
    vector<User *> friends;

    string to_lower(string tmp)
    {
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        return tmp;
    }
public:

    /**
     * User class constructor.
     */
    User(string _username)
    {
        username = _username;
    }

    /* Comparison Operators for Sorting in Alphabetical Order */
    bool operator<(const User &left)
    {
        return to_lower(left.username).compare(to_lower(username)) < 0 ? false : true;
    }

    bool operator>(const User &left)
    {
        return to_lower(left.username).compare(to_lower(username)) > 0 ? false : true;
    }

    friend ostream &operator<<(ostream &os, const User &user)
    {
        if (user.username == "")
            os << "User does not exist.";
        else
            os << user.username;
        return os;
    }
};

#endif // !_USER_HPP_