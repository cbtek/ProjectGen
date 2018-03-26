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

#include "utility/inc/StringUtils.h"
#include "utility/inc/FileUtils.h"
#include "external/catch/inc/catch.hpp"

USE_NAMESPACE_CBTEK_UTILITY

static const std::string dataFolder = "testData/utility/";


TEST_CASE("Testing StringUtils::vectorContains","[utility::StringUtils]")
{
    std::vector<std::string> test1 = {"op","de","ark","gho"};
    std::vector<std::string> test2 = {"The Quick Turtle","The Slow Rabbit", "The Dumber Fox", "The Smart Fish"};

    REQUIRE(StringUtils::vectorContains("opie was destined to find the ghost in the park",test1,true) == true);
    REQUIRE(StringUtils::vectorContains("orie was dostined to Find the ghist in the PaRk",test1,true) == false);
    REQUIRE(StringUtils::vectorContains("opie was destined to Find the ghost in the PaRk",test1,false) == true);
    REQUIRE(StringUtils::vectorContains("",test1) == false);
    REQUIRE(StringUtils::vectorContains("",test2) == false);
    REQUIRE(StringUtils::vectorContains(test2,"The",true) == true);
    REQUIRE(StringUtils::vectorContains(test2,"Z",true) == false);
    REQUIRE(StringUtils::vectorContains(test2,"R",false) == true);
    REQUIRE(StringUtils::vectorContains("",{}) == false);

}
TEST_CASE("Testing StringUtils::indexOf","[utility::StringUtils]")
{
    REQUIRE(StringUtils::indexOf("office",{"the","chair","at","the","office","is","broken"},true) == 4);
    REQUIRE(StringUtils::indexOf("Office",{"the","chair","at","the","office","is","broken"},true) == std::string::npos);
    REQUIRE(StringUtils::indexOf("Office",{"the","chair","at","the","office","is","broken"},false) == 4);
    REQUIRE(StringUtils::indexOf("CHAIR",{"the","chair","at","the","office","is","broken"},false) == 1);
    REQUIRE(StringUtils::indexOf("",{"the","chair","at","the","office","is","broken"},false) == std::string::npos);
    REQUIRE(StringUtils::indexOf("Office",{},false) == std::string::npos);
    REQUIRE(StringUtils::indexOf("",{"the","","at","the","office","is","broken"},false) == 1);
}

TEST_CASE("Testing StringUtils::textAfter","[utility::StringUtils]")
{
    REQUIRE(StringUtils::textAfter("A moon rises in the east!","moon",true) == " rises in the east!");
    REQUIRE(StringUtils::textAfter("A moon rises in the east!","Moon",false) == " rises in the east!");
    REQUIRE(StringUtils::textAfter("A moon rises in the east!","Moon",true) == "");
    REQUIRE(StringUtils::textAfter("A moon rises in the east!","") == "");
    REQUIRE(StringUtils::textAfter("","moon") == "");
}

TEST_CASE("Testing StringUtils::removeInPlace","[utility::StringUtils]")
{
    std::string test1="The Quick Brown Fox";
    REQUIRE(StringUtils::removeInPlace(test1,"o",false) == 2);
    REQUIRE(test1 == "The Quick Brwn Fx");
}

TEST_CASE("Testing StringUtils::toHexString","[utility::StringUtils]")
{
    REQUIRE(StringUtils::toHexString(11259309) == "0xabcdad");
}

TEST_CASE("Testing StringUtils::formatThousandsLabel","[utility::StringUtils]")
{
    REQUIRE(StringUtils::formatWithThousandsLabel("1000") == "1,000");
    REQUIRE(StringUtils::formatWithThousandsLabel("") == "");
    REQUIRE(StringUtils::formatWithThousandsLabel("ABC") == "ABC");
    REQUIRE(StringUtils::formatWithThousandsLabel("22987345123456") == "22,987,345,123,456");
}
TEST_CASE("Testing StringUtils::replace","[utility::StringUtils]")
{

    REQUIRE(StringUtils::replace("THE QUICK brown Fox JUMPED Over THE Moon!","o","X") ==
            "THE QUICK brXwn FXx JUMPED Over THE MXXn!");

    REQUIRE(StringUtils::replace("THE QUICK brown Fox JUMPED Over THE Moon!","o","X",false) ==
            "THE QUICK brXwn FXx JUMPED Xver THE MXXn!");

    REQUIRE(StringUtils::replace("THE QUICK brown Fox JUMPED Over THE Moon!","t","",false) ==
            "HE QUICK brown Fox JUMPED Over HE Moon!");

    REQUIRE(StringUtils::replace("THE QUICK brown Fox JUMPED Over THE Moon!","Z","ABC",false) ==
            "THE QUICK brown Fox JUMPED Over THE Moon!");

    REQUIRE(StringUtils::replace("","o","X",false) == "");

}

