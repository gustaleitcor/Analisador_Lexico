#include <vector>

namespace std
{
    template <>
    struct hash<std::vector<int>>
    {
        size_t operator()(const std::vector<int> &v) const
        {
            // Use uma combinação de hash para cada elemento no vetor
            size_t result = 17;
            for (const auto &elem : v)
            {
                result = result * 31 + std::hash<int>{}(elem);
            }
            return result;
        }
    };

    // Especialização de std::equal_to para std::vector<int>
    template <>
    struct equal_to<std::vector<int>>
    {
        bool operator()(const std::vector<int> &lhs, const std::vector<int> &rhs) const
        {
            // Compare os vetores elemento por elemento
            return lhs == rhs;
        }
    };
}