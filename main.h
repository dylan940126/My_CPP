//
// Created by suen3 on 2022/11/20.
//

#ifndef CLION_MAIN_H
#define CLION_MAIN_H

#include <vector>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstdint>

inline int readInt() {
    int x = 0, c = getchar();
    bool neg = false;
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    if (c == '-')
        neg = true, c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return neg ? -x : x;
}

#endif //CLION_MAIN_H
