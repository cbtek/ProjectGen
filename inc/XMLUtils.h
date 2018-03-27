/** @file XMLUtils.h
 *
 * @details This file contains classes and utilities
 * for the basic parsing of XML files.
 *
 */

#pragma once

//std headers
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <memory>

//utility headers
#include "Exception.hpp"
#include "FileUtils.h"
#include "StringUtils.h"
#include "UtilityCommon.hpp"

//tinyxml headers
#include "utility/external/tinyxml2/inc/tinyxml2.h"

BEG_NAMESPACE_CBTEK_UTILITY

class XMLDataElement;
using XMLDataElementPtr = std::shared_ptr<XMLDataElement>;
typedef std::vector<XMLDataElementPtr> ChildElementVector;
typedef std::vector<std::pair<std::string, std::string> > AttributeVector;

struct XMLNameMapNode
{
    std::string value;
    std::string key;
    std::string id;
    std::string tag;
    std::string alias;
    std::string type;
    std::string description;
    std::vector<XMLNameMapNode> children;
    std::map<std::string,std::string> custom_attributes;
    const XMLNameMapNode find(const std::string &address_key) const;
    bool find(const std::string &address_key, XMLNameMapNode &node) const;
};

class XMLNameMap
{
public:
   /**
    * @brief XMLNameMap
    */
    XMLNameMap();

    /**
     * @brief load
     * @param file_path
     */
    void load(const std::string &file_path);

    /**
     * @brief operator []
     * @param key
     * @return
     */
    const XMLNameMapNode &operator[](const std::string &key) const;

    /**
     * @brief operator []
     * @param key
     * @return
     */
    XMLNameMapNode &operator[](const std::string &key);


    /**
     * Destructor for this XMLNameMap
     */
    ~XMLNameMap();
private:
    XMLNameMapNode m_root_node;
    void loadNested(const XMLDataElement *root,
                    XMLNameMapNode & parent);

};
class CBTEK_UTILITY_DLL XMLDataElement
{
public:
    /**
     * @brief XMLDataElement
     */
    XMLDataElement();

    /**
     * @brief XMLDataElement
     * @param element
     */
    XMLDataElement(const tinyxml2::XMLElement &element);

    /**
     * @brief XMLDataElement
     * @param element
     */
    XMLDataElement(const XMLDataElement & element);

    /**
     * @brief XMLDataElement
     */
    ~XMLDataElement();

    /**
     * @brief getAttributes
     * @return
     */
    const AttributeVector &getAttributes() const;

    /**
     * @brief getChildren
     * @return
     */
    const ChildElementVector & getChildren() const;

    /**
     * @brief getElementName
     * @return
     */
    const std::string &getElementName() const;

    /**
     * @brief getElementData
     * @param trimmed
     * @return
     */
    std::string getElementData(bool trimmed = false) const;

    /**
     * @brief getElementDataAsInteger
     * @return
     */
    std::int64_t getElementDataAsInteger() const;

    /**
     * @brief getElementDataAsFloat
     * @return
     */
    double getElementDataAsFloat() const;

    /**
     * @brief getAttributeValue
     * @param attributeName
     * @param caseSensitive
     * @return
     */
    std::string getAttributeValue(const std::string & attributeName, bool caseSensitive = false) const;

    /**
     * @brief getAttributeName
     * @param index
     * @return
     */
    std::string getAttributeName(size_t index)const;

    /**
     * @brief getAttributeValue
     * @param index
     * @return
     */
    std::string getAttributeValue(size_t index) const;

    /**
     * @brief getParent
     * @return
     */
    XMLDataElement * getParent() const;

    /**
     * @brief getNextSibling
     * @return
     */
    XMLDataElement * getNextSibling() const;

    /**
     * @brief getChildAt
     * @param index
     * @return
     */
    XMLDataElement * getChildAt(size_t index)const;

    /**
     * @brief getChild
     * @param name
     * @return
     */
    XMLDataElement * getChild(const std::string & name) const;

    /**
     * @brief getChildElementData
     * @param name
     * @return
     */
    std::string getChildElementData(const std::string& name) const;

    /**
     * @brief attributeExists
     * @param attributeName
     * @param caseSensitive
     * @return
     */
    bool attributeExists(const std::string &attributeName, bool caseSensitive = false) const;

    /**
     * @brief hasChildren
     * @return
     */
    bool hasChildren() const;

    /**
     * @brief childExists
     * @param index
     * @return
     */
    bool childExists(size_t index);

