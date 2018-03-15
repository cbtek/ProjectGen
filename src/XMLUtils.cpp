#include "XMLUtils.h"
#include "StringUtils.hpp"
#include "UtilityCommon.hpp"
#include "tinyxml2.h"

BEG_NAMESPACE_DSSI_UTILITY

XMLDataElement::XMLDataElement()
{
    m_Parent = nullptr;
    m_LocalIndex = 0;
}

XMLDataElement::XMLDataElement(const tinyxml2::XMLElement &element)
{
    m_Attributes.clear();
    for (const tinyxml2::XMLAttribute* attr = element.FirstAttribute(); attr!=0; attr = attr->Next())
    {
        m_Attributes.push_back(std::make_pair(std::string(attr->Name()),std::string(attr->Value())));
    }
    m_Name = std::string(element.Name());
    const char * text = element.GetText();
    if (text)
    {
        this->m_Data = std::string(text);
    }
    for (const tinyxml2::XMLElement* elem = element.FirstChildElement(); elem !=0; elem = elem->NextSiblingElement())
    {
        m_ChildElementVector.push_back(std::make_shared<XMLDataElement>(*elem));
        m_ChildElementVector.back()->setParent(this);
    }
}

XMLDataElement::~XMLDataElement()
{    
}

const std::string &XMLDataElement::getElementName() const
{
    return m_Name;
}

const AttributeVector &XMLDataElement::getAttributes() const
{
    return m_Attributes;
}

size_t XMLDataElement::getNumAttributes() const
{
    return m_Attributes.size();
}

std::string XMLDataElement::getAttributeName(size_t index) const
{
    if (index<m_Attributes.size())
    {
        return m_Attributes[index].first;
    }
    return "";
}

std::string XMLDataElement::getAttributeValue(size_t index) const
{
    if (index<m_Attributes.size())
    {
        return m_Attributes[index].second;
    }
    return "";
}

bool XMLDataElement::attributeExists(const std::string & attributeName, bool caseSensitive) const
{
    for(size_t a1 = 0;a1<m_Attributes.size();a1++)
    {
        if (caseSensitive)
        {
            if (m_Attributes[a1].first==attributeName)
            {
                return true;
            }
        }
        else
        {
            if (StringUtils::toUpper(m_Attributes[a1].first)==StringUtils::toUpper(attributeName))
            {
                return true;
            }
        }
    }
    return false;
}


std::string XMLDataElement::getElementData(bool trimmed) const
{
    return trimmed ? StringUtils::trimmed(m_Data) : m_Data;
}

int64_t XMLDataElement::getElementDataAsInteger() const
{
    return StringUtils::toInt(StringUtils::trimmed(getElementData()));
}

double XMLDataElement::getElementDataAsFloat() const
{
    return StringUtils::toFloat64(StringUtils::trimmed(getElementData()));
}

std::string XMLDataElement::getAttributeValue(const std::string & attributeName,
                                              bool caseSensitive) const
{

    for(size_t a1 = 0;a1<m_Attributes.size();a1++)
    {
        if (caseSensitive)
        {
            if (m_Attributes[a1].first==attributeName)
            {
                return m_Attributes[a1].second;
            }
        }
        else
        {
            if (StringUtils::toUpper(m_Attributes[a1].first)==StringUtils::toUpper(attributeName))
            {
                return m_Attributes[a1].second;
            }
        }
    }
    return "";
}

const ChildElementVector &XMLDataElement::getChildren() const
{
    return m_ChildElementVector;
}

bool XMLDataElement::hasChildren() const
{
    return m_ChildElementVector.size()>0;
}

XMLDataElement *XMLDataElement::getChildAt(size_t index) const
{
    return (index < m_ChildElementVector.size())?m_ChildElementVector[index].get():NULL;
}

XMLDataElement *XMLDataElement::getChild(const std::string &name) const
{
    for(XMLDataElementPtr element: m_ChildElementVector)
    {
        if (StringUtils::equals(element->getElementName(),name))
        {
            return element.get();
        }
    }
    return nullptr;
}

