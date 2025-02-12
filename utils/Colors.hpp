#pragma once

#include <iostream>
#include <string>


const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string BLACK = "\033[30m";

const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";
const std::string BLINK = "\033[5m";
const std::string REVERSE = "\033[7m";
const std::string HIDDEN = "\033[8m";

const std::string BG_BLACK = "\033[40m";
const std::string BG_RED = "\033[41m";
const std::string BG_GREEN = "\033[42m";
const std::string BG_YELLOW = "\033[43m";
const std::string BG_BLUE = "\033[44m";
const std::string BG_MAGENTA = "\033[45m";
const std::string BG_CYAN = "\033[46m";
const std::string BG_WHITE = "\033[47m";

const std::string RESET = "\033[0m";

std::string bold(const std::string &text) {
    return BOLD + text + RESET;
}

std::string underline(const std::string &text) {
    return UNDERLINE + text + RESET;
}

std::string blink(const std::string &text) {
    return BLINK + text + RESET;
}

std::string reverse(const std::string &text) {
    return REVERSE + text + RESET;
}

std::string hidden(const std::string &text) {
    return HIDDEN + text + RESET;
}



std::string color(const std::string &text, const std::string &color) {
    return color + text + RESET;
}

std::string red(const std::string &text) {
    return RED + text + RESET;
}

std::string green(const std::string &text) {
    return GREEN + text + RESET;
}

std::string yellow(const std::string &text) {
    return YELLOW + text + RESET;
}

std::string blue(const std::string &text) {
    return BLUE + text + RESET;
}

std::string magenta(const std::string &text) {
    return MAGENTA + text + RESET;
}

std::string cyan(const std::string &text) {
    return CYAN + text + RESET;
}

std::string white(const std::string &text) {
    return WHITE + text + RESET;
}

std::string black(const std::string &text) {
    return BLACK + text + RESET;
}




std::string bg_color(const std::string &text, const std::string &color) {
    return color + text + RESET;
}

std::string bg_black(const std::string &text) {
    return BG_BLACK + text + RESET;
}

std::string bg_red(const std::string &text) {
    return BG_RED + text + RESET;
}

std::string bg_green(const std::string &text) {
    return BG_GREEN + text + RESET;
}

std::string bg_yellow(const std::string &text) {
    return BG_YELLOW + text + RESET;
}

std::string bg_blue(const std::string &text) {
    return BG_BLUE + text + RESET;
}

std::string bg_magenta(const std::string &text) {
    return BG_MAGENTA + text + RESET;
}

std::string bg_cyan(const std::string &text) {
    return BG_CYAN + text + RESET;
}

std::string bg_white(const std::string &text) {
    return BG_WHITE + text + RESET;
}