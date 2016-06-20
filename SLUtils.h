#pragma once

#include <string>
#include <fstream>
#include <iostream>

//Get this working tomorrow, you will have to remove the function declaration so that this works
std::string read_file(std::string);
int count_word_occurrence(std::string, std::string);
int count_words(std::string);
int get_file_size(const char*);


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
