#include "MyDB.hpp"
#include <iostream>
#include <random>
#include <string.h>
using namespace std;

int main()
{
    MyDB db;
    db.initDB("localhost","root","Xhy197597.","demo");
    db.executeSQL("select * from t1");
    for(int i = 10; i <= 100000; i++){
        char buffer[200];
        const char* str = "Hello world";
        int vb = random();
        int vc = random();
        int vd = random();
        sprintf(buffer,"insert into t1 values(%d,%d,%d,%d,'d');",i,vb,vc,vd,str);
        string sql(buffer,strlen(buffer));
        db.executeSQL(sql);

    }
    return 0;
}