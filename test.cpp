
//
//This is an example program that shows some use cases of SLUtils!
//

//Make sure to include SLUtils.h
#include "SLUtils.h"

//Main functions
int main(int argc, char* argv[])
{
	//Creating some variables so that we don't have to write out the function names while outputting
	std::string text = read_file(argv[1]);
	std::string word = "What";
	std::string filename = argv[1];

	//Setting up some variables that require an integer return value
	int word_occurrence = count_word_occurrence(text, word);
	int word_count = count_words(text);

	//Seeing what some of the text file manipulation functions!
	std::cout << text << "\n Contains the word: " << word << " " << word_occurrence << 
		" times! The word count of this text is: " << word_count << "\n";

	//Getting the size of a file 
	//(Get the file size in bytes, i will make a calculation that determines whether to use Bytes/KB/MB/GB depending on the size of the file soon)
	std::cout << "The size of the file is around: " << get_file_size(argv[1]) << " bytes! \n";

	return 0;
}
