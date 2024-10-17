#include <stdio.h>
#include <stdbool.h>
#include <string>
#include "Stack.h"
// 检查括号是否匹配
int isMatched(const char* str) {
    SqStack S;
    InitStack(&S);
    for (int i = 0; str[i]; i++) {
        char e = ' ';
        switch (str[i]) {
        case '(': case '[': case '{':
            Push(&S, str[i]);
            break;
        case ')':
            if (StackEmpty(&S))
                return 0;
            Pop(&S, &e);
            if (e != '(')
                return 0;
            break;
        case ']':
            if (StackEmpty(&S))
                return 0;
            Pop(&S, &e);
            if (e != '[')
                return 0;
            break;
        case '}':
            if (StackEmpty(&S))
                return 0;
            Pop(&S, &e);
            if (e != '{')
                return 0;
            break;
        default:
            break; // 忽略其他字符
        }
    }
    return StackEmpty(&S); // 栈空则全部匹配
}

int main() {
    const char* testStr = "{[({)]}";
    if (isMatched(testStr)) {
        printf("括号匹配\n");
    }
    else {
        printf("括号不匹配\n");
    }
    return 0;
}
