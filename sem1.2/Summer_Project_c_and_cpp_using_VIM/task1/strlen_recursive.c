#include "strlen.h"


int strlen_recursive(const char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + strlen_recursive(str + 1);
}
