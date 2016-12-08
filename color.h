#ifndef COLOR_H
#define COLOR_H

#include <ostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>

namespace Color {
    enum Code {
        FG_BLACK    = 00,
        FG_BLUE     = 01,
        FG_GREEN    = 02,
        FG_AQUA	    = 03,
        FG_RED      = 04,
        FG_PURPLE   = 05,
        FG_YELLOW   = 06,
        FG_GRAY     = 08,
        FG_LBLUE    = 09,
        FG_LGREEN   = 10,
        FG_LAQUA    = 11,
        FG_LRED     = 12,
        FG_LPURPLE  = 13,
        FG_LYELLOW  = 14,
        FG_DEFAULT  = 07,
    };

    class Modifier {
    private:
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream& operator<<(std::ostream &os, const Modifier &mod)
        {
            HANDLE  hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

            SetConsoleTextAttribute(hConsole, mod.code);

            return os << "test";
        }
    };
}

#else

namespace Color {
    enum Code {
        FG_BLACK    = 30,
        FG_BLUE     = 34,
        FG_GREEN    = 32,
        FG_AQUA     = 36,
        FG_RED      = 31,
        FG_PURPLE   = 35,
        FG_YELLOW   = 33,
        FG_GRAY     = 37,
        FG_LBLUE    = 94,
        FG_LGREEN   = 92,
        FG_LAQUA    = 96,
        FG_LRED     = 91,
        FG_LPURPLE  = 95,
        FG_LYELLOW  = 93,
        FG_DEFAULT  = 39,
    };

    class Modifier {
    private:
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream& operator<<(std::ostream &os, const Modifier &mod)
        {
            return os << "\033[" << mod.code << "m";
        }
    };
}

#endif // not windows

namespace Color {
    const Color::Modifier BLACK(Color::FG_BLACK);
    const Color::Modifier BLUE(Color::FG_BLUE);
    const Color::Modifier GREEN(Color::FG_GREEN);
    const Color::Modifier AQUA(Color::FG_AQUA);
    const Color::Modifier RED(Color::FG_RED);
    const Color::Modifier PURPLE(Color::FG_PURPLE);
    const Color::Modifier YELLOW(Color::FG_YELLOW);
    const Color::Modifier GRAY(Color::FG_GRAY);
    const Color::Modifier LBLAY(Color::FG_LBLUE);
    const Color::Modifier LGREEN(Color::FG_LGREEN);
    const Color::Modifier LAQUA(Color::FG_LAQUA);
    const Color::Modifier LRED(Color::FG_RED);
    const Color::Modifier LPURPLE(Color::FG_LPURPLE);
    const Color::Modifier LYELLOW(Color::FG_YELLOW);
    const Color::Modifier DEF(Color::FG_DEFAULT);
}

#endif // COLOR_H
