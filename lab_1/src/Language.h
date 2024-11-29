#pragma once
#include <set>
#include <string>
#include <utility>

namespace language {

    class Language {
    public:
        template <class Compare = std::less<std::string>>
        Language(std::set<std::string, Compare> chains, std::set<char> terminals, bool infinite = false) {
            chains_.insert(chains.begin(), chains.end());
            infinite_ = infinite;
            terminals_ = std::move(terminals);
        }

        ~Language() = default;

        std::string GetString();

        Language Union(const Language &other);
        Language Intersection(const Language &other);
        Language Subtraction(const Language &other);
        Language Addition(size_t n);
        Language Concatenate(const Language &other);

    private:
        struct CompareByLength {
            bool operator()(const std::string& s1, const std::string& s2) const {
                if (s1.size() != s2.size()) {
                    return s1.size() < s2.size();
                }

                return s1 < s2;
            }
        };

        Language GenerateChains(size_t n);

        std::set<std::string, CompareByLength> chains_;
        bool infinite_{};
        std::set<char> terminals_;
    };

}
