#include "song.hpp"

Song::Song(string title, string artist, string duration, bool explicitness)
{
    this->artist = artist;
    this->title = title;
    this->isSongExplicit = explicitness;
    this->duration = duration;

    // Standard library provides us with date and time
    time_t t = time(0);
    tm *now = localtime(&t);
    dateAdded = to_string(now->tm_year + 1900) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_mday);
    timeAdded = to_string(now->tm_hour + 1) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);

}

// SONG FILE I/O Code from CA3. Not sure if needed.
/*
Song::Song(string songname)
{
    WordTokenizer info_reader = WordTokenizer(songname + ".song-info.txt");
    vector<string> lyrics;

    this->title = vtos(info_reader.nextLine());
	this->artist = vtos(info_reader.nextLine());
	this->duration = vtos(info_reader.nextLine());
	this->isSongExplicit = vtos(info_reader.nextLine()) == "y" ? true : false;
    this->timeAdded = vtos(info_reader.nextLine());
    this->dateAdded = vtos(info_reader.nextLine());
    info_reader.~WordTokenizer();

    if (file_exists(songname + ".song-lyrics.txt"))
    {
        // replace with vector??
        WordTokenizer lyrics_reader = WordTokenizer(songname + ".song-lyrics.txt");
        LinkedList<string> *lyrics_store = new LinkedList<string>();

        do
        {
            lyrics = lyrics_reader.nextLine();
            if (lyrics.size() == 0) break;

            string word = "";
            for (int i = 0; i < lyrics.size(); i++)
            {
                lyrics_store->Add(lyrics[i]);
            }
        } while (lyrics.size() > 0);

        // Assign this lyrics store to the song class's store.
        this->lyrics = lyrics_store;
        lyrics_reader.~WordTokenizer();
    }else
    {
        // No Lyrics for this song
        this->lyrics = nullptr;
    }
}

void Song::Save(string dir)
{
    // Create ofstreams for the info and lyrics files.
    string filename = this->title;
    //replace(filename.begin(), filename.end(), ' ', '_');
    ofstream infofile;
    ofstream lyricsfile;
    
    // Write song-info file
    infofile.open(combine_paths(dir, filename + ".song-info.txt"), ofstream::out | ofstream::trunc);
    infofile << this->title << endl;
    infofile << this->artist << endl;
    infofile << this->duration << endl;
    infofile << (this->isSongExplicit ? "y" : "n") << endl;
    infofile << this->timeAdded << endl;
    infofile << this->dateAdded << endl;
    infofile.close();


    // Write song-lyrics file
    if (this->lyrics != nullptr)
    {
        lyricsfile.open(combine_paths(dir, filename + ".song-lyrics.txt"), ofstream::out | ofstream::trunc);
        for (int index = 0; index < this->lyrics->Count(); index++)
        {
            string word = *this->lyrics->ItemAt(index);
            lyricsfile << *this->lyrics->ItemAt(index) << (word[word.size()-1] == '\n' ? "" : " ");
            // TODO: Fix extra space being added at the end of each line in lyrics file.

        }
        lyricsfile.clear();
    }    
}

*/