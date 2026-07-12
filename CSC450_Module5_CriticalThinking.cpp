#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function declarations
void appendToFile(const std::string& filePath);
void reverseFileContents(const std::string& sourcePath, const std::string& destinationPath);

int main() {
	// Define the file paths
	std::string originalFilePath = "C:\\Users\\Jonathan\\Desktop\\CSC450_CT5_mod5.txt";
	std::string reverseFilePath = "C:\\Users\\Jonathan\\Desktop\\CSC450-mod5-reverse.txt";

	std::cout << "\n--- Step 1: Appending User Input ---" << std::endl;
	appendToFile(originalFilePath);

	std::cout << "\n--- Step 2: Reversing File Contents ---" << std::endl;
	reverseFileContents(originalFilePath, reverseFilePath);

	std::cout << "\nProcess complete. Check your Desktop and source folders for the updated files." << std::endl;

	return 0;
}

/***
Obtains text input fro mthe user and appends it to the source file
*/
void appendToFile(const std::string& filePath) {
	// Open the file using std::ios::app to safely open without erasing data
	std::ofstream outFile(filePath, std::ios::app);

	if (!outFile) {
		std::cerr << "Error: Could not open the original file for writing at " << filePath << std::endl;
		return;
	}

	std::string userInput;
	std::cout << "Enter the text you want to append to the file: ";
	std::getline(std::cin, userInput);

	// Append the new user input alonf with a newline character
	outFile << userInput << std::endl;

	outFile.close();
	std::cout << "Successfully appended your text to the file." << std::endl;
}

/***
Reads the source file, reverses all the characters, and saves it to a new file
*/
void reverseFileContents(const std::string& sourcePath, const std::string& destinationPath) {
	std::ifstream inFile(sourcePath);

	if (!inFile) {
		std::cerr << "Error: Could not open source file for reading at " << sourcePath << std::endl;
		return;
	}

	// Read file content into a string
	std::string fileContents((std::istreambuf_iterator<char>(inFile)),
		std::istreambuf_iterator<char>());
	inFile.close();

	if (fileContents.empty()) {
		std::cout << "The source file is empty. Nothing to reverse." << std::endl;
		return;
	}

	// Reverse the character string using a standard library algorithm
	std::reverse(fileContents.begin(), fileContents.end());

	// Write the reversed contents to the new output file
	std::ofstream outFile(destinationPath);
	if (!outFile) {
		std::cerr << "Error: Could not create the reverse file at " << destinationPath << std::endl;
		return;
	}

	outFile << fileContents;
	outFile.close();

	std::cout << "Successfully reversed all characters and saved to " << destinationPath << std::endl;
}