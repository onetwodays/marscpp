#include <iostream>
#include "butil/logging.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    LOG(ERROR) << "Fail to add http_svc";
    return 0;
}
