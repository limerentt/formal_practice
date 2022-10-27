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
void process_asterisk(std::stack<reg_exp>& stack);
void process_concatenation(reg_exp& new_reg_exp, reg_exp& first, reg_exp& second);
void process_plus(reg_exp& new_reg_exp, reg_exp& first, reg_exp& second);
bool is_exp_correct(const std::stack<reg_exp>& stack, char c);
