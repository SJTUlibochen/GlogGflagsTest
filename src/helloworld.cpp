#include <glog/logging.h>

void helloworld() {
    LOG(INFO) << "Hello, World!";
    LOG(WARNING) << "This is a test warning message";
}