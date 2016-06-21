
//
//This is an example program that shows some use cases of SLUtils!
//

//Make sure to include SLUtils.h
#include "SLUtils.h"

//Main functions
int main(int argc, char* argv[])
{
	//I didn't error check because this is just an example. Normally you'd want to error check to see if the user provided arguments

	//Creating some variables so that we don't have to write out the function names while outputting
	std::string text = read_file(argv[1]);
	std::string word = "What";
	std::string filename = argv[1];

	//Setting up some variables that require an integer return value
	int word_occurrence = count_word_occurrence(text, word);
	int word_count = count_words(text);

	int size_of_file = get_file_size(argv[1]);

	//Seeing what some of the text file manipulation functions!
	std::cout << text << "\nContains the word: " << word << " " << word_occurrence << 
		" times! The word count of this text is: " << word_count << "\n\n";

	//Getting the size of a file 
	std::cout << "Current size of file: " << print_size_in_format(size_of_file) << "\n\n";

	std::cout << "Size of the file in kb: " << bytes_to_format(size_of_file, "kb") << "KB\n";
	std::cout << "Size of the file in mb: " << bytes_to_format(size_of_file, "mb") << "MB\n";
	std::cout << "Size of the file in gb: " << bytes_to_format(size_of_file, "gb") << "GB\n";

	return 0;
}
