#include <iostream>
#include <string>
#include <fstream>
#include "json.h"
#include "reader.h"
#include "glfw_ui.h"
#include "main.h"
#include "common.h"
#include "grammar.h"

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

void syscmd(string str)
{
    cout << endl << str <<endl;
    system(str.c_str());
}

void system_cmd_test(void)
{
    string filename = "system_cmd_test.txt";
    string filepath = "../test/";
    string file     = filepath + filename;
    string cmd;
    ofstream ofs(file);
    if(!ofs.is_open())
    {
        cout << "Open file:" << filename << " failed!" << endl;
        return;
    }
    ofs << "hello world" << endl;
    ofs.close();
    
    syscmd("ls -l " + filepath);
    syscmd("stat " + file);

    cmd = "touch -d \"3 day ago\" " + file;  //将文件时间设置为3天前
    syscmd(cmd);
    syscmd("stat " + file);

    // 查找 filepath 文件夹下修改时间为 date天 内(外)的文件并删除
    int date = 2;
    string str_date = (date > 0) ? ("+" + to_string(date)) : to_string(date);
    cmd = "find " + filepath + " -type f -mtime " + str_date + " -exec rm {} \\;";   
    syscmd(cmd);
    syscmd("ls -l " + filepath);
}

int main(int argc, char **argv)
{
    cout << "This is project: LearnCpp." << endl;
    grammar gram;
    //json_rd_test();
    //system_cmd_test();
    //glfw_main();
    //glfw_example_triangle();
    //imgui_glfw_opengl3_emample_main();
    gram.test();
    return 0;
}