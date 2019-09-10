//
// Created by Devon Richards on 9/9/19.
//
#ifndef MTSPARKED_DOLLARVALUE_H
#define MTSPARKED_DOLLARVALUE_H

#include <cstddef>

struct dollarValue {
    explicit dollarValue(long dollarAmount) : amount(dollarAmount) { }
    explicit dollarValue(double dollarAmount) : amount(static_cast<long>(dollarAmount*100)) { }
    dollarValue(const dollarValue&) = default;
    dollarValue(dollarValue&&) = default;
    dollarValue& operator=(const dollarValue&) = default;
    dollarValue& operator=(dollarValue&&) = default;

    [[nodiscard]] double value() const {
        return static_cast<double>(this->amount) / 100.0;
    }

    [[nodiscard]] long dollars() const {
        return this->amount / 100;
    }

    [[nodiscard]] std::byte cents() const {
        return static_cast<std::byte>(this->amount % 100);
    }

    friend dollarValue operator+(const dollarValue& left, const dollarValue& right) {
        return dollarValue(left.amount + right.amount);
    }

    friend dollarValue& operator+=(dollarValue& left, const dollarValue& right) {
        left.amount += right.amount;
        return left;
    }

    friend dollarValue operator-(const dollarValue& left, const dollarValue& right) {
        return dollarValue(left.amount - right.amount);
    }

    friend dollarValue& operator-=(dollarValue& left, const dollarValue& right) {
        left.amount -= right.amount;
        return left;
    }

    friend dollarValue operator*(const dollarValue& left, double right) {
        return dollarValue(static_cast<long>(static_cast<double>(left.amount)*right));
    }

    friend dollarValue operator*(double left, const dollarValue& right) {
        return dollarValue(static_cast<long>(static_cast<double>(right.amount)*left));
    }

    friend dollarValue& operator*=(dollarValue& left, double right) {
        left.amount = static_cast<long>(static_cast<double>(left.amount)*right);
        return left;
    }

    friend dollarValue operator/(const dollarValue& left, double right) {
        return dollarValue(static_cast<long>(static_cast<double>(left.amount)/right));
    }

    friend dollarValue& operator/=(dollarValue& left, double right) {
        left.amount = static_cast<long>(static_cast<double>(left.amount)/right);
        return left;
    }

private:
    long amount;
};

#endif //MTSPARKED_DOLLARVALUE_H
