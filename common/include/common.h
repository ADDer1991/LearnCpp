#ifndef __COMMON_H__
#define __COMMON_H__

#include <memory>

class data
{
private:
    int dat;
public:
    void set_data(int input){ dat = input; }
    int get_data(){ return dat; }
};

class common
{
private:
    int x;
public:
    common();
    ~common();
    std::unique_ptr<data> p_data;
    int get_value();
    void set_value(int input);
};

#endif