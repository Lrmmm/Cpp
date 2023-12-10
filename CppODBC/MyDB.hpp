#pragma once
#include <mysql/mysql.h>
#include <string>
using namespace std;
class MyDB{
public:
    MyDB();
    ~MyDB();
    bool initDB(string host, string user, string pwd, string db_name);
    bool executeSQL(string sql);
private:
    MYSQL *mysql;
    MYSQL_RES *result;
    MYSQL_ROW row;
};