#ifndef _MTSPARKED_DECK_H_
#define _MTSPARKED_DECK_H_

#include <map>
#include <optional>
#include <string>
#include <vector>

#include "mtsparked/models/card.h"
#include "mtsparked/services/fileprovider.h"

namespace MtSparked {
    struct Deck {
        static constexpr std::string MASTER = "Total";
        static constexpr std::string MAINBOARD = "Main";
        static constexpr std::string SIDEBOARD = "Sideboard";
        static constexpr std::string UNNAMED = "Unnamed";

        std::string name;
        std::optional<FileData> backingFile;
        std::map<std::string, std::vector<Card>> boards;
        std::string description;
    };
}

#endif
