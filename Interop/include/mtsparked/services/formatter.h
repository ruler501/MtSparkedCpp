#ifndef _MTSPARKED_FORMATTER_H_
#define _MTSPARKED_FORMATTER_H_

#include <string_view>
#include <type_traits>

#include "mtsparked/utils/utils.h"

template<typename Source, typename Result, size_t maxSize=8, size_t maxAlignment=8>
class OutFormatter {
private:
    initializing_buffer<maxSize, maxAlignment> buffer;
    using formatFunction = Result(*)(void*, Source);
    formatFunction formatPtr;

public:
    std::string_view name;
    std::string_view version;

    using source_type = Source;
    using result_type = result;
    
    template<typename T, typename=std::enable_if_t<!std::is_same_v<T, OutFormatter>>>
    OutFormatter(T&& toErase) : initializing_buffer(std::forward<T>(toErase)),
                                formatPtr([](void* obj, Source src){ return static_cast<T*>(obj)->format(src); }
    { }

    OutFormatter(const OutFormatter& other) = delete;
    OutFormatter(OutFormatter&& other) = delete;

    constexpr Result format(Source src) {
        return formatPtr(buffer, src);
    }
};

template<typename Source, typename Result, size_t maxSize=8, size_t maxAlignment=8>
class InFormatter {
private:
    initializing_buffer<maxSize, maxAlignment> buffer;
    using parseFunction = Source(*)(void*, Result);
    parseFunction parsePtr;

public:
    std::string_view name;
    std::string_view version;

    using source_type = Source;
    using result_type = result;
    
    template<typename T, typename=std::enable_if_t<!std::is_same_v<T, InFormatter>>>
    InFormatter(T&& toErase) : initializing_buffer(std::forward<T>(toErase)),
                               parsePtr{[](void* obj, Result res){ return static_cast<std::remove_reference_t<T>*>(obj)->parse(res); }}
    { }

    InFormatter(const InFormatter& other) = delete;
    InFormatter(InFormatter&& other) = delete;

    constexpr Source parse(Result res) {
        return parsePtr(buffer, res);
    }
};

template<typename Source, typename Result, size_t maxSize=8, size_t maxAlignment=8>
class Formatter {
private:
    initializing_buffer<maxSize, maxAlignment> buffer;
    using formatFunction = Result(*)(void*, Source);
    formatFunction formatPtr;
    using parseFunction = Source(*)(void*, Result);
    parseFunction parsePtr;

public:
    std::string_view name;
    std::string_view version;

    using source_type = Source;
    using result_type = result;
    
    template<typename T, typename=std::enable_if_t<!std::is_same_v<T, InFormatter>>>
    Formatter(T&& toErase) : initializing_buffer(std::forward<T>(toErase)),
                             formatPtr{[](void* obj, Source src){ return static_cast<std::remove_reference_t<T>*>(obj)->format(src); }}
                             parsePtr{[](void* obj, Result res){ return static_cast<std::remove_reference_t<T>*>(obj)->parse(res); }}
    { }

    Formatter(const Formatter& other) = delete;
    Formatter(Formatter&& other) = delete;

    constexpr Result format(Source src) {
        return formatPtr(buffer, src);
    }

    constexpr Source parse(Result res) {
        return parsePtr(buffer, res);
    }
};
#endif // !_MTSPARKED_FORMATTER_H_
