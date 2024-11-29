#include "Grammar.h"

namespace grammar {
    language::Language Grammar::GenerateChains(size_t max_length)  {
        bool infinite = false;
        std::set<std::string> result;
        std::queue<std::string> queue;

        queue.emplace(1, start_symbol_);

        while (!queue.empty()) {
            std::string current_chain = queue.front();
            queue.pop();

            if (current_chain.size() > max_length) {
                infinite = true;
                continue;
            }

            if (IsTerminal(current_chain)) {
                result.insert(current_chain);
            }

            for (const auto& [left, right] : rules_) {
                auto pos = current_chain.find(left);  // Ищем первое вхождение s1 в s2

                while (pos != std::string::npos) {
                    for (const auto& replacement : right) {
                        std::string newChain = current_chain.substr(0, pos) + (replacement == "人" ? "" : replacement) + current_chain.substr(pos + left.size());
                        queue.push(newChain.empty() ? "人" : newChain);
                    }

                    pos = current_chain.find(left, pos + 1);
                }
            }
        }

        return {result, terminals_, infinite};
    }

    bool Grammar::IsTerminal(const std::string &chain)  {
        if (chain != "人") {
            for (char c : chain) {
                if (terminals_.find(c) == terminals_.end()) {
                    return false;
                }
            }
        }

        return true;
    }
}
