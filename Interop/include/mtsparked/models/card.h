#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef _MTSPARKED_CARD_H_
#define _MTSPARKED_CARD_H_

#include <string>

namespace MtSparked {
    struct Card {
        std::string manaCost;
        std::string name;
        std::string rarity;
        std::string watermark;
        std::string setCode;
        std::string setName;
        std::string flavor;
        std::string artist;
        std::string border;
        std::string frame;
        std::string layout;
        std::string typeLine;
        std::string colors;
        std::string colorIdentity;
        int cmc;
        std::string colorIndicator;
        bool multicolored;
        bool colorless;
        bool reservedList;
        bool reprint;
        bool fullArt;
        bool onlineOnly;
        bool legalInStandard;
        bool legalInFrontier;
        bool legalInModern;
        bool legalInPauper;
        bool legalInLegacy;
        bool legalInPennyDreadful;
        bool legalInDuelCommander;
        bool legalInCommander;
        bool legalInMtgoCommander;
        bool legalInNextStandard;
    };
}

#endif
#pragma clang diagnostic pop