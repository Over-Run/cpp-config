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
 * @brief The version.
 * version  :  value
 * 0.1.0    :    100
 * 0.1.1    :    101
 * 0.1.99   :    199
 * 0.99.0   :   9900
 * 0.99.1   :   9901
 * 0.99.99  :   9999
 * 1.0.0    :  10000
 * 1.0.1    :  10001
 * 1.0.99   :  10099
 * 1.1.0    :  10100
 * 1.1.1    :  10101
 * 1.1.99   :  10199
 * 1.99.0   :  19900
 * 1.99.1   :  19901
 * 1.99.99  :  19999
 * 99.0.0   : 990000
 * 99.0.1   : 990001
 * 99.0.99  : 990099
 * 99.1.0   : 990100
 * 99.1.1   : 990101
 * 99.1.99  : 990199
 * 99.99.0  : 999900
 * 99.99.1  : 999901
 * 99.99.99 : 999999
 */
#define CPP_CONFIG_VERSION 300

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
/**
 * @brief Construct the configuration file reader object.
 */
Config();
/**
 * @brief Construct the configuration file reader object and load all K2Vs to map.
 * @param filename The file name.
 */
Config(std::string filename);
/**
 * @brief Load all K2Vs to map.
 * @param filename The file name.
 * @return If load success, return true, otherwise false.
 */
bool load(std::string filename);
/**
 * @brief Get the string value by key from the file.
 * This is nullable.
 * @param key The key.
 * @param def If the value is null, will return this param.
 */
std::string get(std::string key, std::string def);
/**
 * @brief Get the boolean value by key from the file.
 * @param key The key.
 * @param def If the value is null, will return this param.
 */
bool getB(std::string key, bool def);
std::string get(std::string key);
bool getB(std::string key);
std::map<std::string, std::string> values();
private:
std::map<std::string, std::string> k2v;
};
}

#endif /* CPP_CONFIG_CPP_CONFIG_HPP_ */
