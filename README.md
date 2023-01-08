# **Calculator** ***(0.1)***
![Github stars](https://img.shields.io/github/stars/lpyNeil/Calculator.svg)
[![Bugs](https://img.shields.io/github/issues/lpyNeil/Calculator)](https://github.com/lpyNeil/Calculator/issues?utf8=✓&q=is%3Aissue+is%3Aopen+label%3Abug)
[![Gitter](https://badges.gitter.im/lpyNeil/community.svg)](https://gitter.im/lpyNeil/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
### An open source C++ calculator project
***
### Implementation process:

### 1. Input

### 2. Calculation

### 3. Output
***
## 1.Input

Use the **string** type input, delete the extra spaces in the **formula**, make them all lowercase, and then start to check whether the **formula** is legal.

- ### Input part:

	The **std** namespace is not used because it is a header file.
- ### Inspection part:

	"**len**" is the length of the **formula**. Loop through the **formula** to check whether there are illegal characters. If not, **flag** is **true**; If yes, **flag** value is still **false**, and then the original formula is output to the "**formula.txt**" file. It is convenient for next input.
***
**erase_space(std::string** **formula)** function is used to delete all spaces in the input.

Code：

```cpp
inline void erase_spaces(std::string& formula) {
    std::string formula1;
    int len = int(formula.size());
    for (int i = 0; i < len; i++) {
        if (formula[i] != ' ') formula1 += formula[i];
    }
    formula = formula1;
    return;
}
```
***
**transfer_lower(std::string** **formula)** function is used to lower case the input.

Code：

```cpp
inline void transfer_lower(std::string& formula) {
    transform(formula.begin(), formula.end(), formula.begin(), ::tolower);
    return;
}
```
***
The header file **"Users.h"** code is as follows:
```cpp
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Function.h"     //Header file
using namespace Function; // Header file
int char_num = 29;        // Number of legal characters, used in the "for" loop
char character[] =
{ '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
 '+', '-', '*', '/', '=', '!', '%', '^', '(', ')',
 '[', ']', '{', '}', '.', '<', '>', 'x', 'y' }; // Legal characters
class Calculator {
public:
    Calculator() {
        input();
    }
    inline void input() {
        std::string formula;
        getline(std::cin, formula);
        erase_spaces(formula);   // Functions defined in "Function.h"
        transfer_lower(formula); // Functions defined in "Function.h"
        check(formula);          // Functions defined in "Function.h"
        return;
    }
    inline void check(std::string formula) { // Check whether the formula is legal
        int len = int(formula.size());
        bool flag = false, flag1 = false;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < char_num; j++) {
                if (formula[i] == character[j]) {
                    flag = true; // Legal is true
                    break;
                }
            }
            if (!flag) {
                if (!flag1) {
                    flag1 = true;
                    std::cout << "Error:" << std::endl; // Illegal characters appear
                }
                std::cout << "  \"" << formula[i] << "\"" << ":illegal character" << std::endl; // Output illegal characters
            }
        }
        if (!flag) {
            std::ofstream outf;
            outf.open("Formula.txt");
            outf << formula; // Output the original formula to a file for the next input
            outf.close();
            std::cout << "  The original formula has been output to the file." << std::endl;
        }
        return;
    }
};
```
To be updated.