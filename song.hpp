#ifndef _SONG_HPP_
#define _SONG_HPP_

#include <iostream>
#include <cstdbool>
//#include <algorithm>
#include <string>
#include <ctime>

/*
#include "WordTokenizer.hpp"
#include "LinkedList.hpp"
#include "helpfunctions.hpp"
#include "BadWords.hpp"
*/

class Song
{
private:
    std::string title;
    std::string artist;
    std::string duration;
    std::string dateAdded;
    std::string timeAdded;

    bool isSongExplicit;

    //LinkedList<std::string> *lyrics;
    //int progress = 0;
public:
    Song() = default;
    //~Song() { delete lyrics; }
    
    /**
     * Creates a song object based on the provided title, artist, duration, and explicitness.
     */
    Song(std::string, std::string, std::string, bool);

    /**
     * Reads the contents of the provided file and creates a song object accordingly.
     * (aka deserialize)
     */
    //Song(std::string);

    /**
     * Saves the Song's information as song-info and song-lyrics files in the
     * specified folder.
     */
    //void Save(std::string);

    const std::string GetTitle() { return title; }
    bool IsExplicit() { return isSongExplicit; }

    int GetSeconds()
    {
        return atoi(duration.substr(3, 2).c_str()) + 
               atoi(duration.substr(0, 2).c_str()) * 60;
    }


    /**
     * Plays the number of requested words (from where previously left off).
     * Plays entire song if not specified.
     * 
     * If word count is specified, and end of song is reached, returns true.
     */
    //bool Play(bool censor, int word_count = 0);

    /*
    int Rewind(int word_count = -1)
    {
        if (word_count <= -1) progress = 0;
        else progress -= word_count;

        if (progress < 0) progress = 0;

        return progress;
    }*/

    // Decides equality based on whether the titles match.
    int operator==(const std::string &o) { if (o == title) return true; else return false; }

    friend std::ostream &operator<<(std::ostream &os, const Song &song)
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