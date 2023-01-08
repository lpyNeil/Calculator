#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "Function.h"
using namespace Function;
const int char_num = 29;
char character[char_num] =
{ '1','2','3','4','5','6','7','8','9','0',
  '+','-','*','/','=','!','%','^','(',')',
  '[',']','{','}','.','<','>','x','y' };
class Calculator {
public:
    Calculator() {
        set_title("Calculator");
        input();
    }
    inline void input() {
        std::string formula;
        getline(std::cin, formula);
        erase_spaces(formula);
        transfer_lower(formula);
        check(formula);
        return;
    }
    inline void check(std::string formula) {
        int len = int(formula.size());
        bool flag = false, flag1 = false;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < char_num; j++) {
                if (formula[i] == character[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                if (!flag1) {
                    flag1 = true;
                    std::cout << "Error:" << std::endl;
                }
                std::cout << "  \"" << formula[i] << "\"" << ":illegal character" << std::endl;
            }
        }
        if (!flag) {
            std::ofstream outf;
            outf.open("Formula.txt");
            outf << formula;
            outf.close();
            std::cout << "  The original formula has been output to the file." << std::endl;
        }
        return;
    }
};