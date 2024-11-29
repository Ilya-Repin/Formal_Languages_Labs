#include "Language.h"

namespace language {
    std::string Language::GetString()  {
        std::string result = "{";
        size_t i = 0;

        for (const auto& chain : chains_) {
            result += chain + (i++ < chains_.size() - 1 ? ", ": "");
        }

        if (infinite_) {
            result += " ...";
        }

        result += "}";

        return result;
    }

    Language Language::Union(const Language &other) {
        auto union_terminals = terminals_;
        union_terminals.insert(other.terminals_.begin(), other.terminals_.end());

        Language result{chains_, union_terminals, infinite_ || other.infinite_};
        result.chains_.insert(other.chains_.begin(), other.chains_.end());

        return result;
    }

    Language Language::Intersection(const Language &other) {
        auto union_terminals = terminals_;
        union_terminals.insert(other.terminals_.begin(), other.terminals_.end());
        Language result({}, union_terminals, infinite_ && other.infinite_);

        for (const auto &chain : other.chains_) {
            if (chains_.find(chain) != chains_.end()) {
                result.chains_.insert(chain);
            }
        }

        return result;
    }

    Language Language::Subtraction(const Language &other) {
        auto union_terminals = terminals_;
        union_terminals.insert(other.terminals_.begin(), other.terminals_.end());
        Language result({}, union_terminals, infinite_);

        for (const auto& chain : chains_) {
            if (other.chains_.find(chain) == other.chains_.end()) {
                result.chains_.insert(chain);
            }
        }

        return result;
    }

    Language Language::Addition(size_t n) {
        auto v_star = GenerateChains(n);

        return v_star.Subtraction(*this);
    }

    Language Language::Concatenate(const Language &other) {
        auto union_terminals = terminals_;
        union_terminals.insert(other.terminals_.begin(), other.terminals_.end());
        Language result({}, union_terminals);

        for (const auto& chain1 : chains_) {
            for (const auto& chain2 : other.chains_) {
                result.chains_.insert(chain1 + chain2);  // Concatenate each pair of chains
            }
        }

        return result;
    }

    Language Language::GenerateChains(size_t n)  {
        std::set<std::string> chains{"人"};

        for (auto terminal : terminals_) {
            chains.insert({terminal});
        }

        for (size_t i = 2; i <= n; ++i) {
            std::set<std::string> new_chains;

            for (const auto& chain : chains) {
                for (auto terminal : terminals_) {
                    if (chain != "人") {
                        new_chains.insert(chain + terminal);
                    }
                }
            }

            chains.insert(new_chains.begin(), new_chains.end());
        }

        return {chains, terminals_, true};
    }
}
