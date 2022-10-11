#include <iostream>
#include <string>
#include <stack>

class reg_exp {
public:
    reg_exp() = default;
    reg_exp(char c, char x);
    int pref = 0;
    int post = 0;
    int root = 0;
    bool full_word_x = false;
    bool is_eps = false;
    bool inf_captured = false;
};

namespace Max_substring {
    int find_substring(std::string expression, char x);
}

void process(char c, std::stack<reg_exp>& stack);
bool is_exp_correct(const std::stack<reg_exp>& stack, char c);

//#ifndef FORMAL_PRACTICE__MAX_SUBSTRING_H_
//#define FORMAL_PRACTICE__MAX_SUBSTRING_H_

//#endif //FORMAL_PRACTICE__MAX_SUBSTRING_H_
