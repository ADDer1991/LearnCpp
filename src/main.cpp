#include <iostream>
#include <string>
#include <fstream>
#include "json.h"
#include "reader.h"

using namespace std;

void json_rd_test(void)
{
    string filename = "./test/json_rd_test.json";
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

void system_cmd_test(void)
{
    string filename = "system_cmd_test.txt";
    string filepath = "../test/";
    string file     = filepath + filename;
    ofstream ofs(file);
    if(!ofs.is_open())
    {
        cout << "Open file:" << filename << " failed!" << endl;
        return;
    }
    ofs << "hello world" << endl;
    ofs.close();
    
    system("ls -l ../test/");
    string cmd = "find " + filepath + " -type f -mtime -2 -exec rm {} \\;";   //查找 ./test/ 文件夹下修改时间为2天内的文件并删除
    cout << cmd << endl;
    system(cmd.c_str());
    system("ls -l ../test/");
}

int main(int argc, char **argv)
{
    cout << "This is project: LearnCpp." << endl;
    //json_rd_test();
    system_cmd_test();
    return 0;
}