/*
    XMLNameMap.h
    

*/
#pragma once

#include "XMLUtils.h"
#include "UtilityCommon.hpp"

#include <vector>
#include <string>

BEG_NAMESPACE_CBTEK_UTILITY

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
END_NAMESPACE_CBTEK_UTILITY
