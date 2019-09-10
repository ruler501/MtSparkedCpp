#ifndef _MTSPARKED_FORMATTER_H_
#define _MTSPARKED_FORMATTER_H_

#include <string_view>
#include <type_traits>

#include "compiletimeplugins/utils.h"

template<typename Source, typename Result>
struct OutFormatterFeature {
    template <typename Buffer>
    class type {
    public:
        using source_type = Source;
        using result_type = Result;

    protected:
        using formatFunc = Result(*)(const void*, const Source&);
        formatFunc formatPtr;

    public:
        std::string_view name;
        std::string_view version;

        template<typename T, typename=std::enable_if_t<!std::is_same_v<std::decay_t<T>, OutFormatterFeature>>>
        OutFormatterFeature(type_value<T>)
                : formatPtr([](const void* obj, const Source& src){ return static_cast<const T*>(obj)->format(src); }
        { }

        OutFormatterFeature(const OutFormatterFeature& other) = delete;
        OutFormatterFeature(OutFormatterFeature&& other) = delete;

        constexpr Result format(const Source& src) const {
            return formatPtr(static_cast<const void*>(static_cast<const Buffer&>(*this)), src);
        }
    };
};

template<typename Source, typename Result>
struct InFormatterFeature {
    template <typename Buffer>
    class type {
    public:
        using source_type = Source;
        using result_type = Result;

    protected:
        using parseFunc = Source(*)(const void*, const Result&);
        parseFunc parsePtr;

    public:
        std::string_view name;
        std::string_view version;

        template<typename T, typename=std::enable_if_t<!std::is_same_v<std::decay_t<T>, InFormatterFeature>>>
        InFormatterFeature(type_value<T>)
                : formatPtr([](const void* obj, const Source& src){ return static_cast<const T*>(obj)->format(src); }
        { }

        InFormatterFeature(const InFormatterFeature& other) = delete;
        InFormatterFeature(InFormatterFeature&& other) = delete;

        constexpr Result format(const Source& src) const {
            return formatPtr(static_cast<const void*>(static_cast<const Buffer&>(*this)), src);
        }
    };
};

template <typename... Features>
using OutFormatter_t = erased<OutFormatterFeature, Features...>;

using OutFormatter = OutFormatter_t<>;

template <typename... Features>
using InFormatter_t = erased<InFormatterFeature, Features...>;

using InFormatter = InFormatter_t<>;

template <typename... Features>
using Formatter_t = erased<OutFormatterFeature, InFormatterFeature, Features...>;

using Formatter = Formatter_t<>;

#endif // !_MTSPARKED_FORMATTER_H_
