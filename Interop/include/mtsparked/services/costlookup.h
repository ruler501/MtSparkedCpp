#ifndef _MTSPARKED_COSTLOOKUP_H_
#define _MTSPARKED_COSTLOOKUP_H_

#include <type_traits>

#include "compiletimeplugins/utils.h"

#include "mtsparked/models/card.h"
#include "mtsparked/models/dollarValue.h"

namespace mtsparked {
    template<typename Buffer>
    class CostLookupPlugin {
    protected:
        using func=double (*)(void *, const mtsparked::card&);
        func fPtr;

        template<typename T, typename=std::enable_if_t<!std::is_base_of_v<CostLookupPlugin, T>>>
        explicit CostLookupPlugin(type_value <T>)
                : fPtr([](void *obj, const mtsparked::card& card) { return static_cast<T*>(obj)->getCost(card); }) {}

    public:
         dollarValue getCost(const mtsparked::card& card) {
            return fPtr(static_cast<void *>(static_cast<Buffer &>(*this)), card);
        }
    };

    template <typename... Features>
    using CostLookup = erased<CostLookupPlugin, Features...>;
}

#endif // _MTSPARKED_COSTLOOKUP_H_