std::string XMLDataElement::getChildElementData(const std::string &name) const
{
    XMLDataElement * child = getChild(name);
    if (child)
    {
        return child->getElementData(true);
    }
    return "";
}

bool XMLDataElement::childExists(const std::string &name, bool caseSensitive)
{
    for (size_t a1 = 0;a1<m_ChildElementVector.size();a1++)
    {
        XMLDataElement * child= m_ChildElementVector[a1].get();
        if (caseSensitive)
        {
            if (child->getElementName()==name)
            {
                return true;
            }
        }
        else
        {
            if (StringUtils::toUpper(child->getElementName())==StringUtils::toUpper(name))
            {
                return true;
            }
        }
    }
    return false;

}

size_t XMLDataElement::getNumChildren() const
{
    return m_ChildElementVector.size();
}

void XMLDataElement::setElementData(const std::string &data)
{
    m_Data=data;
}

void XMLDataElement::setElementName(const std::string &name)
{
    m_Name=name;
}

void XMLDataElement::addAttribute(const std::string &attributeName,
                                  const std::string &attributeValue)
{
    m_Attributes.push_back(std::make_pair(attributeName,attributeValue));
}

void XMLDataElement::addChild(XMLDataElementPtr child)
{
    m_ChildElementVector.push_back(child);
}

void XMLDataElement::setParent(XMLDataElement *parent)
{
    m_Parent=parent;
}

XMLDataElement *XMLDataElement::getParent() const
{
    return m_Parent;
}

size_t XMLDataElement::getLocalIndex() const
{
    return m_LocalIndex;
}

size_t XMLDataElement::getChildIndex(const XMLDataElement *child) const
{
    for (size_t a1 = 0;a1<m_ChildElementVector.size();++a1)
    {
        if (child==m_ChildElementVector[a1].get())
        {
            return a1;
        }
    }
    return 0;
}

void XMLDataElement::setLocalIndex(size_t index)
{
    m_LocalIndex=index;
}

const XMLDataElement *XMLDataElement::find(const std::string &name,
                                           const bool &caseSensitive) const
{
    return findInSubTree(name,this,caseSensitive);
}

XMLDataElement *XMLDataElement::find(const std::string &name,
                                     const bool &caseSensitive)
{
    return findInSubTree(name,this,caseSensitive);
}

void XMLDataElement::addAttribute(const std::string &attributeName,
                                  const float &attributeValue)
{
    m_Attributes.push_back(std::make_pair(attributeName,StringUtils::toString(attributeValue)));
}

void XMLDataElement::addAttribute(const std::string &attributeName,
                                  const double &attributeValue)
{
    m_Attributes.push_back(std::make_pair(attributeName,StringUtils::toString(attributeValue)));
}

bool XMLDataElement::getAttributeValueAsBool(const std::string &attributeName) const
{
    std::string value = getAttributeValue(attributeName);
    if (StringUtils::toUpperTrimmed(value) == "TRUE")
    {
        return true;
    }
    else return false;
}

XMLDataElement *XMLDataElement::findInSubTree(const std::string & name,
                                              const XMLDataElement * element,
                                              const bool &caseSensitive)
{
    for (size_t a1 = 0;a1<element->getNumChildren();++a1)
    {
        XMLDataElement * child = element->getChildAt(a1);
        if (caseSensitive)
        {
            if (name==child->getElementName())
            {
                return child;
            }
        }
        else
        {
            if (StringUtils::toUpper(name)==StringUtils::toUpper(child->getElementName()))
            {
                return child;
            }
        }

        if (child->getNumChildren()>0)
        {
            XMLDataElement * subChild = findInSubTree(name,child,caseSensitive);
            if (subChild)
            {
                return subChild;
            }
        }
    }
    return NULL;
}


