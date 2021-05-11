#ifndef _HELP_FUNCTIONS_HPP_
#define _HELP_FUNCTIONS_HPP_

// May show as error in vscode, but works fine in linux
#include <dirent.h>

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

/**
 * Returns vector containing all the files in a directory.
 */
std::vector<std::string> get_files(std::string);

/**
 * Removes extension from file name.
 * Returns string containing the file's name without an extension.
 * 
 * Examples:
 * thisawesomesong.song-info.txt -> thisawesomesong
 * helloworld.song-lyrics.txt -> helloworld
 * document.txt -> document
 */
std::string remove_extension(std::string);

/**
 * Combines paths
 */
std::string combine_paths(std::string, std::string);

/**
 * Vector to string
 */
std::string vtos(std::vector<std::string> vector);

bool file_exists(std::string path);

#endif // !_HELP_FUNCTIONS_HPP_