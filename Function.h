#pragma once
#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
extern int rows;
namespace Function {
    inline void cls() {
        system("cls");
        return;
    }
    inline void goto_xy(HANDLE hOut, int x, int y) {
        COORD pos{};
        pos.X = x;
        pos.Y = y;
        SetConsoleCursorPosition(hOut, pos);
        return;
    }
    inline void middle(std::string str) {
        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO bInfo;
        GetConsoleScreenBufferInfo(hOutput, &bInfo);
        int dwSizeX = bInfo.dwSize.X, dwSizey = bInfo.dwSize.Y;
        int len = int(str.length()) - 1;
        int x = dwSizeX / 2 - len / 2;
        goto_xy(hOutput, x, rows++);
        std::cout << str;
        if (str == "Press any key to continue . . .") return;
        std::cout << std::endl;
        return;
    }
    inline void hide_cursor() {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO CursorInfo;
        GetConsoleCursorInfo(handle, &CursorInfo);
        CursorInfo.bVisible = false;
        SetConsoleCursorInfo(handle, &CursorInfo);
        return;
    }
    inline void show_cursor() {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO CursorInfo;
        GetConsoleCursorInfo(handle, &CursorInfo);
        CursorInfo.bVisible = true;
        SetConsoleCursorInfo(handle, &CursorInfo);
        return;
    }
    inline void press() {
        middle("Press any key to continue . . .");
        while (true) {
            if (_kbhit()) break;
        }
        return;
    }
    inline void set_title(std::string title) {
        SetConsoleTitle(title.c_str());
        return;
    }
    inline void erase_spaces(std::string& formula) {
        std::string formula1;
        int len = int(formula.size());
        for (int i = 0; i < len; i++) {
            if (formula[i] != ' ') formula1 += formula[i];
        }
        formula = formula1;
        return;
    }
    inline void transfer_lower(std::string& formula) {
        transform(formula.begin(), formula.end(), formula.begin(), ::tolower);
        return;
    }
}