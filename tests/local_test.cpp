#include "../src/Max_substring.h"

int main() {
    std::string expression;
    char x;

    std::cin >> expression >> x;

    Max_substring::find_substring(expression, x);

    return 0;
}
