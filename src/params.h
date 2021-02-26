#include <iostream>

class Params {
public:
  Params(std::string query, std::string fileName): query{query}, fileName{fileName} {}

  std::string getQuery() {
    return query;
  }

  std::string getFileName() {
    return fileName;
  }

private:
  const std::string query;
  const std::string fileName;
};