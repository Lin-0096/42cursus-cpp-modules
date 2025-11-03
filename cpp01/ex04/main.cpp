#include <string>
#include <iostream>
#include <fstream> //file stream for file i/o
#include <sstream> //std::stringstream

std::string replaceAll(std::string& text, const std::string& s1, const std::string& s2);

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "usage: " << argv[0] << " <filename>, <s1>, <s2>"<< std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "error: s1 can't be empty!" << std::endl;
		return 1;
	}
	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "error: fail to open file" << filename << std::endl;
		return 1;
	}
	//std::stringstream reads/writes to a string in memory.
	std::stringstream buffer;
	buffer << inputFile.rdbuf(); //.rdbuf() gives access to its underlying stream buffer.
	std::string content = buffer.str(); ///buffer.str() gets the entire content of the stream as a std::string.

	std::string replaced = replaceAll(content, s1, s2);
	std::string outFile = filename + ".replace";
	std::ofstream outputFile(outFile); //Open a file for writing using the name stored in outFile. If the file doesn’t exist, create it. If it exists, overwrite it.
	if(!outputFile)
	{
		std::cerr << "error: fail to open file" << outFile << std::endl;
		return 1;
	}
	outputFile << replaced;
}

std::string replaceAll(std::string& text, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t match;

	//Any time you use a function like .find() in C++, it will return std::string::npos when the thing you're searching for is not found.
	while((match = text.find(s1, pos)) != std::string::npos)
	{
		result += text.substr(pos, match - pos);
		result += s2;
		pos = match + s1.length();
	}
	result += text.substr(pos); //sub from the postion to the end
	return result;
}
