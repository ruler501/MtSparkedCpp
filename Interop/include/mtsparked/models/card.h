#ifndef _MTSPARKED_CARD_H_
#define _MTSPARKED_CARD_H_

#include <array>
#include <memory>
#include <set>
#include <string>
#include <variant>
#include <vector>

#include "cppproperty/property.h"

namespace MtSparked {
    enum Color {
        WHITE = 0,
        BLUE = 1,
        BLACK = 2,
        RED = 3,
        GREEN = 4
    };

    class HalfInteger {
    private:
        int _value;

    public:
        HalfInteger(int value) : _value(value * 2) {}
        HalfInteger(double value) : _value(value * 2) {}

        explicit operator int() { return _value / 2; }
        operator double() { return _value / 2; }
    };

    enum struct Format {
        Standard,
        NextStandard,
        Frontier,
        Historic,
        Pioneer,
        Modern,
        Pauper,
        Legacy,
        PennyDreadful,
        DuelCommander,
        Commander,
        MtgoCommander,
    };

    struct CardDetails {
        std::vector<std::variant<std::array<char, 1>, std::array<char, 2>>> manaCost;
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
        std::string cmc;
        std::set<Color> colorIndicator;
        std::set<Color> colors;
        std::set<Color> colorIdentity;
        bool reservedList;
        bool reprint;
        bool fullArt;
        bool onlineOnly;
        std::set<Format> legalIn;
    };

    enum struct Status {
        NotOwned,
        Owned,
        Ordered,
        Proxied,
    };

    enum struct Finish {
        Foil,
        Signed,
        Altered,
        Misprint,
        Premium,
        FullArt,
    };

    struct CardOverrides {
    };

    struct Set {
        std::string code;
        std::string name;
    };

    struct Card {
        Status status;
        std::set<Finish> finishes;
        std::shared_ptr<const CardDetails> details;
        CardOverrides overrides;
        std::string notes;
        std::set<std::string> tags;

private:
        static std::string getRarity(const Card&);
        static std::vector<std::variant<std::array<char, 1>, std::array<char, 2>>> getManaCost(const Card&);
        static std::string getName(const Card&);
        static std::string getWatermark(const Card&);
        static Set getSet(const Card&);
        static std::string getFlavor(const Card&);
        static std::string getArtist(const Card&);
        static std::string getBorder(const Card&);
        static std::string getFrame(const Card&);
        static std::string getLayout(const Card&);
        static std::string getTypeLine(const Card&);
        static std::string getCmc(const Card&);
        static std::set<Color> getColorIndicator(const Card&);
        static std::set<Color> getColors(const Card&);
        static std::set<Color> getColorIdenity(const Card&);
        static bool getIsReservedList(const Card&);
        static bool getIsReprint(const Card&);
        static bool getIsOnlineOnly(const Card&);
        static std::set<Format> getLegalIn(const Card&);

public:
        property<Card, std::string, void, Card::getRarity> rarity;
        property<Card, std::vector<std::variant<std::array<char, 1>, std::array<char, 2>>>, Card::getManaCost> manaCost;
        property<Card, std::string, Card::getName> name;
        property<Card, std::string, Card::getWatermark> watermark;
        property<Card, Set, Card::getSet> set;
        property<Card, std::string, Card::getFlavor> flavor;
        property<Card, std::string, Card::getArtist> artist;
        property<Card, std::string, Card::getBorder> border;
        property<Card, std::string, Card::getFrame> frame;
        property<Card, std::string, Card::getLayout> layout;
        property<Card, std::string, Card::getTypeLine> typeLine;
        property<Card, std::string, Card::getCmc> cmc;
        property<Card, std::set<Color>, Card::getColorIndicator> colorIndicator;
        property<Card, std::set<Color>, Card::getColors> colors;
        property<Card, std::set<Color>, Card::getColorIdenity> colorIdentity;
        property<Card, bool, Card::getIsReservedList> isReservedList;
        property<Card, bool, Card::getIsReprint> isReprint;
        property<Card, bool, Card::getIsOnlineOnly> isOnlineOnly;
        property<Card, std::set<Format>, Card::getLegalIn> legalIn;
    };
}

#endif
