#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
#ifndef _COMPILETIMESTRING_H_
#define _COMPILETIMESTRING_H_

#include <string>

template<size_t Length>
struct CompileTimeString {
    using char_array = const char (&)[Length + 1];
    using string = std::string;
    using value_type = char;
    using reference = const char&;
    using const_reference = const char&;
    using pointer = const char*;
    using const_pointer = const char*;
    using iterator = const char*;
    using const_iterator = const char*;
    using difference_type = std::ptrdiff_t;
    using size_type = std::size_t;

    constexpr CompileTimeString(char_array chars) noexcept : value(chars) { }
    constexpr CompileTimeString(const CompileTimeString&) noexcept = default;
    constexpr CompileTimeString(CompileTimeString&&) noexcept = default;
    constexpr CompileTimeString& operator=(const CompileTimeString&) = delete;
    constexpr CompileTimeString& operator=(CompileTimeString&&) = delete;

    char_array value;

    [[nodiscard]] operator string() const noexcept {
        return std::string(value, Length);
    }

    [[nodiscard]] constexpr operator char_array() const noexcept {
        return value;
    }

    [[nodiscard]] constexpr iterator begin() const noexcept {
        return value;
    }

    [[nodiscard]] constexpr const_iterator cbegin() const noexcept {
        return value;
    }

    [[nodiscard]] constexpr iterator end() const noexcept {
        return static_cast<const char*>(this->value) + Length;
    }

    [[nodiscard]] constexpr const_iterator cend() const noexcept {
        return static_cast<const char*>(this->value) + Length;
    }

    [[nodiscard]] constexpr size_type size() const noexcept {
        return Length;
    }

    [[nodiscard]] constexpr size_type length() const noexcept {
        return Length;
    }

    [[nodiscard]] constexpr char_array c_str() const noexcept {
        return value;
    }
};

template<size_t Length>
CompileTimeString(const char (&chars)[Length]) -> CompileTimeString<Length - 1>;

#endif
#pragma clang diagnostic pop