TEST_CASE("Testing StringUtils::rightTrimmed","[utility::StringUtils]")
{
    REQUIRE(StringUtils::rightTrimmed("\r\r\r\n\tTHE Quick BROWN FOX    \n\r\t") == "\r\r\r\n\tTHE Quick BROWN FOX");
    REQUIRE(StringUtils::rightTrimmed("\r\r\r\n\t    \n\r\t") == "");
    REQUIRE(StringUtils::rightTrimmed("") == "");
}

TEST_CASE("Testing StringUtils::leftTrimmed","[utility::StringUtils]")
{
    REQUIRE(StringUtils::leftTrimmed("\r\r\r\n\tTHE Quick BROWN FOX    \n\r\t") == "THE Quick BROWN FOX    \n\r\t");
    REQUIRE(StringUtils::leftTrimmed("\r\r\r\n\t    \n\r\t") == "");
    REQUIRE(StringUtils::leftTrimmed("") == "");
}

TEST_CASE("Testing StringUtils::trimmed","[utility::StringUtils]")
{
    REQUIRE(StringUtils::trimmed("\r\r\r\n\tTHE Quick BROWN FOX    \n\r\t") == "THE Quick BROWN FOX");
    REQUIRE(StringUtils::trimmed("\r\r\r\n\t    \n\r\t") == "");
    REQUIRE(StringUtils::trimmed("") == "");
}

TEST_CASE("Testing StringUtils::splitKeyValue","[utility::StringUtils]")
{
    std::string test1 = " T1<%>   T2";
    std::string test2 = "" ;
    std::string test3 = " MyKey:";
    std::string test4 = ":MyValue";

    auto result1 = StringUtils::splitKeyValue(test1,"<%>",true);
    auto result2 = StringUtils::splitKeyValue(test2,"<%>");
    auto result3 = StringUtils::splitKeyValue(test3,":",false);
    auto result4 = StringUtils::splitKeyValue(test4,":");

    REQUIRE(result1.first == "T1");
    REQUIRE(result1.second == "T2");
    REQUIRE(result2.first == "");
    REQUIRE(result2.second == "");
    REQUIRE(result3.first == " MyKey");
    REQUIRE(result3.second == "");
    REQUIRE(result4.first == "");
    REQUIRE(result4.second == "MyValue");
}

TEST_CASE("Testing StringUtils::isEmpty","[utility::StringUtils]")
{
    std::string test1 = "The Quick Brown Fox      ";
    std::string test2 = "";
    std::string test3 = "                                  .";
    std::string test4 = "                       ";
    REQUIRE(StringUtils::isEmpty(test1) == false);
    REQUIRE(StringUtils::isEmpty(test2) == true);
    REQUIRE(StringUtils::isEmpty(test3) == false);
    REQUIRE(StringUtils::isEmpty(test4) == true);
}

TEST_CASE("Testing StringUtils::join","[utility::StringUtils]")
{
    std::vector<std::string> container = {"The","Quick","Brown","Fox"};
    REQUIRE(StringUtils::join(container,"And","Pre","Post") ==
            "PreThePostAndPreQuickPostAndPreBrownPostAndPreFoxPost");
}

TEST_CASE("Testing StringUtils::createUniqueUUIDList","[utility::StringUtils]")
{
    std::vector<std::string> uuid_vector = StringUtils::createUniqueUUIDList(1000);
    std::set<std::string> uuid_set(uuid_vector.begin(),uuid_vector.end());
    REQUIRE(uuid_set.size() == uuid_vector.size() );
}

