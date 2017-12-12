
//
// Created by wzq on 12/12/17.
//

#include <Table.h>

uint8_t Table::load(string rawdata) {
    mdata=json::parse(rawdata);
    mname=mdata["name"];
}
Table& Table::setName(string name) {
    mname=name;
    mdata["name"]=name;
    return *this;
}
string Table::dump(){
    return mdata.dump();
}