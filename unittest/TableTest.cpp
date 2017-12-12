
//
// Created by wzq on 12/12/17.
//

#include <gtest/gtest.h>
#include <Table.h>
TEST(Table,setname){
    Table table;
    table.setName("wzq");
    cout<<table.dump();
}

