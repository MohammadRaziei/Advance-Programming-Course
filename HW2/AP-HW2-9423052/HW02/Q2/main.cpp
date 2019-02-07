#include<iostream>
#include<fstream>
#include<vector>
#include<string>


bool isCapital(const std::string& str);
void print_out(const std::vector<std::string>& out);
std::vector<std::string> check_find(const std::string& oneWord);

int main()                    
{
	const char* FileName{"Error_find.txt"};
	//int data;
	std::ifstream File;
	File.open(FileName, std::ios::in | std::ios::out);
	std::string oneWord{};
	std::vector<std::string> output;
	while(File >> oneWord)
	{
		std::vector<std::string> temp {check_find(oneWord)};
		output.insert( output.end(), temp.begin(),temp.end());
	}
	File.close();
	print_out(output);
	return 0;
}


std::vector<std::string> check_find(const std::string& oneWord)
{
	const std::string separators{ " ,;:()[]{}.\"!?'\n\t" },
						vowels{"AaEeIiOoUu"}; // Word delimiters

	size_t start { oneWord.find_first_not_of(separators) }; // First word start index
	size_t end {};
	std::vector<std::string> Word, Out;
	while (start != std::string::npos) // Find the words
	{
		end = oneWord.find_first_of(separators, start + 1); // Find end of word
		if (end == std::string::npos) // Found a separator?
			end = oneWord.length(); // No, so set to last + 1Chapter 7  Working With StringS
		Word.push_back(oneWord.substr(start, end - start)); // Store the word
		start = oneWord.find_first_not_of(separators, end + 1); // Find 1st character of next word
	}
	start = oneWord.find_first_not_of(vowels) ;
	for(const auto& str : Word)
	{
		end = str.find_first_of(vowels, start + 1); // Find end of word
		if (end == std::string::npos) // Found a separator?
			end = str.length(); // No, so set to last + 1Chapter 7  Working With StringS
		if ((end - start ) >= 5)
			if(!isCapital(str.substr(start,end)))
				Out.push_back(str);
		start = str.find_first_not_of(vowels, end + 1); // Find 1st character of next word
	}
	return Out;
}
bool isCapital(const std::string& str)
{
	bool val{true};
	for(const auto& x : str)
		if (!(x >='A' && x <= 'Z'))    
			val &= false;
	return val;
}
void print_out(const std::vector<std::string>& out)
{
	for(size_t i{}; i < out.size(); i++)
		std::cout << out[i] << std::endl;
}
