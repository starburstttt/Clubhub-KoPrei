// SPDX-License-Identifier: TODO (Task 3)
#include "clubhub/Student.h"

#include <cctype>
#include <stdexcept>
#include <utility>

namespace clubhub {

namespace {

// Digits, '+' and ' ' only, with at least one digit.
bool validPhone(const std::string& p) {
    bool hasDigit = false;
    for (char c : p) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigit = true;
        } else if (c != '+' && c != ' ') {
            return false;
        }
    }
    return hasDigit;
}

}  // namespace

Student::Student(std::string id, std::string name, std::string email)
    : id_(std::move(id)), name_(std::move(name)), email_(std::move(email)) {
    if (id_.empty()) throw std::invalid_argument("student id is empty");
    if (name_.empty()) throw std::invalid_argument("student name is empty");
    if (email_.find('@') == std::string::npos) {
        throw std::invalid_argument("email must contain '@'");
    }
}

void Student::giveSmsConsent(std::string phone) {
    if (!validPhone(phone)) {
        throw std::invalid_argument("phone may only contain digits, '+' and spaces");
    }
    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept { phone_.reset(); }

std::string Student::redacted() const {
    return "Student{id=" + maskId(id_) + "}";
}

std::string maskId(std::string_view id) {
    if (id.size() <= 3) return std::string(id.size(), '*');
    std::string out;
    out += id.substr(0, 2);
    out.append(id.size() - 3, '*');
    out += id.back();
    return out;
}

}  // namespace clubhub