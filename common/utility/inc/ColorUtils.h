/**
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include "UtilityCommon.hpp"

BEG_NAMESPACE_CBTEK_UTILITY

/**
 * @brief The ColorStringStyle enum contains
 * style associated with parsing strings
 * with color information
 */
enum class ColorStringStyle
{
    RGB_255        //eg. 255 127 64
    ,RGBA_255      //eg. 255 127 64 255
    ,RGB_FLOAT     //eg. 1.0 0.5 0.25
    ,RGBA_FLOAT    //eg. 1.0 0.5 0.25 1.0
    ,RGB_HTML_HEX  //eg. #FFAA33
    ,RGBA_HTML_HEX //eg. #FFAA33AA
    ,ARGB_HTML_HEX //eg. #AARRGGBB
};

class Color
{
public:

    /**
     * @brief Color Constructor for this class
     */
    Color();

    /**
     * @brief Color Constructor for this class
     * @param color 32-bit color defined as 8
     * bit components of RGBA
     */
    Color(std::uint32_t color);

    /**
     * @brief Color Constructor for this class
     * @param rgbaHex Hexadecimal string representing the
     * color to be set upon construction
     */
    Color(const std::string & rgbaHex);

    /**
     * @brief Color Constructor for this class
     * @param name String name/id for the color
     * @param red 8-bit red component for this color [0-255]
     * @param green 8-bit green component for this color [0-255]
     * @param blue 8-bit blue component for this color [0-255]
     * @param alpha 8-bit opacity component for this color [0-255]
     * Higher value results in less transparency
     */
    Color(const std::string & name,const uint8_t & red,
          const uint8_t & green,
          const uint8_t & blue,
          const uint8_t & alpha=255);

    /**
     * @brief Color Constructor for this class
     * @param red 8-bit red component for this color [0-255]
     * @param green 8-bit green component for this color [0-255]
     * @param blue 8-bit blue component for this color [0-255]
     * @param alpha 8-bit opacity component for this color [0-255]
     * Higher value results in less transparency
     */
    Color(const uint8_t & red,
          const uint8_t & green,
          const uint8_t & blue,
          const uint8_t & alpha=255);

    /**
     * @brief set Sets the color using rgba components
     * @param red 8-bit red component for this color [0-255]
     * @param green 8-bit green component for this color [0-255]
     * @param blue 8-bit blue component for this color [0-255]
     * @param alpha 8-bit opacity component for this color [0-255]
     * Higher value results in less transparency
     */
    void set (const uint8_t & red,
              const uint8_t & green,
              const uint8_t & blue,
              const uint8_t & alpha=255);

    /**
     * @brief set Sets the color from a html string
     * @param htmlColor The string containing color information
     * (e.g #AAFFCC, #abc, #ef41af)
     */
    void set(const std::string& htmlColor);

    /**
     * @brief setRed Sets the red component
     * @param Red intensity value for the red component [0-255]
     */
    void setRed(const uint8_t & red);

    /**
     * @brief setGreen Sets the green component
     * @param Green intensity value for the green component [0-255]
     */
    void setGreen(const uint8_t & green);

    /**
     * @brief setBlue Sets the blue component
     * @param Blue intensity value for the blue component [0-255]
     */
    void setBlue(const uint8_t & blue);

    /**
     * @brief setAlpha Sets the alpha component
     * @param Alpha intensity value for the alpha component [0-255]
     */
    void setAlpha(const uint8_t & alpha);

    /**
     * @brief toInteger Converts color to 32-bit numeric value
     * @return Integer of converted color
     */
    std::uint32_t toInteger() const;

    /**
     * @brief operator == Determine if two colors are equal
     * @param color The color to test against
     * @return Return true if colors match, false otherwise
     */
    bool operator==(const Color & color) const;

    /**
     * @brief operator != Determine if two colors are not equal
     * @param color The color to test against
     * @return Return true if colors don't match, false otherwise
     */
    bool operator!=(const Color & color) const;

    /**
     * @brief getRed Gets the red component
     * @return 8-bit red component value
     */
    uint8_t getRed() const;

    /**
     * @brief getGreen Gets the green component
     * @return 8-bit green component value
     */
    uint8_t getGreen() const;

    /**
     * @brief getBlue Gets the blue component
     * @return 8-bit blue component value
     */
    uint8_t getBlue() const;

    /**
     * @brief getAlpha Gets the alpha component
     * @return 8-bit alpha component value
     */
    uint8_t getAlpha() const;

    /**
     * @brief isTransparent Return true if color
     *  can be considered transparent
     * @return Return true if transparent, false otherwise
     */
    bool isTransparent() const;

    /**
     * @brief toString Convert color to string
     * @param style Use string style in ColorStringStyle
     * @return Converted string
     */
    std::string toString(const ColorStringStyle& style = ColorStringStyle::RGBA_255) const;

    /**
     * @brief getName Get the name of this color
     * @return Return name of color
     */
    std::string getName() const;

    /**
     * @brief setName Sets name for current color
     * @param name String representing name
     */
    void setName(const std::string & name);

private:

    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
    std::string m_name;
};
typedef std::shared_ptr<Color> ColorPtr;


namespace colors{

