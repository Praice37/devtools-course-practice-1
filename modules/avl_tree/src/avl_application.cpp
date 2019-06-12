// Copyright 2019 Ivan Blagin

#include "include/avl_application.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>

std::string CAvlApplication::operator()(int argc, const char ** argv) {
    if (ValidateArguments(argc, argv)) {
        int64_t key;
        switch (xmap[op_]) {
        case etOperation::eSEARCH_ELEMENT:
            key = avl_.Find(searchElem_);
            return std::string(std::to_string(key));
            break;
        case etOperation::eSEARCH_MAX_ELEMENT:
            key = avl_.
            FindMax();
            return std::string(std::to_string(key));
            break;
        case etOperation::eSEARCH_MIN_ELEMENT:
            key = avl_.FindMin();
            return std::string(std::to_string(key));
            break;
        }
    }
    return message_;
}

void CAvlApplication::Help(
    const char * appname,
    const std::string& message) {
    message_ = std::string(message) +
        "\n\nThis is an avl application.\n"
        "Please provide arguments in the following format:\n\n"
        "$ " + appname +
        + " <key_1> <key_2> ... <key_k> <operation> <key>\n\n"
        "Where word_key is string and word_value is integer number, " +
        "and <operation> is one of\n"
        "-s' - search element,\n"
        "-smin' - search min element,\n"
        "-smax' - search max elemet,\n";
}

bool CAvlApplication::ValidateNumberOfArguments(
    int argc,
    const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc < 3) {
        Help(argv[0], "ERROR: Should be at least 2 arguments.\n\n");
        return false;
    }
    return true;
}

bool CAvlApplication::ValidateArguments(
    int argc,
    const char ** argv) {
    if (!ValidateNumberOfArguments(argc, argv)) {
        return false;
    }
    const char* itOp = nullptr;
    int indexOperation = 0;
    for (; indexOperation != argc; indexOperation++) {
        if (strcmp(argv[indexOperation], "-s") == 0
        || strcmp(argv[indexOperation], "-smin") == 0
        || strcmp(argv[indexOperation], "-smax") == 0) {
            itOp = argv[indexOperation];
            break;
        }
    }
    if (itOp) {
        int i = 1;
        while (i < indexOperation) {
            try {
                avl_.Insert(key(std::stoi(argv[i])));
            }
            catch (std::exception &e) {
                Help(argv[0], "Invalid key!" + std::string(e.what()));
                return false;
            }
            i++;
        }
        if (i == indexOperation) {
            op_ = itOp;
            if (xmap[op_] == etOperation::eSEARCH_ELEMENT) {
                if (i + 1 != argc) {
                        searchElem_ = std::stoi(argv[i + 1]);
                        return true;
                } else {
                    Help(argv[0], "Invalid search element!");
                    return false;
                }
            }
            return true;
        }
    }
    Help(argv[0], "Invalid operation!");
    return false;
}
