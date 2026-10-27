#include "clubhub/event_csv.hpp"
#include <sstream>
#include <stdexcept>
#include <charconv>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;
    
    if (!std::getline(in, line)) {
        return result; // empty file
    }
    
    while (std::getline(in, line)) {
        ++lineNo;
        
        // Strip a trailing '\r' if present (Windows line endings)
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        std::istringstream lineStream{line};
        std::string field;
        std::vector<std::string> fields;
        
        while (std::getline(lineStream, field, ',')) {
            fields.push_back(field);
        }
        
        // Handle a trailing comma creating an extra empty field if needed, 
        // but we strictly expect 5 fields: id, title, start, location, capacity
        if (lineStream.eof() && line.back() == ',') {
            fields.push_back("");
        }
        
        if (fields.size() != 5) {
            result.errors.push_back({lineNo, "expected 5 fields, got " + std::to_string(fields.size())});
            continue;
        }
        
        try {
            TimePoint start = parseTimePoint(fields[2]);
            
            int capacity = 0;
            auto [ptr, ec] = std::from_chars(fields[4].data(), fields[4].data() + fields[4].size(), capacity);
            if (ec != std::errc() || ptr != fields[4].data() + fields[4].size()) {
                throw std::invalid_argument("bad number '" + fields[4] + "'");
            }
            
            result.events.emplace_back(fields[0], fields[1], start, fields[3], capacity);
        } catch (const std::exception& e) {
            result.errors.push_back({lineNo, e.what()});
        }
    }
    
    return result;
}

} // namespace clubhub