#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"

typedef double SElemType;

// 定义运算符优先级
int Priority(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    default: return 0;
    }
}

// 执行运算
double Operate(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : 0; // 检查除数是否为零
    default: return 0;
    }
}

// 计算表达式
double EvaluateExpression(const char* expr) {
    SqStack numStack;
    OpStack opStack;
    InitStack(&numStack);
    InitOpStack(&opStack);
    double a, b, num;
    char op, c;

    while (*expr) {
        if (isdigit(*expr) || (*expr == '.')) {
            sscanf(expr, "%lf", &num);
            Push(&numStack, num);
            while (isdigit(*expr) || (*expr == '.')) expr++; // 跳过数字
        }
        else if (*expr == '(') {
            PushOp(&opStack, *expr);
            expr++;
        }
        else if (*expr == ')') {
            while (!StackEmptyOp(&opStack) && GetTopOp(&opStack) != '(') {
                PopOp(&opStack, &op);
                Pop(&numStack, &b);
                Pop(&numStack, &a);
                Push(&numStack, Operate(a, b, op));
            }
            if (!StackEmptyOp(&opStack)) PopOp(&opStack, &c); // 移除 '('
            expr++;
        }
        else {
            while (!StackEmptyOp(&opStack) && Priority(GetTopOp(&opStack)) >= Priority(*expr)) {
                PopOp(&opStack, &op);
                Pop(&numStack, &b);
                Pop(&numStack, &a);
                Push(&numStack, Operate(a, b, op));
            }
            PushOp(&opStack, *expr);
            expr++;
        }
    }

    while (!StackEmptyOp(&opStack)) {
        PopOp(&opStack, &op);
        Pop(&numStack, &b);
        Pop(&numStack, &a);
        Push(&numStack, Operate(a, b, op));
    }

    double result = GetTop(&numStack);
    return result;
}

int main() {
    const char* expr1 = "3+3*2.5";
    const char* expr2 = "(3+2)*2";
    const char* expr3 = "(1+2)*3";

    printf("Expression value of '%s': %f\n", expr1, EvaluateExpression(expr1));
    printf("Expression value of '%s': %f\n", expr2, EvaluateExpression(expr2));
    printf("Expression value of '%s': %f\n", expr3, EvaluateExpression(expr3));

    return 0;
}
