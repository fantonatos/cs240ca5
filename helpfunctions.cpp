// #include <iostream>

// #include "helpfunctions.hpp"

// /**
//  * DO NOT TOUCH THIS!!!! ASSUME THIS WORKS!!!!
//  * 
//  * Provided by the ca3 onboarding repository.
//  */
// std::vector<std::string> get_files(std::string inputdir_name) {
// 	if (inputdir_name == "") return std::vector<std::string>();
// 	// cite - https://www.delftstack.com/howto/cpp/how-to-get-list-of-files-in-a-directory-cpp/
// 	DIR *dir;
// 	struct dirent *dir_entry;
// 	std::vector<std::string> filenames;
// 	if ((dir = opendir(inputdir_name.c_str())) != nullptr) {
// 		while ((dir_entry = readdir(dir)) != nullptr) {
// 			// only adding txt files.
// 			if (std::string(dir_entry->d_name).find(".txt") != std::string::npos) {
// 				filenames.push_back(dir_entry->d_name);
// 			}
// 		}
// 		closedir(dir);
// 	}
// 	return filenames;
// }

// std::string remove_extension(std::string filename)
// {
//     size_t lastindex = filename.find_first_of(".");
//     if (lastindex == std::string::npos) return filename;
//     else return filename.substr(0, lastindex);
// }

// std::string combine_paths(std::string path1, std::string path2)
// {
//     std::stringstream ss;
//     ss << path1 << "/" << path2;
//     return ss.str();
// }

// std::string vtos(std::vector<std::string> vector)
// {
// 	std::string str = "";
// 	for (int i = 0; i < vector.size() - 1; i++) str += vector[i] + " ";
// 	str += vector[vector.size() - 1];
//     str = str.substr(0, str.size()-2);
// 	return str;
// }

// bool file_exists(std::string path)
// {
//     std::ifstream ifs;
//     ifs.open(path);
//     if (ifs) return true;
//     return false;
// }