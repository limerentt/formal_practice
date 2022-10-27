#include "Max_substring.h"

reg_exp::reg_exp(char c, char x):   full_word_x(c == x),
                                    pref(c == x),
                                    post(c == x),
                                    root(c == x),
                                    is_eps(c == '1') {}

void process_asterisk(std::stack<reg_exp>& stack) {
    reg_exp new_reg_exp = stack.top();
    stack.pop();
    if (new_reg_exp.full_word_x) {
        std::cout << "INF";
        new_reg_exp.inf_captured = true;
        stack.push(new_reg_exp);
        return;
    }
    new_reg_exp.root = std::max(new_reg_exp.root, new_reg_exp.pref + new_reg_exp.post);
    stack.push(new_reg_exp);
}

void process_concatenation(reg_exp& new_reg_exp, reg_exp& first, reg_exp& second) {
    new_reg_exp.full_word_x = first.full_word_x && second.full_word_x;
    new_reg_exp.pref = (second.full_word_x ? second.pref + first.pref : second.pref);
    new_reg_exp.root = std::max(second.post + first.pref, std::max(first.root, second.root));
    new_reg_exp.post = (first.full_word_x ? first.post + second.post : first.post);
}

void process_plus(reg_exp& new_reg_exp, reg_exp& first, reg_exp& second) {
    new_reg_exp.full_word_x = first.full_word_x || second.full_word_x;
    new_reg_exp.pref = std::max(first.pref, second.pref);
    new_reg_exp.post = std::max(first.post, second.post);
    new_reg_exp.root = std::max(first.root, second.root);
}

void process(char c, std::stack<reg_exp>& stack) {
    if (c == '*') {
        process_asterisk(stack);
        return;
    }

    reg_exp new_reg_exp, first, second;
    first = stack.top(), stack.pop();
    second = stack.top(), stack.pop();

    if (first.is_eps || second.is_eps) {
        (first.is_eps ? stack.push(second) : stack.push(first));
        return;
    }
    (c == '.' ? process_concatenation(new_reg_exp, first, second) : process_plus(new_reg_exp, first, second));
    stack.push(new_reg_exp);
}


bool is_exp_correct(const std::stack<reg_exp>& stack, char c) {
    if ((c == '.' || c == '+') && stack.size() < 2) return false;
    if (c == '*' && stack.empty()) return false;
    return true;
}


int Max_substring::find_substring(std::string expression, char x) {
    std::stack<reg_exp> stack;
    for (auto c: expression) {
        if (!is_exp_correct(stack, c)) {
            std::cout << "ERROR";
            return 0;
        }
        if (c == '.' || c == '*' || c == '+') {
            process(c, stack);
            if (stack.top().inf_captured) { return 0; }
        } else {
            stack.push(reg_exp(c, x));
        }
    }
    if (stack.size() > 1) {
        std::cout << "ERROR";
        return 0;
    }

    std::cout << stack.top().root;
    return 0;
}
