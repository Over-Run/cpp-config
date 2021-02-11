/*
 * cpp_config.cpp
 *
 *  Created on: 2021/02/10
 *      Author: squid233
 */

#include "cpp_config/cpp_config.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<string> split(string str, string seperator, unsigned int limit) {
    str += seperator;
    string::size_type pos, size = str.size();
    vector<string> result;
    for (string::size_type i = 0; i < size; ++i) {
        pos = str.find(seperator, i);
        if (pos < size) {
            string s = str.substr(i, pos - i);
            result.push_back(s);
            if (result.size() == limit) {
                break;
            }
            i = pos + seperator.size() - 1;
        }
    }
    return result;
}

namespace config {
Config::Config() { }
Config::Config(string filename) {
    load(filename);
}
bool Config::load(string filename) {
    ifstream config(filename);
    if (config.is_open()) {
        string str;
        while (getline(config, str)) {
            if (str.compare(0, 1, "#") != 0) {
                vector<string> kv = split(str, "=", 2);
                if (kv.size() > 1) {
                    k2v.insert(pair<string, string>(kv[0], kv[1]));
                }
            }
        }
        config.close();
        return true;
    } else {
        cerr << "The file \"" << filename << "\" has not opened." << endl;
        return false;
    }
}
string Config::get(string key, string def) {
    return k2v.find(key) != k2v.end() ? k2v[key] : def;
}
bool Config::getB(string key, bool def) {
    string value = get(key);
    return (value != string("null")) ? (value == string("true")) : def;
}
string Config::get(string key) {
    return get(key, "null");
}
bool Config::getB(string key) {
    return getB(key, false);
}
map<string, string> Config::values() {
    return k2v;
}
}
