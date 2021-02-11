/*
 * cpp_config.hpp
 *
 *  Created on: 2021/02/10
 *      Author: squid233
 */

#ifndef CPP_CONFIG_CPP_CONFIG_HPP_
#define CPP_CONFIG_CPP_CONFIG_HPP_

#include <map>
#include <string>

/**
 * @brief The Configurations object.
 * Example:
 *     config::Config cfg;
 *     cfg.load("myconfig.cfg");
 *     std::cout << cfg.get("key", "defaultValue");
 * myconfig.cfg:
 *     # comment
 *     key1=value
 *     key2=a value contains space
 *     # This below is invalid
 *     key3=#comment will read to value
 */
namespace config {
class Config {
public:
typedef const char* String;
/**
 * @brief Construct the configuration file reader object.
 */
Config();
/**
 * @brief Construct the configuration file reader object and load all K2Vs to map.
 * @param filename The file name.
 */
Config(String filename);
/**
 * @brief Load all K2Vs to map.
 * @param filename The file name.
 * @return If load success, return true, otherwise false.
 */
bool load(String filename);
/**
 * @brief Get the string value by key from the file.
 * This is nullable.
 * @param key The key.
 * @param def If the value is null, will return this param.
 */
std::string get(String key, std::string def);
/**
 * @brief Get the boolean value by key from the file.
 * @param key The key.
 * @param def If the value is null, will return this param.
 */
bool getB(String key, bool def);
std::string get(String key);
bool getB(String key);
std::map<std::string, std::string> values();
private:
std::map<std::string, std::string> k2v;
};
}

#endif /* CPP_CONFIG_CPP_CONFIG_HPP_ */
