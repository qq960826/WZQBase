
//
// Created by wzq on 12/12/17.
//

#include <Table.h>
#include <iostream>

uint8_t Table::load(string rawdata) {
    mdata = json::parse(rawdata);
    mname = mdata["name"];//数据库名称
    mmaxid = mdata["maxid"];//最大id
    mcolumn = mdata["column"];//列表

}

Table &Table::setName(string name) {
    mname = name;
    mdata["name"] = name;
    return *this;
}

string Table::dump() {
    return mdata.dump();
}

int Table::insert(string row) {

    json json_row=json::parse(row);
    int resnum=0;
    for (int i = 0; i < json_row.size(); ++i) {
        json temp=json::array();
        int count=0;
        for (int j = 0; j < mcolumn.size(); ++j) {
            string columnname=mcolumn[j];
            if(!(bool)json_row[i][columnname.c_str()].is_null()){
                count++;
                temp[j]=(json_row[i][columnname.c_str()]);
            }else{
                temp[j]="";
            }
        }

        if(count==0)continue;
        mmaxid++;
        resnum++;
        mdata["maxid"]=mmaxid;

        json inserted;
        inserted["id"]=mmaxid;
        inserted["data"]=temp;
        mdata["rows"]+=inserted;
    }
    //cout<<mdata<<endl;
    return resnum;

}
json Table::select(){
    json result;
    result["column"]=mdata["column"];
    result["record"]=mdata["rows"];
    return result;
}
json select_minize(json data){
    json result;
    result["column"]=data["column"];
    for (int i = 0; i < data["record"].size(); ++i) {
        result["record"][i]=data["record"][i]["data"];
    }
    return result;
}