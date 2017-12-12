#include <json.hpp>
#include <string>
#include <cstdint>
#ifndef WZQBASE_DATASTORAGE_H
#define WZQBASE_DATASTORAGE_H
using namespace std;
using json = nlohmann::json;

class Table{
private:
    string mname;
    json mdata;
public:
    uint8_t load(string rawdata);
    Table& setName(string name);
    string dump();

};

#endif //WZQBASE_DATASTORAGE_H
