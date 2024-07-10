#include "flags.h"
#include <regex>

DEFINE_bool(bool_var, false, "Test bool flag");
DEFINE_int32(int32_var, 0, "Test int32 flag");
DEFINE_int64(int64_var, 0, "Test int64 flag");
DEFINE_double(double_var, 0, "Test double flag");
DEFINE_string(str_var, "", "Test string flag");
DEFINE_string(multi_vd1, "", "Test flag for validator with validating function & flag in multiple source files");
DEFINE_string(multi_vd2, "", "Test flag for validator with flag in multiple source files");

// 不使用static修饰符，因为在main.cpp中使用了该函数
bool validate_multi_vd1(const char* flagname, const std::string &var)
{
    return true;
}

bool validate_multi_vd3(const char* flagname, const std::string &var)
{
    return true;
}
