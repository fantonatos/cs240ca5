#ifndef _SONG_HPP_
#define _SONG_HPP_

#include <iostream>
#include <cstdbool>
#include <algorithm>
#include <string>
#include <ctime>

/*
#include "WordTokenizer.hpp"*/
#include "helpfunctions.hpp"


using namespace std;

class Song
{
private:
    string title;
    string artist;
    string duration;
    string dateAdded;
    string timeAdded;

    bool isSongExplicit;

    string getTitleLowercase()
    {
        string tmp = this->title;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        return tmp;
    }

public:
    Song() = default;
    
    /**
     * Creates a song object based on the provided title, artist, duration, and explicitness.
     */
    Song(string, string, string, bool);

    /**
     * Reads the contents of the provided file and creates a song object accordingly.
     * (aka deserialize)
     */
    //Song(string);

    /**
     * Saves the Song's information as song-info and song-lyrics files in the
     * specified folder.
     */
    //void Save(string);

    const string GetTitle() { return title; }
    bool IsExplicit() { return isSongExplicit; }

    int GetSeconds()
    {
        return atoi(duration.substr(3, 2).c_str()) + 
               atoi(duration.substr(0, 2).c_str()) * 60;
    }

    // Decides equality based on whether the titles match.
    bool operator==(const string &o) { if (o == title) return true; else return false; }
    bool operator==(const Song &o) { if (o.title == title) return true; else return false; }

    /* Comparison Operators for Sorting in Alphabetical Order */
    bool operator<(const Song &left)
    {
        return left.title.compare(this->title) < 0 ? false : true;
    }

    bool operator>(const Song &left)
    {
        return left.title.compare(this->title) > 0 ? false : true;
    }


    friend ostream &operator<<(ostream &os, const Song &song)
    {
        if (song.title == "" && song.artist == "" && song.duration == "")
            os << "Song does not exist.";
        else
            os << "\"" << song.title << "\" by " << song.artist 
               << ", Duration: " << song.duration << ", Added on " 
               << song.dateAdded << " " << song.timeAdded << (song.isSongExplicit ? " (Explicit)" : "") << ".";
        return os;
    }
};



#endif // !_SONG_HPP_