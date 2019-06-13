// Copyright 2019 Aksenov Nikita

#ifndef MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_APP_H_
#define MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_APP_H_

#include "include/line_plane_intersection.h"

#include <string>

class LinePlaneIntersectionApp {
 public:
    LinePlaneIntersectionApp();
    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;
    void Help(const char* appname, const char* message = " ");
    bool ValidateNumberOfArguments(int argc, const char** argv);

    typedef struct {
        std::string operation;
        Dot* plane;
        Dot* line;
    } Arguments;

};

#endif  // MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_APP_H_