    enum ColorType
    {
        RED=0
        ,GREEN
        ,BLUE
        ,YELLOW
        ,BRILLIANT_PURPLE
        ,BRIGHT_BLUE
        ,BURNT_ORANGE
        ,FOREST_GREEN
        ,MIDNIGHT_BLUE
        ,DESERT_MUAVE
        ,PLUM
        ,SMOKE
        ,BURNT_OLIVE
        ,BURGANDY
        ,OLIVE_DRAB
        ,DARK_TURQUOISE
        ,MAROON
        ,DARK_GREEN
        ,TORQUOISE
        ,DARK_BLUE
        ,WHINE
        ,SHADOW_GREY
        ,BURNT_RED
        ,DARK_ORANGE
        ,MUSTARD
        ,JADE_BLUE
        ,PURPLE
        ,ASH_GREY
        ,ORANGE
        ,LIME_GREEN
        ,ELECTRIC_BLUE
        ,PLATINUM
        ,SALMON
        ,GOLD
        ,YELLOW_GOLD
        ,SEA_FOAM_GREEN
        ,BABY_BLUE
        ,PURPLE_GREY
        ,PINK
        ,WHITE
        ,BLACK
        ,PALE_SALMON
        ,PALE_ORANGE
        ,PALE_YELLOW
        ,PALE_GREEN
        ,PALE_BLUE
        ,PALE_PURPLE
        ,PALE_PINK
        ,ACID_GREEN
        ,AERO
        ,AERO_BLUE
        ,AFRICAN_PURPLE
        ,AIR_FORCE_BLUE_RAF
        ,AIR_FORCE_BLUE_USAF
        ,AIR_SUPERIORITY_BLUE
        ,ALABAMA_CRIMSON
        ,ALICE_BLUE
        ,ALIZARIN_CRIMSON
        ,ALLOY_ORANGE
        ,ALMOND
        ,AMARANTH
        ,AMARANTH_PINK
        ,AMARANTH_PURPLE
        ,AMAZON
        ,AMBER
        ,SAE_ECE_AMBER_COLOR
        ,AMERICAN_ROSE
        ,AMETHYST
        ,ANDROID_GREEN
        ,ANTI_FLASH_WHITE
        ,ANTIQUE_BRASS
        ,GUI_BLUE
        ,ANTIQUE_BRONZE
        ,ANTIQUE_FUCHSIA
        ,ANTIQUE_RUBY
        ,ANTIQUE_WHITE
        ,AO_ENGLISH
        ,APPLE_GREEN
        ,APRICOT
        ,AQUA
        ,AQUAMARINE
        ,ARMY_GREEN
        ,ARSENIC
        ,ARTICHOKE
        ,ARYLIDE_YELLOW
        ,ASPARAGUS
        ,ATOMIC_TANGERINE
        ,AUBURN
        ,AUREOLIN
        ,AUROMETALSAURUS
        ,AVOCADO
        ,AZURE
        ,AZURE_MIST_WEB
        ,BABY_BLUE_EYES
        ,BABY_PINK
        ,BABY_POWDER
        ,BAKER_MILLER_PINK
        ,BALL_BLUE
        ,BANANA_MANIA
        ,BANANA_YELLOW
        ,BANGLADESH_GREEN
        ,BARBIE_PINK
        ,BARN_RED
        ,BATTLESHIP_GREY
        ,BAZAAR
        ,BEAU_BLUE
        ,BEAVER
        ,BEIGE
        ,BDAZZLED_BLUE
        ,BIG_DIP_O_RUBY
        ,BISQUE
        ,BISTRE
        ,BISTRE_BROWN
        ,BITTER_LEMON
        ,BITTER_LIME
        ,BITTERSWEET
        ,BITTERSWEET_SHIMMER
        ,BLACK_BEAN
        ,BLACK_LEATHER_JACKET
        ,BLACK_OLIVE
        ,BLANCHED_ALMOND
        ,BLAST_OFF_BRONZE
        ,BLEU_DE_FRANCE
        ,BLIZZARD_BLUE
        ,BLOND
        ,BLUE_CRAYOLA
        ,BLUE_MUNSELL
        ,BLUE_NCS
        ,BLUE_PIGMENT
        ,BLUE_RYB
        ,BLUE_BELL
        ,BLUE_GRAY
        ,BLUE_GREEN
        ,BLUE_SAPPHIRE
        ,BLUE_VIOLET
        ,BLUE_YONDER
        ,BLUEBERRY
        ,BLUEBONNET
        ,BLUSH
        ,BOLE
        ,BONDI_BLUE
        ,BONE
        ,BOSTON_UNIVERSITY_RED
        ,BOTTLE_GREEN
        ,BOYSENBERRY
        ,BRANDEIS_BLUE
        ,BRASS
        ,BRICK_RED
        ,BRIGHT_CERULEAN
        ,BRIGHT_GREEN
        ,BRIGHT_LAVENDER
        ,BRIGHT_LILAC
        ,BRIGHT_MAROON
        ,BRIGHT_NAVY_BLUE
        ,BRIGHT_PINK
        ,BRIGHT_TURQUOISE
        ,BRIGHT_UBE
        ,BRILLIANT_LAVENDER
        ,BRILLIANT_ROSE
        ,BRINK_PINK
        ,BRITISH_RACING_GREEN
        ,BRONZE
        ,BRONZE_YELLOW
        ,BROWN_TRADITIONAL
        ,BROWN_WEB
        ,BROWN_NOSE
        ,BRUNSWICK_GREEN
        ,BUBBLE_GUM
        ,BUBBLES
        ,BUFF
        ,BUD_GREEN
        ,BULGARIAN_ROSE
        ,BURGUNDY
        ,BURLYWOOD
        ,BURNT_SIENNA
        ,BYZANTINE
        ,BYZANTIUM
        ,CADET
        ,CADET_BLUE
        ,CADET_GREY
        ,CADMIUM_GREEN
        ,CADMIUM_ORANGE
        ,CADMIUM_RED
        ,CADMIUM_YELLOW
        ,CAFE_AU_LAIT
        ,CAFE_NOIR
        ,CAL_POLY_GREEN
        ,CAMBRIDGE_BLUE
        ,CAMEL
        ,CAMEO_PINK
        ,CAMOUFLAGE_GREEN
        ,CANARY_YELLOW
        ,CANDY_APPLE_RED
        ,CANDY_PINK
        ,CAPRI
        ,CAPUT_MORTUUM
        ,CARDINAL
        ,CARIBBEAN_GREEN
        ,CARMINE
        ,CARMINE_M_AND_P
        ,CARMINE_PINK
        ,CARMINE_RED
        ,CARNATION_PINK
        ,CARNELIAN
        ,CAROLINA_BLUE
        ,CARROT_ORANGE
        ,CASTLETON_GREEN
        ,CATALINA_BLUE
        ,CATAWBA
        ,CEDAR_CHEST
        ,CEIL
        ,CELADON
        ,CELADON_BLUE
        ,CELADON_GREEN
        ,CELESTE
        ,CELESTIAL_BLUE
        ,CERISE
        ,CERISE_PINK
        ,CERULEAN
        ,CERULEAN_BLUE
        ,CERULEAN_FROST
        ,CG_BLUE
        ,CG_RED
        ,CHAMOISEE
        ,CHAMPAGNE
        ,CHARCOAL
        ,CHARLESTON_GREEN
        ,CHARM_PINK
        ,CHARTREUSE_TRADITIONAL
        ,CHARTREUSE_WEB
        ,CHERRY
        ,CHERRY_BLOSSOM_PINK
        ,CHESTNUT
        ,CHINA_PINK
        ,CHINA_ROSE
        ,CHINESE_RED
        ,CHINESE_VIOLET
        ,CHOCOLATE_TRADITIONAL
        ,CHOCOLATE_WEB
        ,CHROME_YELLOW
        ,CINEREOUS
        ,CINNABAR
        ,CINNAMON
        ,CITRINE
        ,CITRON
        ,CLARET
        ,CLASSIC_ROSE
        ,COBALT
        ,COCOA_BROWN
        ,COCONUT
        ,COFFEE
        ,COLUMBIA_BLUE
        ,CONGO_PINK
        ,COOL_BLACK
        ,COOL_GREY
        ,COPPER
        ,COPPER_CRAYOLA
        ,COPPER_PENNY
        ,COPPER_RED
        ,COPPER_ROSE
        ,COQUELICOT
        ,CORAL
        ,CORAL_PINK
        ,CORAL_RED
        ,CORDOVAN
        ,CORN
        ,CORNELL_RED
        ,CORNFLOWER_BLUE
        ,CORNSILK
        ,COSMIC_LATTE
        ,COTTON_CANDY
        ,CREAM
        ,CRIMSON
        ,CRIMSON_GLORY
        ,CYAN
        ,CYAN_PROCESS
        ,CYBER_GRAPE
        ,CYBER_YELLOW
        ,DAFFODIL
        ,DANDELION
        ,DARK_BLUE_GRAY
        ,DARK_BROWN
        ,DARK_BYZANTIUM
        ,DARK_CANDY_APPLE_RED
        ,DARK_CERULEAN
        ,DARK_CHESTNUT
        ,DARK_CORAL
        ,DARK_CYAN
        ,DARK_ELECTRIC_BLUE
        ,DARK_GOLDENROD
        ,DARK_GRAY
        ,DARK_IMPERIAL_BLUE
        ,DARK_JUNGLE_GREEN
        ,DARK_KHAKI
        ,DARK_LAVA
        ,DARK_LAVENDER
        ,DARK_LIVER
        ,DARK_LIVER_HORSES
        ,DARK_MAGENTA
        ,DARK_MIDNIGHT_BLUE
        ,DARK_MOSS_GREEN
        ,DARK_OLIVE_GREEN
        ,DARK_ORCHID
        ,DARK_PASTEL_BLUE
        ,DARK_PASTEL_GREEN
        ,DARK_PASTEL_PURPLE
        ,DARK_PASTEL_RED
        ,DARK_PINK
        ,DARK_POWDER_BLUE
        ,DARK_PUCE
        ,DARK_RASPBERRY
        ,DARK_RED
        ,DARK_SALMON
        ,DARK_SCARLET
        ,DARK_SEA_GREEN
        ,DARK_SIENNA
        ,DARK_SKY_BLUE
        ,DARK_SLATE_BLUE
        ,DARK_SLATE_GRAY
        ,DARK_SPRING_GREEN
        ,DARK_TAN
        ,DARK_TANGERINE
        ,DARK_TAUPE
        ,DARK_TERRA_COTTA
        ,DARK_VANILLA
        ,DARK_VIOLET
        ,DARK_YELLOW
        ,DARTMOUTH_GREEN
        ,DAVYS_GREY
        ,DEBIAN_RED
        ,DEEP_CARMINE
        ,DEEP_CARMINE_PINK
        ,DEEP_CARROT_ORANGE
        ,DEEP_CERISE
        ,DEEP_CHAMPAGNE
        ,DEEP_CHESTNUT
        ,DEEP_COFFEE
        ,DEEP_FUCHSIA
        ,DEEP_JUNGLE_GREEN
        ,DEEP_LEMON
        ,DEEP_LILAC
        ,DEEP_MAGENTA
        ,DEEP_MAUVE
        ,DEEP_MOSS_GREEN
        ,DEEP_PEACH
        ,DEEP_PINK
        ,DEEP_PUCE
        ,DEEP_RUBY
        ,DEEP_SAFFRON
        ,DEEP_SAFFRON_ORANGE
        ,DEEP_SKY_BLUE
        ,DEEP_SPACE_SPARKLE
        ,DEEP_TAUPE
        ,DEEP_TUSCAN_RED
        ,DEER
        ,DENIM
        ,DESERT
        ,DESERT_SAND
        ,DESIRE
        ,DIAMOND
        ,DIM_GRAY
        ,DIRT
        ,DODGER_BLUE
        ,DOGWOOD_ROSE
        ,DOLLAR_BILL
        ,DONKEY_BROWN
        ,DRAB
        ,DUKE_BLUE
        ,DUST_STORM
        ,DUTCH_WHITE
        ,EARTH_YELLOW
        ,EBONY
        ,ECRU
        ,EERIE_BLACK
        ,EGGPLANT
        ,EGGSHELL
        ,EGYPTIAN_BLUE
        ,ELECTRIC_CRIMSON
        ,ELECTRIC_CYAN
        ,ELECTRIC_GREEN
        ,ELECTRIC_INDIGO
        ,ELECTRIC_LAVENDER
        ,ELECTRIC_LIME
        ,ELECTRIC_PURPLE
        ,ELECTRIC_ULTRAMARINE
        ,ELECTRIC_VIOLET
        ,ELECTRIC_YELLOW
        ,EMERALD
        ,EMINENCE
        ,ENGLISH_GREEN
        ,ENGLISH_LAVENDER
        ,ENGLISH_RED
        ,ENGLISH_VIOLET
        ,ETON_BLUE
        ,EUCALYPTUS
        ,FALLOW
        ,FALU_RED
        ,FANDANGO
        ,FANDANGO_PINK
        ,FASHION_FUCHSIA
        ,FAWN
        ,FELDGRAU
        ,FELDSPAR
        ,FERN_GREEN
        ,FERRARI_RED
        ,FIELD_DRAB
        ,FIREBRICK
        ,FIRE_ENGINE_RED
        ,FLAME
        ,FLAMINGO_PINK
        ,FLATTERY
        ,FLAVESCENT
        ,FLAX
        ,FLIRT
        ,FLORAL_WHITE
        ,FLUORESCENT_ORANGE
        ,FLUORESCENT_PINK
        ,FLUORESCENT_YELLOW
        ,FOLLY
        ,FOREST_GREEN_TRADITIONAL
        ,FOREST_GREEN_WEB
        ,FRENCH_BEIGE
        ,FRENCH_BISTRE
        ,FRENCH_BLUE
        ,FRENCH_FUCHSIA
        ,FRENCH_LILAC
        ,FRENCH_LIME
        ,FRENCH_MAUVE
        ,FRENCH_PINK
        ,FRENCH_PUCE
        ,FRENCH_RASPBERRY
        ,FRENCH_ROSE
        ,FRENCH_SKY_BLUE
        ,FRENCH_VIOLET
        ,FRENCH_WINE
        ,FRESH_AIR
        ,FUCHSIA
        ,FUCHSIA_CRAYOLA
        ,FUCHSIA_PINK
        ,FUCHSIA_PURPLE
        ,FUCHSIA_ROSE
        ,FULVOUS
        ,FUZZY_WUZZY
        ,GAINSBORO
        ,GAMBOGE
        ,GENERIC_VIRIDIAN
        ,GHOST_WHITE
        ,GIANTS_ORANGE
        ,GINGER
        ,GLAUCOUS
        ,GLITTER
        ,GO_GREEN
        ,GOLD_METALLIC
        ,GOLD_WEB_GOLDEN
        ,GOLD_FUSION
        ,GOLDEN_BROWN
        ,GOLDEN_POPPY
        ,GOLDEN_YELLOW
        ,GOLDENROD
        ,GRANNY_SMITH_APPLE
        ,GRAPE
        ,GRAY
        ,GRAY_HTML_CSS_GRAY
        ,GRAY_X11_GRAY
        ,GRAY_ASPARAGUS
        ,GRAY_BLUE
        ,GREEN_COLOR_WHEEL_X11_GREEN
        ,GREEN_CRAYOLA
        ,GREEN_HTML_CSS_COLOR
        ,GREEN_MUNSELL
        ,GREEN_NCS
        ,GREEN_PIGMENT
        ,GREEN_RYB
        ,GREEN_YELLOW
        ,GRULLO
        ,GUPPIE_GREEN
        ,HALAYA_UBE
        ,HAN_BLUE
        ,HAN_PURPLE
        ,HANSA_YELLOW
        ,HARLEQUIN
        ,HARVARD_CRIMSON
        ,HARVEST_GOLD
        ,HEART_GOLD
        ,HELIOTROPE
        ,HELIOTROPE_GRAY
        ,HOLLYWOOD_CERISE
        ,HONEYDEW
        ,HONOLULU_BLUE
        ,HOOKERS_GREEN
        ,HOT_MAGENTA
        ,HOT_PINK
        ,HUNTER_GREEN
        ,ICEBERG
        ,ICTERINE
        ,ILLUMINATING_EMERALD
        ,IMPERIAL
        ,IMPERIAL_BLUE
        ,IMPERIAL_PURPLE
        ,IMPERIAL_RED
        ,INCHWORM
        ,INDEPENDENCE
        ,INDIA_GREEN
        ,INDIAN_RED
        ,INDIAN_YELLOW
        ,INDIGO
        ,INDIGO_DYE
        ,INDIGO_WEB
        ,INTERNATIONAL_KLEIN_BLUE
        ,INTERNATIONAL_ORANGE_AEROSPACE
        ,INTERNATIONAL_ORANGE_ENGINEERING
        ,INTERNATIONAL_ORANGE_GOLDEN_GATE_BRIDGE
        ,IRIS
        ,IRRESISTIBLE
        ,ISABELLINE
        ,ISLAMIC_GREEN
        ,ITALIAN_SKY_BLUE
        ,IVORY
        ,JADE
        ,JAPANESE_CARMINE
        ,JAPANESE_INDIGO
        ,JAPANESE_VIOLET
        ,JASMINE
        ,JASPER
        ,JAZZBERRY_JAM
        ,JELLY_BEAN
        ,JET
        ,JONQUIL
        ,JORDY_BLUE
        ,JUNE_BUD
        ,JUNGLE_GREEN
        ,KELLY_GREEN
        ,KENYAN_COPPER
        ,KEPPEL
        ,KHAKI_HTML_CSS_KHAKI
        ,KHAKI_X11_LIGHT_KHAKI
        ,KOBE
        ,KOBI
        ,KOMBU_GREEN
        ,KU_CRIMSON
        ,LA_SALLE_GREEN
        ,LANGUID_LAVENDER
        ,LAPIS_LAZULI
        ,LASER_LEMON
        ,LAUREL_GREEN
        ,LAVA
        ,LAVENDER_FLORAL
        ,LAVENDER_WEB
        ,LAVENDER_BLUE
        ,LAVENDER_BLUSH
        ,LAVENDER_GRAY
        ,LAVENDER_INDIGO
        ,LAVENDER_MAGENTA
        ,LAVENDER_MIST
        ,LAVENDER_PINK
        ,LAVENDER_PURPLE
        ,LAVENDER_ROSE
        ,LAWN_GREEN
        ,LEMON
        ,LEMON_CHIFFON
        ,LEMON_CURRY
        ,LEMON_GLACIER
        ,LEMON_LIME
        ,LEMON_MERINGUE
        ,LEMON_YELLOW
        ,LICORICE
        ,LIBERTY
        ,LIGHT_APRICOT
        ,LIGHT_BLUE
        ,LIGHT_BROWN
        ,LIGHT_CARMINE_PINK
        ,LIGHT_CORAL
        ,LIGHT_CORNFLOWER_BLUE
        ,LIGHT_CRIMSON
        ,LIGHT_CYAN
        ,LIGHT_DEEP_PINK
        ,LIGHT_FUCHSIA_PINK
        ,LIGHT_GOLDENROD_YELLOW
        ,LIGHT_GRAY
        ,LIGHT_GREEN
        ,LIGHT_HOT_PINK
        ,LIGHT_KHAKI
        ,LIGHT_MEDIUM_ORCHID
        ,LIGHT_MOSS_GREEN
        ,LIGHT_ORCHID
        ,LIGHT_PASTEL_PURPLE
        ,LIGHT_PINK
        ,LIGHT_RED_OCHRE
        ,LIGHT_SALMON
        ,LIGHT_SALMON_PINK
        ,LIGHT_SEA_GREEN
        ,LIGHT_SKY_BLUE
        ,LIGHT_SLATE_GRAY
        ,LIGHT_STEEL_BLUE
        ,LIGHT_TAUPE
        ,LIGHT_THULIAN_PINK
        ,LIGHT_YELLOW
        ,LILAC
        ,LIME_COLOR_WHEEL
        ,LIME_WEB_X11_GREEN
        ,LIMERICK
        ,LINCOLN_GREEN
        ,LINEN
        ,LION
        ,LISERAN_PURPLE
        ,LITTLE_BOY_BLUE
        ,LIVER
        ,LIVER_DOGS
        ,LIVER_ORGAN
        ,LIVER_CHESTNUT
        ,LIVID
        ,LUMBER
        ,LUST
        ,MAGENTA
        ,MAGENTA_CRAYOLA
        ,MAGENTA_DYE
        ,MAGENTA_PANTONE
        ,MAGENTA_PROCESS
        ,MAGENTA_HAZE
        ,MAGIC_MINT
        ,MAGNOLIA
        ,MAHOGANY
        ,MAIZE
        ,MAJORELLE_BLUE
        ,MALACHITE
        ,MANATEE
        ,MANGO_TANGO
        ,MANTIS
        ,MARDI_GRAS
        ,MAROON_CRAYOLA
        ,MAROON_HTML_CSS
        ,MAROON_X11
        ,MAUVE
        ,MAUVE_TAUPE
        ,MAUVELOUS
        ,MAY_GREEN
        ,MAYA_BLUE
        ,MEAT_BROWN
        ,MEDIUM_AQUAMARINE
        ,MEDIUM_BLUE
        ,MEDIUM_CANDY_APPLE_RED
        ,MEDIUM_CARMINE
        ,MEDIUM_CHAMPAGNE
        ,MEDIUM_ELECTRIC_BLUE
        ,MEDIUM_JUNGLE_GREEN
        ,MEDIUM_LAVENDER_MAGENTA
        ,MEDIUM_ORCHID
        ,MEDIUM_PERSIAN_BLUE
        ,MEDIUM_PURPLE
        ,MEDIUM_RED_VIOLET
        ,MEDIUM_RUBY
        ,MEDIUM_SEA_GREEN
        ,MEDIUM_SKY_BLUE
        ,MEDIUM_SLATE_BLUE
        ,MEDIUM_SPRING_BUD
        ,MEDIUM_SPRING_GREEN
        ,MEDIUM_TAUPE
        ,MEDIUM_TURQUOISE
        ,MEDIUM_TUSCAN_RED
        ,MEDIUM_VERMILION
        ,MEDIUM_VIOLET_RED
        ,MELLOW_APRICOT
        ,MELLOW_YELLOW
        ,MELON
        ,METALLIC_SEAWEED
        ,METALLIC_SUNBURST
        ,MEXICAN_PINK
        ,MIDNIGHT_GREEN_EAGLE_GREEN
        ,MIDNIGHT_MAROON
        ,MIKADO_YELLOW
        ,MINDARO
        ,MINT
        ,MINT_CREAM
        ,MINT_GREEN
        ,MISTY_ROSE
        ,MOCCASIN
        ,MODE_BEIGE
        ,MOONSTONE_BLUE
        ,MORDANT_RED_19
        ,MOSS_GREEN
        ,MOUNTAIN_MEADOW
        ,MOUNTBATTEN_PINK
        ,MSU_GREEN
        ,MUGHAL_GREEN
        ,MULBERRY
        ,MYRTLE_GREEN
        ,NADESHIKO_PINK
        ,NAPIER_GREEN
        ,NAPLES_YELLOW
        ,NAVAJO_WHITE
        ,NAVY
        ,NAVY_PURPLE
        ,NEON_CARROT
        ,NEON_FUCHSIA
        ,NEON_GREEN
        ,NEW_CAR
        ,NEW_YORK_PINK
        ,NON_PHOTO_BLUE
        ,NORTH_TEXAS_GREEN
        ,NYANZA
        ,OCEAN_BOAT_BLUE
        ,OCHRE
        ,OFFICE_GREEN
        ,OLD_BURGUNDY
        ,OLD_GOLD
        ,OLD_HELIOTROPE
        ,OLD_LACE
        ,OLD_LAVENDER
        ,OLD_MAUVE
        ,OLD_MOSS_GREEN
        ,OLD_ROSE
        ,OLD_SILVER
        ,OLIVE
        ,OLIVE_DRAB_3
        ,OLIVE_DRAB_7
        ,OLIVINE
        ,ONYX
        ,OPERA_MAUVE
        ,ORANGE_COLOR_WHEEL
        ,ORANGE_CRAYOLA
        ,ORANGE_PANTONE
        ,ORANGE_RYB
        ,ORANGE_WEB
        ,ORANGE_PEEL
        ,ORANGE_RED
        ,ORCHID
        ,ORCHID_PINK
        ,ORIOLES_ORANGE
        ,OTTER_BROWN
        ,OUTER_SPACE
        ,OUTRAGEOUS_ORANGE
        ,OXFORD_BLUE
        ,OU_CRIMSON_RED
        ,PAKISTAN_GREEN
        ,PALATINATE_BLUE
        ,PALATINATE_PURPLE
        ,PALE_AQUA
        ,PALE_BROWN
        ,PALE_CARMINE
        ,PALE_CERULEAN
        ,PALE_CHESTNUT
        ,PALE_COPPER
        ,PALE_CORNFLOWER_BLUE
        ,PALE_GOLD
        ,PALE_GOLDENROD
        ,PALE_LAVENDER
        ,PALE_MAGENTA
        ,PALE_PLUM
        ,PALE_RED_VIOLET
        ,PALE_ROBIN_EGG_BLUE
        ,PALE_SILVER
        ,PALE_SPRING_BUD
        ,PALE_TAUPE
        ,PALE_TURQUOISE
        ,PALE_VIOLET_RED
        ,PANSY_PURPLE
        ,PAOLO_VERONESE_GREEN
        ,PAPAYA_WHIP
        ,PARADISE_PINK
        ,PARIS_GREEN
        ,PASTEL_BLUE
        ,PASTEL_BROWN
        ,PASTEL_GRAY
        ,PASTEL_GREEN
        ,PASTEL_MAGENTA
        ,PASTEL_ORANGE
        ,PASTEL_PINK
        ,PASTEL_PURPLE
        ,PASTEL_RED
        ,PASTEL_VIOLET
        ,PASTEL_YELLOW
        ,PATRIARCH
        ,PAYNES_GREY
        ,PEACH
        ,PEACH_2_POINT_OH
        ,PEACH_ORANGE
        ,PEACH_PUFF
        ,PEACH_YELLOW
        ,PEAR
        ,PEARL
        ,PEARL_AQUA
        ,PEARLY_PURPLE
        ,PERIDOT
        ,PERIWINKLE
        ,PERSIAN_BLUE
        ,PERSIAN_GREEN
        ,PERSIAN_INDIGO
        ,PERSIAN_ORANGE
        ,PERSIAN_PINK
        ,PERSIAN_PLUM
        ,PERSIAN_RED
        ,PERSIAN_ROSE
        ,PERSIMMON
        ,PERU
        ,PHLOX
        ,PHTHALO_BLUE
        ,PHTHALO_GREEN
        ,PICTON_BLUE
        ,PICTORIAL_CARMINE
        ,PIGGY_PINK
        ,PINE_GREEN
        ,PINK_PANTONE
        ,PINK_LACE
        ,PINK_LAVENDER
        ,PINK_ORANGE
        ,PINK_PEARL
        ,PINK_SHERBET
        ,PISTACHIO
        ,PLUM_WEB
        ,POMP_AND_POWER
        ,POPSTAR
        ,PORTLAND_ORANGE
        ,POWDER_BLUE
        ,PRINCETON_ORANGE
        ,PRUNE
        ,PRUSSIAN_BLUE
        ,PSYCHEDELIC_PURPLE
        ,PUCE
        ,PUCE_RED
        ,PULLMAN_BROWN_UPS_BROWN
        ,PUMPKIN
        ,PURPLE_HTML
        ,PURPLE_MUNSELL
        ,PURPLE_X11
        ,PURPLE_HEART
        ,PURPLE_MOUNTAIN_MAJESTY
        ,PURPLE_NAVY
        ,PURPLE_PIZZAZZ
        ,PURPLE_TAUPE
        ,PURPUREUS
        ,QUARTZ
        ,QUEEN_BLUE
        ,QUEEN_PINK
        ,QUINACRIDONE_MAGENTA
        ,RACKLEY
        ,RADICAL_RED
        ,RAJAH
        ,RASPBERRY
        ,RASPBERRY_GLACE
        ,RASPBERRY_PINK
        ,RASPBERRY_ROSE
        ,RAW_UMBER
        ,RAZZLE_DAZZLE_ROSE
        ,RAZZMATAZZ
        ,RAZZMIC_BERRY
        ,RED_CRAYOLA
        ,RED_MUNSELL
        ,RED_NCS
        ,RED_PANTONE
        ,RED_PIGMENT
        ,RED_RYB
        ,RED_BROWN
        ,RED_DEVIL
        ,RED_ORANGE
        ,RED_PURPLE
        ,RED_VIOLET
        ,REDWOOD
        ,REGALIA
        ,RESOLUTION_BLUE
        ,RHYTHM
        ,RICH_BLACK
        ,RICH_BRILLIANT_LAVENDER
        ,RICH_CARMINE
        ,RICH_ELECTRIC_BLUE
        ,RICH_LAVENDER
        ,RICH_LILAC
        ,RICH_MAROON
        ,RIFLE_GREEN
        ,ROAST_COFFEE
        ,ROBIN_EGG_BLUE
        ,ROCKET_METALLIC
        ,ROMAN_SILVER
        ,ROSE
        ,ROSE_BONBON
        ,ROSE_EBONY
        ,ROSE_GOLD
        ,ROSE_MADDER
        ,ROSE_PINK
        ,ROSE_QUARTZ
        ,ROSE_RED
        ,ROSE_TAUPE
        ,ROSE_VALE
        ,ROSEWOOD
        ,ROSSO_CORSA
        ,ROSY_BROWN
        ,ROYAL_AZURE
        ,ROYAL_BLUE
        ,ROYAL_FUCHSIA
        ,ROYAL_PURPLE
        ,ROYAL_YELLOW
        ,RUBER
        ,RUBINE_RED
        ,RUBY
        ,RUBY_RED
        ,RUDDY
        ,RUDDY_BROWN
        ,RUDDY_PINK
        ,RUFOUS
        ,RUSSET
        ,RUSSIAN_GREEN
        ,RUSSIAN_VIOLET
        ,RUST
        ,RUSTY_RED
        ,SACRAMENTO_STATE_GREEN
        ,SADDLE_BROWN
        ,SAFETY_ORANGE_BLAZE_ORANGE
        ,SAFETY_YELLOW
        ,SAFFRON
        ,SAGE
        ,ST_PATRICKS_BLUE
        ,SALMON_PINK
        ,SAND
        ,SAND_DUNE
        ,SANDSTORM
        ,SANDY_BROWN
        ,SANDY_TAUPE
        ,SANGRIA
        ,SAP_GREEN
        ,SAPPHIRE
        ,SAPPHIRE_BLUE
        ,SATIN_SHEEN_GOLD
        ,SCARLET
        ,SCHAUSS_PINK
        ,SCHOOL_BUS_YELLOW
        ,SCREAMIN_GREEN
        ,SEA_BLUE
        ,SEA_GREEN
        ,SEAL_BROWN
        ,SEASHELL
        ,SELECTIVE_YELLOW
        ,SEPIA
        ,SHADOW
        ,SHADOW_BLUE
        ,SHAMPOO
        ,SHAMROCK_GREEN
        ,SHEEN_GREEN
        ,SHIMMERING_BLUSH
        ,SHOCKING_PINK
        ,SHOCKING_PINK_CRAYOLA
        ,SIENNA
        ,SILVER
        ,SILVER_CHALICE
        ,SILVER_LAKE_BLUE
        ,SILVER_PINK
        ,SILVER_SAND
        ,SINOPIA
        ,SKOBELOFF
        ,SKY_BLUE
        ,SKY_MAGENTA
        ,SLATE_BLUE
        ,SLATE_GRAY
        ,SMALT_DARK_POWDER_BLUE
        ,SMITTEN
        ,SMOKEY_TOPAZ
        ,SMOKY_BLACK
        ,SNOW
        ,SOAP
        ,SOLID_PINK
        ,SONIC_SILVER
        ,SPARTAN_CRIMSON
        ,SPACE_CADET
        ,SPANISH_BISTRE
        ,SPANISH_BLUE
        ,SPANISH_CARMINE
        ,SPANISH_CRIMSON
        ,SPANISH_GRAY
        ,SPANISH_GREEN
        ,SPANISH_ORANGE
        ,SPANISH_PINK
        ,SPANISH_RED
        ,SPANISH_SKY_BLUE
        ,SPANISH_VIOLET
        ,SPANISH_VIRIDIAN
        ,SPIRO_DISCO_BALL
        ,SPRING_BUD
        ,SPRING_GREEN
        ,STAR_COMMAND_BLUE
        ,STEEL_BLUE
        ,STEEL_PINK
        ,STIL_DE_GRAIN_YELLOW
        ,STIZZA
        ,STORMCLOUD
        ,STRAW
        ,STRAWBERRY
        ,SUNGLOW
        ,SUNRAY
        ,SUNSET
        ,SUNSET_ORANGE
        ,SUPER_PINK
        ,SUPER_CYAN
        ,TAN
        ,TANGELO
        ,TANGERINE
        ,TANGERINE_YELLOW
        ,TANGO_PINK
        ,TAUPE
        ,TAUPE_GRAY
        ,TEA_GREEN
        ,TEA_ROSE
        ,TEAL
        ,TEAL_BLUE
        ,TEAL_DEER
        ,TEAL_GREEN
        ,TELEMAGENTA
        ,TENN
        ,TERRA_COTTA
        ,THISTLE
        ,THULIAN_PINK
        ,TICKLE_ME_PINK
        ,TIFFANY_BLUE
        ,TIGERS_EYE
        ,TIMBERWOLF
        ,TITANIUM_YELLOW
        ,TOMATO
        ,TOOLBOX
        ,TOPAZ
        ,TRACTOR_RED
        ,TROLLEY_GREY
        ,TROPICAL_RAIN_FOREST
        ,TRUE_BLUE
        ,TUFTS_BLUE
        ,TULIP
        ,TUMBLEWEED
        ,TURKISH_ROSE
        ,TURQUOISE
        ,TURQUOISE_BLUE
        ,TURQUOISE_GREEN
        ,TUSCAN
        ,TUSCAN_BROWN
        ,TUSCAN_RED
        ,TUSCAN_TAN
        ,TUSCANY
        ,TWILIGHT_LAVENDER
        ,TYRIAN_PURPLE
        ,UA_BLUE
        ,UA_RED
        ,UBE
        ,UCLA_BLUE
        ,UCLA_GOLD
        ,UFO_GREEN
        ,ULTRAMARINE
        ,ULTRAMARINE_BLUE
        ,ULTRA_PINK
        ,ULTRA_RED
        ,UMBER
        ,BURNT_UMBER
        ,UNBLEACHED_SILK
        ,UNITED_NATIONS_BLUE
        ,UNIVERSITY_OF_CALIFORNIA_GOLD
        ,UNMELLOW_YELLOW
        ,UP_FOREST_GREEN
        ,UP_MAROON
        ,UPSDELL_RED
        ,UROBILIN
        ,USAFA_BLUE
        ,USC_CARDINAL
        ,USC_GOLD
        ,UNIVERSITY_OF_TENNESSEE_ORANGE
        ,UTAH_CRIMSON
        ,VANILLA
        ,VANILLA_ICE
        ,VEGAS_GOLD
        ,VENETIAN_RED
        ,VERDIGRIS
        ,VERMILION
        ,VERONICA
        ,VIOLET
        ,VIOLET_COLOR_WHEEL
        ,VIOLET_RYB
        ,VIOLET_WEB
        ,VIOLET_BLUE
        ,VIOLET_RED
        ,VIRIDIAN
        ,VIRIDIAN_GREEN
        ,VIVID_AUBURN
        ,VIVID_BURGUNDY
        ,VIVID_CERISE
        ,VIVID_ORCHID
        ,VIVID_SKY_BLUE
        ,VIVID_TANGERINE
        ,VIVID_VIOLET
        ,WARM_BLACK
        ,WATERSPOUT
        ,WENGE
        ,WHEAT
        ,WHITE_SMOKE
        ,WHITE_RED
        ,WILD_BLUE_YONDER
        ,WILD_ORCHID
        ,WILD_STRAWBERRY
        ,WILD_WATERMELON
        ,WILLPOWER_ORANGE
        ,WINDSOR_TAN
        ,WINE
        ,WINE_DREGS
        ,WISTERIA
        ,WOOD_BROWN
        ,XANADU
        ,YALE_BLUE
        ,YANKEES_BLUE
        ,YELLOW_CRAYOLA
        ,YELLOW_MUNSELL
        ,YELLOW_NCS
        ,YELLOW_PANTONE
        ,YELLOW_PROCESS
        ,YELLOW_RYB
        ,YELLOW_GREEN
        ,YELLOW_ORANGE
        ,YELLOW_ROSE
        ,ZAFFRE
        ,ZINNWALDITE_BROWN
        ,ZOMP
        ,RANDOM
        ,RANDOM_LIGHT
        ,RANDOM_DARK
        ,NUM_COLORS
        ,INVISIBLE_1
        ,TRANSPARENT_1
    };

}

