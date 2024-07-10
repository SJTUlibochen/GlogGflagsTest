#ifndef FLAGS_H
#define FLAGS_H

#include <gflags/gflags.h>

DECLARE_bool(bool_var);
DECLARE_int32(int32_var);
DECLARE_int64(int64_var);
DECLARE_double(double_var);
DECLARE_string(str_var);
DECLARE_string(multi_vd1);
DECLARE_string(multi_vd2);
bool validate_multi_vd1(const char* flagname, const std::string& var);
bool validate_multi_vd3(const char* flagname, const std::string& var);

#endif