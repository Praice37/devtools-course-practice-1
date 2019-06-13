// Copyright 2019 Aksenov Nikita

#include "include/line_plane_intersection_app.h"

#include <stdlib.h>
#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    LinePlaneIntersectionApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