class ColorFactory
{

public:
    /**
     * @brief create
     * @param rgba
     * @return
     */
    static Color create(const std::string & rgba);

    /**
     * @brief create
     * @param color
     * @return
     */
    static Color create(const colors::ColorType & color);

    /**
     * @brief create
     * @param r
     * @param g
     * @param b
     * @param a
     * @return
     */
    static Color create(const float & r, const float & g, const float & b, const float & a=1.0f);

    /**
     * @brief createNextColor
     * @return
     */
    static Color createNextColor();

    /**
     * @brief createRandomNamedColor
     * @return
     */
    static Color createRandomNamedColor();

    /**
     * @brief createRandomColor
     * @return
     */
    static Color createRandomColor();

    /**
     * @brief createRandomDarkColor
     * @return
     */
    static Color createRandomDarkColor();

    /**
     * @brief createRandomLightColor
     * @return
     */
    static Color createRandomLightColor();

    /**
     * @brief resetNextColor
     */
    static void resetNextColor();

private:
    ColorFactory();
    ColorFactory(const ColorFactory &);
    ColorFactory & operator=(const ColorFactory &);
};

namespace colorFunctions
{
    enum ColorFunction
    {
        ADD_5_RANDOM_COLORS,
        ADD_10_RANDOM_COLORS,
        ADD_15_RANDOM_COLORS,
        ADD_20_RANDOM_COLORS,
        ADD_5_RANDOM_LIGHT_COLORS,
        ADD_10_RANDOM_LIGHT_COLORS,
        ADD_15_RANDOM_LIGHT_COLORS,
        ADD_20_RANDOM_LIGHT_COLORS,
        ADD_5_RANDOM_DARK_COLORS,
        ADD_10_RANDOM_DARK_COLORS,
        ADD_15_RANDOM_DARK_COLORS,
        ADD_20_RANDOM_DARK_COLORS
    };
}
class ColorLoop
{

public:

    ColorLoop();

    /**
     * @brief operator <<
     * @param color
     * @return
     */
    ColorLoop & operator<<(const Color & color);

    /**
     * @brief operator <<
     * @param colorType
     * @return
     */
    ColorLoop & operator<< (const colors::ColorType & colorType);

    /**
     * @brief operator <<
     * @param function
     * @return
     */
    ColorLoop & operator<< (const colorFunctions::ColorFunction & function);

    /**
     * @brief generateUniqueColors
     * @param count
     */
    void generateUniqueColors(const size_t & count);

    /**
     * @brief getNextColor
     * @return
     */
    Color getNextColor();

    /**
     * @brief reset
     */
    void reset();

    /**
     * @brief clear
     */
    void clear();

    /**
     * @brief getColorAt
     * @param ndx
     * @return
     */
    Color getColorAt(size_t ndx) const;

    /**
     * @brief getCurrentColorNdx
     * @return
     */
    size_t getCurrentColorNdx() const;

    /**
     * @brief setCurrentColorNdx
     * @param ndx
     */
    void setCurrentColorNdx(size_t ndx);

private:
    size_t m_currentColor;
    std::vector<Color> m_colors;
    bool colorExists(const Color & color);
};
END_NAMESPACE_CBTEK_UTILITY