const XMLDataElement *XMLDataElement::findInSubTree(const std::string & name,
                                                    const XMLDataElement * element,
                                                    const bool &caseSensitive) const
{
    for (size_t a1 = 0;a1<element->getNumChildren();++a1)
    {
        const XMLDataElement * child = element->getChildAt(a1);
        if (caseSensitive)
        {
            if (name==child->getElementName())
            {
                return child;
            }
        }
        else
        {
            if (StringUtils::toUpper(name)==StringUtils::toUpper(child->getElementName()))
            {
                return child;
            }
        }

        if (child->getNumChildren()>0)
        {
            const XMLDataElement * subChild = findInSubTree(name,child,caseSensitive);
            if (subChild)
            {
                return subChild;
            }
        }
    }
    return NULL;
}

XMLDataElement *XMLDataElement::getNextSibling() const
{
    if (m_Parent)
    {
        size_t ndx = m_Parent->getChildIndex(this);
        return m_Parent->getChildAt(ndx+1);
    }
    return NULL;
}

XMLReader::XMLReader()
{

}


XMLReader::~XMLReader()
{
}

XMLDataElement *XMLReader::getRoot()
{    
    return this->m_root.get();
}

const XMLDataElement *XMLReader::getRoot() const
{
    return this->m_root.get();
}

XMLDataElement *XMLReader::getFirstElement()
{
    return this->m_root.get();
}

XMLDataElement *XMLReader::find(const std::string &name,
                                const bool & caseSensitive)
{
    return m_root->find(name,caseSensitive);
}

bool XMLReader::exists(const std::string &tagName,
                       const bool &caseSensitive)
{
    return this->getElement(tagName,caseSensitive)?true:false;
}

size_t XMLReader::getNumElements(const std::string &tagName,
                                 const bool & caseSensitive)
{
    const XMLDataElement * element = this->getElement(tagName,caseSensitive);
    if (element)
    {
        return element->getNumChildren();
    }
    std::string errMsg="(FATAL_XMLDataElement::getNumElements) : ";
    errMsg+="Could not find element with tag name equal to \""+tagName+"\"";
    throw InvalidOperationException(errMsg);
}

XMLDataElement *XMLReader::getElement(const std::string &dotNotation,
                                      const bool &caseSensitive)
{
    std::string tag;
       if (caseSensitive)
       {
           tag=dotNotation;
       }
       else
       {
           tag=StringUtils::toUpper(dotNotation);
       }

       std::vector<std::string> items = StringUtils::split(tag,".");
       std::string tagValue;
       XMLDataElement * element=m_root.get();

       if (caseSensitive)
       {
           tagValue=StringUtils::trimmed(dotNotation);
       }
       else
       {
           items[1]=StringUtils::toUpper(items[1]);
           tagValue=StringUtils::trimmed(dotNotation);
           tagValue=StringUtils::toUpper(tagValue);
       }


       if (items[0]==tagValue)
       {
           return element;
       }

       for(unsigned int a1=1;a1<items.size();a1++)
       {
           element = this->getChild(element,items[a1]);
           if (element)
           {
               std::string elementName =
                       StringUtils::toUpper(element->getElementName());
               std::string searchName =
                       StringUtils::toUpper(items[a1]);

               bool isValid = (elementName==searchName);
               if (!isValid)
               {
                   return nullptr;
               }
           }
           else
           {
               return nullptr;
           }
       }

       if (items.size()>0)
       {
           return element;
       }
       return nullptr;

}

bool XMLReader::load(const std::string & url)
{
    m_document.LoadFile(url.c_str());
    m_root = std::make_shared<XMLDataElement>(*m_document.RootElement());
}

std::string XMLReader::toString() const
{
    tinyxml2::XMLPrinter printer;
    m_document.Print(&printer);
    return std::string(printer.CStr());
}

size_t XMLReader::getNumLines() const
{
    return m_document.GetLineNum();
}


XMLDataElement *XMLReader::getFirst(XMLDataElement * node,
                                    const std::string name,
                                    const bool &caseSensitive)
{
    return m_root.get();
}

