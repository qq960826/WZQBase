
//
// Created by wzq on 12/12/17.
//

#include <gtest/gtest.h>
#include <Table.h>
#include <Util.h>
#include <fstream>
using namespace std;
TEST(Table,setname){
    Table table;
    table.setName("wzq");
    cout<<table.dump();
}
TEST(Table,loadtest){
    Table table;
    string testcase1="{\"name\":\"wzq\",\"maxid\":0,\"column\":[\"name\",\"class\"]}";

    table.load(testcase1);
}

TEST(Table,inserttest){

    Table table;
    string testcase1=Util::ReadFileToString("/Users/wzq/Documents/WZQBase/table.json");
    string testcase2=Util::ReadFileToString("/Users/wzq/Documents/WZQBase/a.json");
    table.load(testcase1);

    table.insert(testcase2);
    json temp=table.select();
    cout<<temp<<endl;
    temp=select_minize(temp);
    cout<<temp<<endl;
}
