#ifndef _MTSPARKED_DECK_H_
#define _MTSPARKED_DECK_H_

#include <string>
#include <vector>

#include "mtsparked/utils/compiletimestring.h"
#include "mtsparked/services/fileprovider.h"

namespace MtSparked {
    struct Deck {
        static constexpr CompileTimeString MASTER = "Total";
        static constexpr CompileTimeString MAINBOARD = "Mainboard";
        static constexpr CompileTimeString SIDEBOARD = "Sideboard";
        static constexpr CompileTimeString UNNAMED = "Unnamed";

        std::string name;
        std::optional<FileData>
    };
}

#endif