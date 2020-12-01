//
// Created by masha on 11/4/20.
//

#ifndef CPP_PRACTICE_STRING_H
#define CPP_PRACTICE_STRING_H

#endif //CPP_PRACTICE_STRING_H

#include <iostream>

/*
 * StringStream
 * Complete the parseInts function in the editor below.
 * parseInts has the following parameters:
 * string str: a string of comma separated integers
 * Returns
 * vector<int>: a vector of the parsed integers.
 * Note You can learn to push elements onto a vector by solving the first problem in the STL chapter.
 * Input Format
 * There is one line of n integers separated by commas.
 */
#include <sstream>
#include <vector>

std::vector<int> parseInts(std::string str) {
    // Complete this function
    std::vector<int> res_vector;
    std::stringstream ss(str);
    char ch;
    int tmp;
    while (ss) {
        ss >> tmp >> ch;
        res_vector.push_back(tmp);
    }
    return res_vector;
}

void call_parserInts() {
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        std::cout << integers[i] << "\n";
    }
}

/*
 * Strings
 * Input Format
 * You are given two strings, a and b, separated by a new line. Each string will consist of lower case Latin characters ('a'-'z').
 *
 * Output Format
 * In the first line print two space-separated integers, representing the length of a and b respectively.
 * In the second line print the string produced by concatenating a and b (a+b).
 * In the third line print two strings separated by a space, a' and b'.
 * a' and b' are the same as  and , respectively, except that their first characters are swapped.
 */
void strings()
{    std::string a;
    std::string b;

    std::cin >> a;
    std::cin >> b;

    std::cout << a.length() << " " << b.length() << std::endl;
    std::cout << a+b << std::endl;

    char tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;
    std::cout << a << " " << b << std::endl;}

/* Attribute Parser
 * This challenge works with a custom-designed markup language HRML. In HRML, each element consists of a starting and ending tag,
 * and there are attributes associated with each tag. Only starting tags can have attributes.
 * We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.
 * The opening tags follow the format: <tag-name attribute1-name = "value1" attribute2-name = "value2" ...>
 *  The closing tags follow the format: </tag-name>
 * The attributes are referenced as:
 *  tag1~value
 *  tag1.tag2~name
 *  Given the source code in HRML format consisting of N lines, answer Q queries.
 *  For each query, print the value of the attribute specified. Print "Not Found!" if the attribute does not exist.
 *  Input Format
 *      The first line consists of two space separated integers, N and Q. N specifies the number of lines in the HRML source program.
 *      Q specifies the number of queries.
 *      The following N lines consist of either an opening tag with zero or more attributes or a closing tag.
 *      There is a space after the tag-name, attribute-name, '=' and value.There is no space after the last value.
 *      If there are no attributes there is no space after tag name.
 *      Q queries follow. Each query consists of string that references an attribute in the source program. More formally,
 *      each query is of the form tagi1.tagi2.tagi3...tagim~attr - name where m>=1 and tagi1, tagi2...tagim are valid tags in the input.
 *  Output Format
 *      Print the value of the attribute for each query. Print "Not Found!" without quotes if the attribute does not exist.
*/
#include <unordered_map>
#include <iomanip>
void update_htmlr_bd(const std::string tag_prefix, const std::string &content,
                     std::unordered_map<std::string, std::string> &htmlr_db) {
    std::string attr, eq, value;
    std::istringstream ss{content};
    while (ss >> attr >> eq >> std::quoted(value)) {
        std::string key = tag_prefix + "~" + attr;
        htmlr_db.emplace(key, value);
    }
}

std::string get_tag_prefix(const std::string &tag, const std::vector<std::string> &tags_stack) {
    if (tags_stack.empty()) return tag;
    std::string prefix;
    for (std::string tg : tags_stack) { prefix += tg + "."; }
    return prefix + tag;
}

void call_attr_parser() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    std::cin >> n >> q;

    std::vector<std::string> tags_stack;
    std::unordered_map<std::string, std::string> htmlr_db;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < n; i++) {
        std::string raw_data;
        std::getline(std::cin, raw_data);

        if (raw_data[1] == '/') {
            tags_stack.pop_back();
        } else {
            std::string tag = raw_data.substr(1, raw_data.find(' ') - 1);
            if (tag[tag.length()-1] == '>') {tag = tag.substr(0, tag.length()-1);}
            std::string attr_content = raw_data.substr(raw_data.find(tag) + tag.length(), raw_data.size());
            update_htmlr_bd(get_tag_prefix(tag, tags_stack), attr_content, htmlr_db);
            tags_stack.push_back(tag);
        }
    }
    std::vector<std::string> query_list;
    for (int i = 0; i < q; i++) {
        std::string query;
        std::getline(std::cin, query);
        query_list.push_back(query);
    }

    for (int i = 0; i < q; i++) {
        auto search = htmlr_db.find(query_list[i]);
        if (search != htmlr_db.end()) {
            std::cout << search->second << std::endl;
        } else {
            std::cout << "Not Found!" << std::endl;
        }
    }
}