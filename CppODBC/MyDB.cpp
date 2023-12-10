#include "MyDB.hpp"
#include <iostream>
#include <string>
using namespace std;

MyDB::MyDB()
{
    mysql = mysql_init(NULL);
    if (mysql == NULL){
        cout << "Error:" << mysql_error(mysql);
        exit(1);
    }
}

MyDB::~MyDB(){
    if (mysql != NULL)
        mysql_close(mysql);
}

bool MyDB::initDB(string host, string user, string passwd, string db_name)
{
    mysql = mysql_real_connect(mysql, host.c_str(), user.c_str(), passwd.c_str(), db_name.c_str(), 0, NULL, 0);
    if (!mysql){
        cout << "Error:" << mysql_error(mysql);
        exit(1);
    }
    return true;
}

bool MyDB::executeSQL(string sql)
{
    // mysql_query执行成功返回0，不成功返回非0
    if (mysql_query(mysql,sql.c_str())){
        cout << "Query Error: " << mysql_error(mysql);
        return false;
    }
    
    result = mysql_store_result(mysql);
    if (result)
    {
        int num_fields = mysql_num_fields(result);
        int num_rows = mysql_num_rows(result);
        for (int i=0 ; i < num_rows; i++)
        {
            row = mysql_fetch_row(result);
            if(row < 0)
                break;
            for(int j=0; j < num_fields; j++)
                cout << row[j] <<"\t\t";
            cout << endl;
        }
    }
    else{
        if(mysql_field_count(mysql) == 0)
            int num_rows = mysql_affected_rows(mysql);
        else{
            cout << "Get result error:"<<mysql_error(mysql);
        }
    }

    return true;
}