    /**
     * @brief childExists
     * @param name
     * @param caseSensitive
     * @return
     */
    bool childExists(const std::string & name, bool caseSensitive = false);

    /**
     * @brief getNumChildren
     * @return
     */
    size_t getNumChildren() const;

    /**
     * @brief getNumAttributes
     * @return
     */
    size_t getNumAttributes() const;

    /**
     * @brief getLocalIndex
     * @return
     */
    size_t getLocalIndex() const;

    /**
     * @brief getChildIndex
     * @param child
     * @return
     */
    size_t getChildIndex(const XMLDataElement * child) const;

    /**
     * @brief setElementData
     * @param data
     */
    void setElementData(const std::string & data);

    /**
     * @brief setElementName
     * @param name
     */
    void setElementName(const std::string & name);

    /**
     * @brief addAttribute
     * @param attributeName
     * @param attributeValue
     */
    void addAttribute(const std::string & attributeName, const std::string & attributeValue);

    /**
     * @brief addChild
     * @param child
     */
    void addChild(XMLDataElementPtr child);

    /**
     * @brief setParent
     * @param parent
     */
    void setParent(XMLDataElement *parent);

    /**
     * @brief setLocalIndex
     * @param index
     */
    void setLocalIndex(size_t index);

    /**
     * @brief find
     * @param name
     * @param caseSensitive
     * @return
     */
    XMLDataElement * find(const std::string & name, const bool & caseSensitive = false);

    /**
     * @brief find
     * @param name
     * @param caseSensitive
     * @return
     */
    const XMLDataElement * find(const std::string & name, const bool & caseSensitive = false) const;

    /**
     * @brief addAttribute
     * @param attributeName
     * @param attributeValue
     */
    void addAttribute(const std::string & attributeName, const float & attributeValue);

    /**
     * @brief addAttribute
     * @param attributeName
     * @param attributeValue
     */
    void addAttribute(const std::string & attributeName, const double & attributeValue);

    /**
     * @brief addAttribute
     * @param attributeName
     * @param attributeValue
     */
    template<typename T>
    void addAttribute(const std::string & attributeName, const T & attributeValue)
    {
        m_Attributes.push_back(
            std::make_pair(attributeName,
                StringUtils::toString(attributeValue)));
    }

    /**
     * @brief getAttributeValueAsType
     * @param attributeName
     * @return
     */
    template <typename Number>
    Number getAttributeValueAsType(const std::string& attributeName) const
    {
        Number valueNumber;
        std::string valueStr = getAttributeValue(attributeName);
        std::stringstream in(valueStr);
        in >> valueNumber;
        return valueNumber;
    }


    /**
     * @brief getChildElementDataAsType
     * @param name
     * @return
     */
    template <typename Number>
    Number getChildElementDataAsType(const std::string& name) const
    {
        std::string data = getChildElementData(name);
        if (!data.empty())
        {
            Number valueNumber;
            std::stringstream in(data);
            in >> valueNumber;
            return valueNumber;
        }
        return 0;
    }

    /**
     * @brief getAttributeValueAsBool
     * @param attributeName
     * @return
     */
    bool getAttributeValueAsBool(const std::string& attributeName) const;

protected:

    /**
     * @brief findInSubTree
     * @param name
     * @param element
     * @param caseSensitive
     * @return
     */
    XMLDataElement *findInSubTree(const std::string & name,
        const XMLDataElement *element,
        const bool &caseSensitive);

    /**
     * @brief findInSubTree
     * @param name
     * @param element
     * @param caseSensitive
     * @return
     */
    const XMLDataElement *findInSubTree(const std::string & name,
        const XMLDataElement *element,
        const bool &caseSensitive) const;

    size_t m_LocalIndex;
    std::string m_Name;
    std::string m_Data;
    std::string m_Temp;
    AttributeVector m_Attributes;
    ChildElementVector m_ChildElementVector;        
    XMLDataElement * m_Parent;
};

class CBTEK_UTILITY_DLL XMLReader
{

public:
    XMLReader();
    ~XMLReader();
    /**
     * @brief load
     * @param filename
     * @return
     */
    bool load(const std::string & filename);

    /**
     * @brief getElement
     * @param tagName
     * @param caseSensitive
     * @return
     */
    XMLDataElement * getElement(const std::string & tagName,
        const bool & caseSensitive = false);

    /**
     * @brief find
     * @param name
     * @param caseSensitive
     * @return
     */
    XMLDataElement * find(const std::string & name,
        const bool & caseSensitive = false);

