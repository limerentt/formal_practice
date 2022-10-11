#include "Max_substring.h"

reg_exp::reg_exp(char c, char x) {
    full_word_x = (c == x);
    pref = post = root = (c == x ? 1 : 0);
    is_eps = (c == '1');
}

void process(char c, std::stack<reg_exp>& stack) {
    if (c == '*') {
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
        return;
    }

    reg_exp first, second;
    first = stack.top(), stack.pop();
    second = stack.top(), stack.pop();

    reg_exp new_reg_exp;

    if (first.is_eps) {
        stack.push(second);
        return;
    } else if (second.is_eps) {
        stack.push(first);
        return;
    }

    if (c == '.') {
        new_reg_exp.full_word_x = first.full_word_x && second.full_word_x;
        if (second.full_word_x) {
            new_reg_exp.pref = second.pref + first.pref;
        } else {
            new_reg_exp.pref = second.pref;
        }

        new_reg_exp.root = std::max(second.post + first.pref, std::max(first.root, second.root));

        if (first.full_word_x) {
            new_reg_exp.post = first.post + second.post;
        } else {
            new_reg_exp.post = first.post;
        }

    } else if (c == '+') {
        new_reg_exp.full_word_x = first.full_word_x || second.full_word_x;
        new_reg_exp.pref = std::max(first.pref, second.pref);
        new_reg_exp.post = std::max(first.post, second.post);
        new_reg_exp.root = std::max(first.root, second.root);
    }
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