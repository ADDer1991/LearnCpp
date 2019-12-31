#include <iostream>
#include <string>
#include <fstream>
#include "json.h"
#include "reader.h"

using namespace std;

void json_rd_test(void)
{
    string filename = "./test/test.json";
    ofstream ofs(filename);
    Json::Reader reader;
    Json::Value  obj;
    
    if(!ofs.is_open())
    {
        cout << "Open file:" << filename << " failed!" << endl;
        return;
    }

    /* 写入obj */
    obj["name"] = filename;
    ofs << obj.toStyledString();
    ofs.close();

    /* 读取obj */
    ifstream ifs(filename);
    if(!reader.parse(ifs, obj))
    {
        cout << "Parse " << filename << " failed!" << endl;
        ifs.close();
        return;
    }
    string str;
    str = obj["name"].asString();
    cout << "name: " << str << endl;
    ifs.close();
    
}

int main(int argc, char **argv)
{
    cout << "This is project: LearnCpp." << endl;
    json_rd_test();
    return 0;
}