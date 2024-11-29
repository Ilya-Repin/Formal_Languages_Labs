#include <iostream>
#include "src/Language.h"
#include "src/Grammar.h"

int main(){
    std::cout << "\033[93mЛАБОРАТОРНАЯ РАБОТА №1\033[0m" << std::endl;
    std::cout << "\n\033[93mЗАДАНИЕ №1\033[0m" << std::endl;

    language::Language l1({"ab", "bb", "ba"}, {'a', 'b'});
    language::Language l2({"ba", "bb", "b"}, {'a', 'b'});

    std::cout << "\033[32mЯзыки:\033[0m {ab, bb, ba} и {ba, bb, b}" << std::endl;

    auto united = l1.Union(l2);
    std::cout << "\033[32mа) Объединение L1 и L2: \033[0m" << united.GetString() << std::endl;

    auto intersection  = l1.Intersection(l2);
    std::cout << "\033[32mб) Пересечение L1 и L2: \033[0m" << intersection.GetString() << std::endl;

    auto subtraction_1 = l1.Subtraction(l2);
    std::cout << "\033[32mв) Разность L1 и L2: \033[0m" << subtraction_1.GetString() << std::endl;

    auto subtraction_2 = l2.Subtraction(l1);
    std::cout << "\033[32mг) Разность L2 и L1: \033[0m" << subtraction_2.GetString() << std::endl;

    auto addition_1 = l1.Addition(5);
    std::cout << "\033[32mд) Дополнение L1: \033[0m" << addition_1.GetString() << std::endl;

    auto addition_2 = l2.Addition(5);
    std::cout << "\033[32mе) Дополнение L2: \033[0m" << addition_2.GetString() << std::endl;

    auto concatanated_1 = l1.Concatenate(l2);
    std::cout << "\033[32mж) Конкатенация L1 и L2: \033[0m" << concatanated_1.GetString() << std::endl;

    auto concatanated_2 = l2.Concatenate(l1);
    std::cout << "\033[32mз) Конкатенация L2 и L1: \033[0m" << concatanated_2.GetString() << std::endl;

    std::cout << "\n\033[93mЗАДАНИЕ №2\033[0m" << std::endl;

    language::Language language({"01", "0101", "010101"}, {'0', '1'});

    auto curr = language;

    std::vector<std::string> l_plus{curr.GetString()};

    for (int i = 1; i <= 3; i++) {
        curr = language.Concatenate(curr);
        l_plus.push_back(curr.GetString());
    }

    std::cout << "\033[32mа)\033[0m" << " ";
    for (const auto& chains : l_plus) {
        std::cout << chains << " U ";
    }

    std::cout << "..." << std::endl;

    std::cout << "\033[32mб)\033[0m" << " {人} U ";

    for (const auto& chains : l_plus) {
        std::cout << chains << " U ";
    }

    std::cout << "..." << std::endl;

    std::cout << "\n\033[93mЗАДАНИЕ №3\033[0m" << std::endl;

    std::map<std::string, std::set<std::string>> rules_3 = {
        {"S", {"aA"}},
        {"A", {"aaA", "人"}}
    };

    grammar::Grammar grammar_3(rules_3, 'S', {'a'});
    auto language_3 = grammar_3.GenerateChains(10);

    std::cout << "\033[32mЯзык L(G): \033[0m" << language_3.GetString() << std::endl;

    std::cout << "\n\033[93mЗАДАНИЕ №4\033[0m" << std::endl;

    std::map<std::string, std::set<std::string>> rules_4 = {
        {"S", {"0A"}},
        {"A", {"0A", "1B", "0"}},
        {"B", {"1B", "C"}},
        {"C", {"0C", "0"}}
    };

    grammar::Grammar grammar_4(rules_4, 'S', {'0', '1'});

    auto language_4 = grammar_4.GenerateChains(8);

    std::cout << "\033[32mЯзык L(G): \033[0m" << language_4.GetString() << std::endl;

    return EXIT_SUCCESS;
}
