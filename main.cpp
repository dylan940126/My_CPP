#include <cstdio>
#include <string>

int main() {
    auto a = std::to_string(123.1);
    puts(a.c_str());
}