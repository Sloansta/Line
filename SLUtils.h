#pragma once

#include <string>
#include <fstream>
#include <iostream>

//Get this working tomorrow, you will have to remove the function declaration so that this works
std::string read_file(std::string);
int count_word_occurrence(std::string, std::string);
int count_words(std::string);
int get_file_size(const char*);
int bytes_to_format(int, std::string);

//Helper functions
std::string print_size_in_format(int);

//Reads the file
std::string read_file(std::string filename)
{
	std::string line;
	std::string file_contents;
	std::ifstream file(filename);

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			file_contents += line;
			file.ignore(); //Ignores the new lines and other things
			file_contents.push_back('\n');
		}

		file.close();
	}
	else
		std::cout << "Cannot open file";
	return file_contents;
}

//Gets size of givin file
int get_file_size(const char *filename)
{
	//Felt like making this a C implementation. No strings!
	FILE *fl = NULL;
	int size = 0;

	fl = fopen(filename, "rb");

	//Error checking is important!!!!
	if (fl == NULL)
		std::cout << "Error loading file. Are you sure that you typed the name in correctly?";
	else 
	{
		fseek(fl, 0, SEEK_END);
		size = ftell(fl);
		fclose(fl);

		return size;
	}
}

//Function that will return an integer depending on the format size you want it to convert to
int bytes_to_format(int size, std::string format)
{
	int kb_divisor = 1000;
	int mb_divisor = 1000000;
	int gb_divisor = 1000000000;

	int formated_size = 0;

	if (format == "kb" || format == "KB")
		formated_size = size / kb_divisor;

	else if (format == "mb" || format == "MB")
		formated_size = size / mb_divisor;

	else if (format == "gb" || format == "GB")
		formated_size = size / gb_divisor;

	return formated_size;

}


// PRINT_SIZE_IN_FORMAT() BEING DELETED SOON!
/*
	*Helper function that will conver bytes to their proper size, rather than just printing bytes

	Similar to the bytes_to_format() function, this function just prints out the size of the integer provided in the arguments,
	making it easier to use when printing data to the console or printing to other interfaces

	This will most likely be removed as it's rather similar to bytes_to_format() and might not be of use.
*/
std::string print_size_in_format(int size)
{
	//Code needs to be cleaned up and refactored, continue with caution you have been warned!

	int kb_divisor = 1000;
	int mb_divisor = 1000000;
	int gb_divisor = 1000000000;

	int formated_size = 0;

	if (size >= kb_divisor && size < mb_divisor)
	{
		formated_size = size / kb_divisor;
		std::string str = std::to_string(formated_size);

		return str + "KB";

	}else if (size >= mb_divisor && size < gb_divisor)
	{
		formated_size = size / mb_divisor;
		std::string str = std::to_string(formated_size);

		return str + "MB";
	}else if (size >= gb_divisor)
	{
		formated_size = size / gb_divisor;
		std::string str = std::to_string(formated_size);

		return str + "GB";
	}else
	{
		formated_size = size;
		std::string str = std::to_string(formated_size);

		return str + "Bytes";
	}
}

//Counts the word count
int count_word_occurrence(std::string text, std::string word)
{
	int word_count = 0;
	int i = 0;

	for (i = text.find(word, 0); i != std::string::npos; i = text.find(word, i))
	{
		word_count++;
		i++;
	}

	return word_count;
}

//Counts the number of words that are in the givin string
int count_words(std::string text)
{
	int words = 0;
	int new_lines = 0;
	for (int i = 0; i < int(text.length()); i++)
	{
		try
		{
			if (isspace(text.at(i)))
				words++;
			else if (text.at(i) == '\n')
				new_lines++;
		}
		catch (const std::exception&)
		{
			std::cout << "Something went wrong when reading your text. Do you have invalide characters?\n";
		}
	}
	return words;
}
