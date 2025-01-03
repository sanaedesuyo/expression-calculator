#pragma once

class expr {
public:
    virtual ~expr() = 0;
    virtual double explain() = 0;
};

class number final : public expr {
protected:
    double val_;
public:
    explicit number(const double val) : val_(val) {}
    double explain() override;

    ~number() override = default;
};

class symbol : public expr {
protected:
    expr* l_;
    expr* r_;
public:
    symbol(expr* l, expr* r)
        : l_(l),
          r_(r) {}
    ~symbol() override;
};

class add final : public symbol {
public:
    add(expr* l, expr* r)
        : symbol(l, r) {
    }

    double explain() override;
};

class minus final : public symbol {
public:
    minus(expr* l, expr* r)
        : symbol(l, r) {
    }

    double explain() override;
};

class mul final : public symbol {
public:
    mul(expr* l, expr* r)
        : symbol(l, r) {
    }

    double explain() override;
};

class div final : public symbol {
public:
    div(expr* l, expr* r)
        : symbol(l, r) {
    }

    double explain() override;
};
