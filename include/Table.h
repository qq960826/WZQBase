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
    json mcolumn;
    int mmaxid;
public:
    uint8_t load(string rawdata);
    Table& setName(string name);
    int insert(string row);
    json select();
    //uint8_t insert(string rows);
    string dump();

};
json select_minize(json data);//去除id
json select_filter(json data);//提取所需记录
#endif //WZQBASE_DATASTORAGE_H
