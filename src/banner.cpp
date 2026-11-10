

#include "clubhub/banner.hpp"

#include <cstddef>
#include <string>
#include <string_view>

namespace clubhub
{

    namespace
    {
        // Puts text in the middle of the 40-character space inside the frame
        std::string teamRow(const std::string &text)
        {
            const std::size_t inner = 40;
            std::string t = text.substr(0, inner);
            const std::size_t left = (inner - t.size()) / 2;
            const std::size_t right = inner - t.size() - left;
            return "|*#" + std::string(left, ' ') + t + std::string(right, ' ') + "#*|\n";
        }
    } // namespace

    std::string banner(std::string_view teamName)
    {
        std::string out;
        out += "/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n";
        out += "|********************************************|\n";
        out += "|*#========================================#*|\n";
        out += "|*#  [][][][][][][][][][][][][][][][][][]  #*|\n";
        out += "|*#            ITC Club Hub  v1            #*|\n";
        out += teamRow("Team: " + std::string(teamName));
        out += "|*#  [][][][][][][][][][][][][][][][][][]  #*|\n";
        out += "|*#========================================#*|\n";
        out += "|********************************************|\n";
        out += "\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/\n";
        return out;
    }

} // namespace clubhub