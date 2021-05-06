#include "song.hpp"

Song::Song(std::string title, std::string artist, std::string duration, bool explicitness)
{
    this->artist = artist;
    this->title = title;
    this->isSongExplicit = explicitness;
    this->duration = duration;

    // Standard library provides us with date and time
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    dateAdded = std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday);
    timeAdded = std::to_string(now->tm_hour + 1) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);

}

// SONG FILE I/O Code from CA3. Not sure if needed.
/*
Song::Song(std::string songname)
{
    WordTokenizer info_reader = WordTokenizer(songname + ".song-info.txt");
    std::vector<std::string> lyrics;

    this->title = vtos(info_reader.nextLine());
	this->artist = vtos(info_reader.nextLine());
	this->duration = vtos(info_reader.nextLine());
	this->isSongExplicit = vtos(info_reader.nextLine()) == "y" ? true : false;
    this->timeAdded = vtos(info_reader.nextLine());
    this->dateAdded = vtos(info_reader.nextLine());
    info_reader.~WordTokenizer();

    if (file_exists(songname + ".song-lyrics.txt"))
    {
        WordTokenizer lyrics_reader = WordTokenizer(songname + ".song-lyrics.txt");
        LinkedList<std::string> *lyrics_store = new LinkedList<std::string>();

        do
        {
            lyrics = lyrics_reader.nextLine();
            if (lyrics.size() == 0) break;

            std::string word = "";
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

void Song::Save(std::string dir)
{
    // Create ofstreams for the info and lyrics files.
    std::string filename = this->title;
    //std::replace(filename.begin(), filename.end(), ' ', '_');
    std::ofstream infofile;
    std::ofstream lyricsfile;
    
    // Write song-info file
    infofile.open(combine_paths(dir, filename + ".song-info.txt"), std::ofstream::out | std::ofstream::trunc);
    infofile << this->title << std::endl;
    infofile << this->artist << std::endl;
    infofile << this->duration << std::endl;
    infofile << (this->isSongExplicit ? "y" : "n") << std::endl;
    infofile << this->timeAdded << std::endl;
    infofile << this->dateAdded << std::endl;
    infofile.close();


    // Write song-lyrics file
    if (this->lyrics != nullptr)
    {
        lyricsfile.open(combine_paths(dir, filename + ".song-lyrics.txt"), std::ofstream::out | std::ofstream::trunc);
        for (int index = 0; index < this->lyrics->Count(); index++)
        {
            std::string word = *this->lyrics->ItemAt(index);
            lyricsfile << *this->lyrics->ItemAt(index) << (word[word.size()-1] == '\n' ? "" : " ");
            // TODO: Fix extra space being added at the end of each line in lyrics file.

        }
        lyricsfile.clear();
    }    
}

bool Song::Play(bool censor, int word_count)
{
    // First of all, does this song even have lyrics?
    if (this->lyrics == nullptr) return true;

    if (word_count == 0)
    {
        for (int index = 0; index < lyrics->Count(); index++)
        {
            if (censor && is_badword(*lyrics->ItemAt(index)))
                std::cout << " @@@@@@@";
            else
                std::cout << " " << *lyrics->ItemAt(index);
        }
        return true;
    }
    else for (int index = 0; index + progress < lyrics->Count() && index < word_count; index++)
    {
        if (censor && is_badword(*lyrics->ItemAt(progress + index)))
            std::cout << " @@@@@@@";
        else
            std::cout << " " << *lyrics->ItemAt(progress + index);
        if (index + progress == lyrics->Count()-1) return true;
    }

    progress += word_count;

    return false;
}
*/