XMLDataElement *XMLReader::getChild(XMLDataElement *parent,
                                    const std::string & childName,
                                    const bool &caseSensitive)
{
    for (size_t a1 = 0;a1<parent->getNumChildren();a1++)
    {
        std::string childTag;
        std::string searchTag;
        if (caseSensitive)
        {
            childTag=childName;
            searchTag=parent->getChildAt(a1)->getElementName();
        }
        else
        {
            childTag = StringUtils::toUpper(childName);
            searchTag =
                    StringUtils::toUpper(parent->getChildAt(a1)->getElementName());
        }

        if (childTag==searchTag)
        {
            return parent->getChildAt(a1);
        }
    }
    return NULL;
}

std::string XMLUtils::getEncodedString(const std::string &rawString)
{
    std::string retStr;
    retStr=StringUtils::replace(rawString,"&","&amp;",true);
    retStr=StringUtils::replace(retStr,"\"","&quot;",true);
    retStr=StringUtils::replace(retStr,"<","&lt;",true);
    retStr=StringUtils::replace(retStr,">","&gt;",true);
    retStr=StringUtils::replace(retStr,"\n","&nl;",true);
    retStr=StringUtils::replace(retStr,"\t","&tab;",true);
    return retStr;
}

std::string XMLUtils::getDecodedString(const std::string &xmlString)
{
    std::string retStr;
    retStr=StringUtils::replace(xmlString,"&amp;","&",true);
    retStr=StringUtils::replace(retStr,"&quot;","\"",true);
    retStr=StringUtils::replace(retStr,"&lt;","<",true);
    retStr=StringUtils::replace(retStr,"&gt;",">",true);
    retStr=StringUtils::replace(retStr,"&nl;","\n",true);
    retStr=StringUtils::replace(retStr,"&tab;","\n",true);
    return retStr;
}

XMLStreamWriter::XMLStreamWriter(std::ostream &out)
    : m_out(out)
{
    m_currentTab = 0;
}

void XMLStreamWriter::writeStartDocument(const std::string &version, bool flag)
{
    m_out << "<?xml version=\""<<version<<"\" encoding=\"UTF-8\" standalone=\""<<(flag?"yes":"no")<<"\"?>"<<std::endl;
}

void XMLStreamWriter::writeStartElementNoAttributes(const std::string &tag)
{
    writeTabs();
    m_out <<"<"<<tag<<">\n";
    incrementTab();
}

void XMLStreamWriter::writeStartElement(const std::string &tag)
{
    writeTabs();
    m_out <<"<"<<tag;
    incrementTab();
}

void XMLStreamWriter::writeEndElement()
{
     m_out<<"/>"<<std::endl;
     decrementTab();
}

void XMLStreamWriter::writeEndElement(const std::string &tag)
{
    decrementTab();
    writeTabs();
    m_out<<"</"<<tag<<">"<<std::endl;
}

void XMLStreamWriter::writeTextElement(const std::string &tag, const std::string &text)
{
    writeTabs();
    m_out<<"<"<<tag<<">"<<text<<"</"<<tag<<">"<<std::endl;

}

void XMLStreamWriter::setCurrentTab(int tab)
{
    m_currentTab = tab;
}

void XMLStreamWriter::writeText(const std::string &text)
{
    m_out << XMLUtils::getEncodedString(text);
}

std::ostream &XMLStreamWriter::stream()
{
    return m_out;
}

XMLStreamWriter::~XMLStreamWriter()
{

}

void XMLStreamWriter::writeTabs()
{
    for (size_t a1 = 0;a1<m_currentTab;++a1)
    {
        m_out << "    ";
    }
}

void XMLStreamWriter::decrementTab()
{
    if (m_currentTab > 0)
    {
        m_currentTab--;
    }
}

void XMLStreamWriter::incrementTab()
{
    m_currentTab++;
}

END_NAMESPACE_DSSI_UTILITY