TEST_CASE("Testing StringUtils::removeTextAfter","[utility::StringUtils]")
{
    std::string sentence = "A Fast Hound Hunted a Red Fox And Passed The Quick Car";
    REQUIRE(StringUtils::removeTextAfter(sentence,"a Red Fox",true) == "A Fast Hound Hunted a Red Fox");
}

TEST_CASE("Testing StringUtils::multiequals","[utility::StringUtils]")
{
    std::vector<std::string> search_tokens1 = {"The","Quick","Red","Fox"};
    std::vector<std::string> search_tokens2 = {"THE","QUICK","Red","Fox"};
    std::vector<std::string> search_tokens3 = {"The","Fast","RED","Dog"};
    std::vector<std::string> search_tokens4;
    std::string sentence = "A Fast Hound Hunted a Red Fox And Passed The Quick Car";
    REQUIRE(StringUtils::multiequals(sentence,search_tokens1,true) == true);
    REQUIRE(StringUtils::multiequals(sentence,search_tokens2,false) == true);
    REQUIRE(StringUtils::multiequals(sentence,search_tokens3,true) == false);
    REQUIRE(StringUtils::multiequals(sentence,search_tokens4,true) == false);
}

TEST_CASE("Testing StringUtils::toLower","[utility::StringUtils]")
{
    std::string text1 = "LOWeR_%CaSE";
    REQUIRE(StringUtils::toLower(text1) == "lower_%case");
}


TEST_CASE("Testing StringUtils::isNumeric","[utility::StringUtils]")
{
    std::string test1 = "1.1234";
    std::string test2 = "-100,231,334.1234";
    std::string test3 = ".";
    std::string test4 = "-";
    std::string test5 = "$-5,000.00";
    std::string test6 = "-$5,000.00";
    std::string test7 = "";

    REQUIRE(StringUtils::isNumeric(test1) == true);
    REQUIRE(StringUtils::isNumeric(test2) == true);
    REQUIRE(StringUtils::isNumeric(test3) == false);
    REQUIRE(StringUtils::isNumeric(test4) == false);
    REQUIRE(StringUtils::isNumeric(test5) == true);
    REQUIRE(StringUtils::isNumeric(test6) == true);
    REQUIRE(StringUtils::isNumeric(test7) == false);
}



TEST_CASE("Testing StringUtils::isWholeWord","[utility::StringUtils]")
{
    std::string data = "The Quick Brown $foxjumped over the $foxxy moon with a $fox and $fox_";
    std::vector<size_t> wholeWords = StringUtils::getWholeWords(data,"$fox");
    REQUIRE(wholeWords.size() == 2);
    REQUIRE(wholeWords[0] == 55);
    REQUIRE(wholeWords[1] == 64);
}

TEST_CASE("Testing StringUtils::findAllThatStartWith","[utility::StringUtils]")
{
    std::vector<std::string> test;
    test.push_back("hello");
    test.push_back("crazy");
    test.push_back("world");
    test.push_back("held");
    StringUtils::removeAllThatStartWith(test,"H",true);
    REQUIRE(test.size()==4);
    StringUtils::removeAllThatStartWith(test,"H",false);
    REQUIRE(test.size()==2);
    StringUtils::removeAllThatStartWith(test,"wo",false);
    REQUIRE(test.size()==1);
    REQUIRE(test[0] == "crazy");
}

TEST_CASE("Testing StringUtils::findAllThatContain","[utility::StringUtils]")
{
    std::vector<std::string> test;
    test.push_back("hello");
    test.push_back("crazy");
    test.push_back("world");
    test.push_back("worldly");
    StringUtils::removeAllThatContain(test,"O",true);
    REQUIRE(test.size()==4);
    StringUtils::removeAllThatContain(test,"O",false);
    REQUIRE(test.size()==1);
    StringUtils::removeAllThatContain(test,"az",false);
    REQUIRE(test.size()==0);
}

