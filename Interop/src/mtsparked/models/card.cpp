#include "mtsparked/models/card.h"

namespace MtSparked {
    std::string Card::getRarity(const Card& card) {
        return card.details->rarity;
    }
    
    std::vector<std::variant<std::array<char, 1>, std::array<char, 2>>> Card::getManaCost(const Card& card) {
        return card.details->manaCost;
    }

    std::string Card::getName(const Card& card) {
        return card.details->name;
    }

    std::string Card::getWatermark(const Card& card) {
        return card.details->watermark;
    }

    Set Card::getSet(const Card& card) {
        return card.details->set;
    }

    std::string Card::getFlavor(const Card& card) {
        return card.details->flavor;
    }

    std::string Card::getArtist(const Card& card) {
        return card.details->artist;
    }

    std::string Card::getBorder(const Card& card) {
        return card.details->border;
    }

    std::string Card::getFrame(const Card& card) {
        return card.details->frame;
    }

    std::string Card::getLayout(const Card& card) {
        return card.details->layout;
    }

    std::string Card::getTypeLine(const Card& card) {
        return card.details->typeLine;
    }

    std::string Card::getCmc(const Card& card) {
        return card.details->cmc;
    }

    std::set<Color> Card::getColorIndicator(const Card& card) {
        return card.details->colorIndicator;
    }

    std::set<Color> Card::getColors(const Card& card) {
        return card.details->colors;
    }

    std::set<Color> Card::getColorIdenity(const Card& card) {
        return card.details->colorIdentity;
    }

    bool Card::getIsReservedList(const Card& card) {
        return card.details->isReservedList;
    }

    bool Card::getIsReprint(const Card& card) {
        return card.details->isReprint;
    }

    bool Card::getIsOnlineOnly(const Card& card) {
        return card.details->isOnlineOnly;
    }

    std::set<Format> Card::getLegalIn(const Card& card) {
        return card.details->legalIn;
    }

}
