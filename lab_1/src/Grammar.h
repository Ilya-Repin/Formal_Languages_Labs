#pragma once
#include <set>
#include <map>
#include <string>
#include <queue>
#include "Language.h"


namespace grammar {
    class Grammar {
    public:
        Grammar() = delete;

        Grammar(const std::map<std::string, std::set<std::string> > &rules, char startSymbol,
                const std::set<char> &terminals) : rules_(rules), start_symbol_(startSymbol), terminals_(terminals) {
        }

        language::Language GenerateChains(size_t max_length);

    private:
        bool IsTerminal(const std::string &chain);

        const std::map<std::string, std::set<std::string> > rules_;
        const char start_symbol_;
        const std::set<char> terminals_;
    };
}
