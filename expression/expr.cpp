#include "expr.h"
#include <stdexcept>

expr::~expr() = default;

double number::explain() {
    return val_;
}

symbol::~symbol() {
    delete l_;
    delete r_;
}

double add::explain() {
    return l_->explain() + r_->explain();
}

double minus::explain() {
    return l_->explain() - r_->explain();
}

double mul::explain() {
    return l_->explain() * r_->explain();
}

double div::explain() {
    const double r_val = r_->explain();
    if (r_val == 0.0) {
        throw std::runtime_error("Division by zero");
    }

    return l_->explain() / r_val;
}