    /**
     * @brief getNumElements
     * @param tagName
     * @param caseSensitive
     * @return
     */
    size_t  getNumElements(const std::string & tagName,
        const bool & caseSensitive = false);


    /**
     * @brief exists
     * @param tagName
     * @param caseSensitive
     * @return
     */
    bool exists(const std::string & tagName,
        const bool & caseSensitive = false);

    /**
     * @brief toString
     * @return
     */
    std::string toString()const;

    /**
     * @brief getRoot
     * @return
     */
    XMLDataElement * getRoot();

    /**
     * @brief getRoot
     * @return
     */
    const XMLDataElement *getRoot() const;

    /**
     * @brief getNumLines
     * @return
     */
    size_t getNumLines()const;

    /**
     * @brief getFirstElement
     * @return
     */
    XMLDataElement *getFirstElement();

private:

    /**
     * @brief getFirst
     * @param node
     * @param name
     * @param caseSensitive
     * @return
     */
    XMLDataElement * getFirst(XMLDataElement *node,
        const std::string name,
        const bool & caseSensitive = false);

    /**
     * @brief getChild
     * @param parent
     * @param childName
     * @param caseSensitive
     * @return
     */
    XMLDataElement * getChild(XMLDataElement * parent,
        const std::string &childName,
        const bool & caseSensitive = false);

    tinyxml2::XMLDocument m_document;
    XMLDataElementPtr m_root;
};

class CBTEK_UTILITY_DLL XMLUtils
{
public:
    /**
     * @brief getEncodedString
     * @param rawString
     * @return
     */
    static std::string getEncodedString(const std::string &  rawString);

    /**
     * @brief getDecodedString
     * @param xmlString
     * @return
     */
    static std::string getDecodedString(const std::string & xmlString);
};

class CBTEK_UTILITY_DLL XMLStreamWriter
{
public:
    //! Constructor for XMLStreamWriter
    XMLStreamWriter(std::ostream & out);

    /**
     * @brief writeStartDocument
     * @param version
     * @param flag
     */
    void writeStartDocument(const std::string & version = "1.0", bool flag = true);

    /**
     * @brief writeStartElementNoAttributes
     * @param tag
     */
    void writeStartElementNoAttributes(const std::string & tag);

    /**
     * @brief writeStartElement
     * @param tag
     */
    void writeStartElement(const std::string & tag);

    /**
     * @brief writeEndElement
     */
    void writeEndElement();

    /**
     * @brief writeEndElement
     * @param tag
     */
    void writeEndElement(const std::string &tag);

    /**
     * @brief writeTextElement
     * @param tag
     * @param text
     */
    void writeTextElement(const std::string & tag, const std::string & text);

    /**
     * @brief writeLastAttribute
     * @param attributeName
     * @param attributeValue
     */
    template<typename ValueType>
    void writeLastAttribute(const std::string & attributeName,
        const ValueType& attributeValue)
    {

        writeAttribute(attributeName, attributeValue);
        m_out << ">" << std::endl;
    }


    /**
     * @brief setCurrentTab
     * @param tab
     */
    void setCurrentTab(int tab);


    /**
     * @brief writeText
     * @param text
     */
    void writeText(const std::string& text);

    /**
     * @brief writeLastAttribute
     * @param attributeName
     * @param attributeValue
     */
    template<typename ValueType>
    void writeLastAttributeAndCloseTag(const std::string & attributeName,
        const ValueType & attributeValue)
    {
        writeAttribute(attributeName, attributeValue);
        m_out << "/>" << std::endl;
        if (m_currentTab > 0)
        {
            m_currentTab--;
        }
    }

    /**
     * @brief writeAttribute
     * @param attributeName
     * @param attributeValue
     */
    template<typename ValueType>
    void writeAttribute(const std::string &attributeName,
                        const ValueType &attributeValue,
                        bool lastAttribute = false)
    {
        m_out << " " << attributeName << "=\"" << XMLUtils::getEncodedString(StringUtils::toString(attributeValue)) << "\"";
        if (lastAttribute)
        {
            m_out << ">" << std::endl;
        }
    }

    /**
     * @brief out
     * @return
     */
    std::ostream & stream();

    //! Destructor
    ~XMLStreamWriter();

private:
    void writeTabs();
    void decrementTab();
    void incrementTab();
    std::string m_currentNS;
    size_t m_currentTab;
    std::ostream & m_out;
};

END_NAMESPACE_CBTEK_UTILITY
