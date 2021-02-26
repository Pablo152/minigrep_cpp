#include <iostream>
#include <fstream>

#include "params.h"

#include <vector>
#include <algorithm>
#include <string>

// Splits file by lines.
std::vector<std::string> parseFile(const std::string &fileName)
{
  std::ifstream file(fileName);

  if(!file) {
    std::cerr << "File not found!" << std::endl;
  }

  std::vector<std::string> linesInFile;
  std::string line;

  while (std::getline(file, line))
  {
    linesInFile.push_back(line);
  }
  return linesInFile;
}

void searchString(const std::vector<std::string> &parsedFile, Params &params)
{
  int i = 1;
  std::for_each(parsedFile.begin(), parsedFile.end(), [&, params, i](const std::string &line) mutable {
    if (line.find(params.getQuery()) != std::string::npos)
    {
      std::cout << "Query found at line: " << i << ", " << line << std::endl;
    }
    ++i;
  });
}

int main(int argc, char **argv)
{

  if (!argv[1] || !argv[2])
  {
    std::cerr << "Syntax is: minigrep <query> <filename>" << std::endl;
    return -1;
  }

  Params params = Params(argv[1], argv[2]);

  std::cout << "Searching for: " << params.getQuery() << std::endl;
  std::cout << "In file: " << params.getFileName() << std::endl;

  std::vector<std::string> parsedFile = parseFile(params.getFileName());

  searchString(parsedFile, params);

  return 1;
}