TEST_CASE("Testing StringUtils::findAllThatEndWith","[utility::StringUtils]")
{
    std::vector<std::string> test;
    test.push_back("hello");
    test.push_back("crazy");
    test.push_back("world");
    test.push_back("meld");
    StringUtils::removeAllThatEndWith(test,"O",true);
    REQUIRE(test.size()==4);
    StringUtils::removeAllThatEndWith(test,"O",false);
    REQUIRE(test.size()==3);
    StringUtils::removeAllThatEndWith(test,"ld",false);
    REQUIRE(test.size()==1);
    REQUIRE(test[0] == "crazy");
}

TEST_CASE("Testing StringUtils::eraseFromVector","[utility::StringUtils]")
{
    std::vector<std::string> test;
    test.push_back("hello");
    test.push_back("crazy");
    test.push_back("world");
    StringUtils::vectorErase(test,"hello2");
    REQUIRE(test.size()==3);
    StringUtils::vectorErase(test,"hellO",true);
    REQUIRE(test.size()==3);
    StringUtils::vectorErase(test,"krazy");
    REQUIRE(test.size()==3);
    StringUtils::vectorErase(test,"crazy");
    REQUIRE(test.size()==2);
    REQUIRE(test[0]=="hello");
    REQUIRE(test[1]=="world");

}


TEST_CASE("Testing StringUtils::removeNonAlphaNumeric","[utility::StringUtils]")
{
    std::string str = "~!@#$%^&T*()_+{}|\"{}|\\:;'\"<,>.?/-=\r\r\n\f\t~E!@#$%^&*()_+{}|\"{}|\\:;'\"<,>.?/-=\r\rS\n\fT\t";
    REQUIRE(StringUtils::removeNonAlphaNumeric(str) == "TEST");
}

TEST_CASE("Testing StringUtils::toString","[utility::StringUtils")
{
    double value1 = 122104432.23456789;
    double value2 = 1.23;    
    std::uint64_t value3 = 99123456789;
    std::uint64_t value4 = 72;    
    std::int64_t value5 = -262315;
    double value6 = -903172.0112;
    double value7 = 102234.00;

    REQUIRE(StringUtils::toString(value1,2) == "122,104,432.23");
    REQUIRE(StringUtils::toString(value2,1) == "1.2");
    REQUIRE(StringUtils::toString(value3) == "99,123,456,789");
    REQUIRE(StringUtils::toString(value4) == "72");
    REQUIRE(StringUtils::toString(value5) == "-262,315");
    REQUIRE(StringUtils::toString(value6,2) == "-903,172.01");
    REQUIRE(StringUtils::toString(value7,2) == "102,234.00");

    REQUIRE(StringUtils::toString(value1,2) == "122104432.23");
    REQUIRE(StringUtils::toString(value2,1) == "1.2");
    REQUIRE(StringUtils::toString(value3) == "99123456789");
    REQUIRE(StringUtils::toString(value4) == "72");
    REQUIRE(StringUtils::toString(value5) == "-262315");
    REQUIRE(StringUtils::toString(value6,2) == "-903172.01");
    REQUIRE(StringUtils::toString(value7,2) == "102234.00");
}

TEST_CASE("Testing StringUtils::multisplit","[utility::StringUtils]")
{
    std::string str = "test,are!you?happy?with!,me";
    std::vector<std::string> delims {",", "!", "?"};
    std::vector<std::string> output = StringUtils::multisplit(str,delims);
    REQUIRE(output.size() == 7);

    //Output items ordered by delimiter NOT by order in original string
    //Items split by comma
    REQUIRE(output[0] == "test");
    REQUIRE(output[1] == "me");

    //Items split by exclaimation
    REQUIRE(output[2] == "are");
    REQUIRE(output[3] == "");

    //Items split by question
    REQUIRE(output[4] == "you");
    REQUIRE(output[5] == "happy");
    REQUIRE(output[6] == "with");
}


TEST_CASE("Testing StringUtils::multiremove","[utility::StringUtils]")
{
    std::string input = "xg<WHATSUP>test,are!you?happy?with!,me";
    std::string output = StringUtils::multiremove(input,{",", "!", "?","<WHATSUP>"});
    REQUIRE(output == "xgtestareyouhappywithme");
}
