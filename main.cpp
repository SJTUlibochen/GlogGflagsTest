#include <iostream>
#include <glog/logging.h>
#include <gflags/gflags.h>
#include "include/flags.h"
#include "include/helloworld.h"

// 推荐的validator使用方法，在同一个源文件中定义检查函数、命令行标志和检查器
static bool validate_std(const char* flagname, int var) {
   if (var > 0 && var < 32768)
     return true;
   std::cout << "Invalid value for --" << flagname << ": " << var << std::endl;
   return false;
}
DEFINE_int32(port, 0, "What port to listen on");
DEFINE_validator(port, &validate_std);

// validator测试情况3，在同一个源文件中定义命令行标志和检查器，但是检查器函数在另一个源文件中定义"
DEFINE_string(multi_vd3, "", "Test flag for validator with validating function in multiple source files");
DEFINE_validator(multi_vd3, &validate_multi_vd3);

// validator测试情况2，在同一个源文件中定义检查函数和检查器，但是命令行标志在另一个源文件中定义
static bool validate_multi_vd2(const char* flagname, const std::string &var)
{
    return true;
}
DEFINE_validator(multi_vd2, &validate_multi_vd2);

// validator测试情况1，仅在使用validator的源文件中定义检查器，检查函数和命令行标志都在另一个源文件中定义
DEFINE_validator(multi_vd1, &validate_multi_vd1);

int main(int argc, char* argv[]){
    std::cout << "This is a test program for glog and gflags. Check source code for detailed documentation" << std::endl;

    // 输出gflags解析前的argc和argv
    std::cout << "Before gflags parse, " << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for(int i = 0; i < argc; i++){
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    // 解析gflags，argc和argv与main函数对应
    gflags::ParseCommandLineFlags(&argc, &argv, false);

    // 输出gflags解析后的argc和argv
    std::cout << "After gflags parse, " << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for(int i = 0; i < argc; i++){
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    // 通过gflags设置glog的日志目录
    // FLAGS_log_dir = "./logs/";

    // 初始化glog
    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "This is a test log message";
    LOG(INFO) << "Log output directory is: " << FLAGS_log_dir;

    helloworld();

    // 输出gflags解析后的flag值
    std::cout << "This program will test the following flags, " << std::endl;
    std::cout << "bool flag: " << FLAGS_bool_var << std::endl;
    std::cout << "int32 flag: " << FLAGS_int32_var << std::endl;
    std::cout << "int64 flag: " << FLAGS_int64_var << std::endl;
    std::cout << "double flag: " << FLAGS_double_var << std::endl;
    std::cout << "string flag: " << FLAGS_str_var << std::endl;
    std::cout << "port validator flag: " << port_validator_registered << std::endl;
    std::cout << "multi_vd1 validator flag: " << multi_vd1_validator_registered << std::endl;
    std::cout << "multi_vd2 validator flag: " << multi_vd2_validator_registered << std::endl;
    std::cout << "multi_vd3 validator flag: " << multi_vd3_validator_registered << std::endl;
}
