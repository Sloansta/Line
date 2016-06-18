#include <iostream>
#include <fstream>
#include <string>

void read_file(std::string, std::string);
int count_word_occurrence(std::string, std::string);
int check_for_space(std::string);

int main(int argc, char* argv[])
{
	if (argc > 1) 
		read_file(argv[1], argv[2]);
	else
		std::cout << "No file specified... \n" << std::endl;

	return 0;
}

void read_file(std::string filename, std::string word_wanted)
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

	std::cout << filename << " contains " << check_for_space(file_contents) << " words!\n";

	std::cout << filename << " contains the word: " << word_wanted << " " 
		<< count_word_occurrence(file_contents, word_wanted) << " times!\n";

}

//Counts the number of times the givin word occurs within a string
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

//Counts the total amount of words that are within the givin text
int check_for_space(std::string text)
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

