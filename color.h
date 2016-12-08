#ifndef COLOR_H
#define COLOR_H

#include <ostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>

namespace Color {
    enum Code {
        FG_RED      = 04,
        FG_GREEN    = 02,
        FG_BLUE     = 01,
        FG_DEFAULT  = 07,
        BG_RED      = 74,
        BG_GREEN    = 72,
        BG_BLUE     = 71,
        BG_DEFAULT  = 07
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

            return os;
        }
    };
}

#else

namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
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
    const Color::Modifier fg_red(Color::FG_RED);
    const Color::Modifier fg_blue(Color::FG_BLUE);
    const Color::Modifier fg_green(Color::FG_GREEN);
    const Color::Modifier bg_red(Color::BG_RED);
    const Color::Modifier bg_blue(Color::BG_BLUE);
    const Color::Modifier bg_green(Color::BG_GREEN);
    const Color::Modifier def(Color::FG_DEFAULT);
}

#endif // COLOR_H
