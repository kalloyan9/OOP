#pragma once

#include<iostream>
namespace static_namespace
{
    static const int MAX_STR_INPUT = 1000;
    static const char DATA_FILE_NAME[] = "users";
    static const int MAX_CMD_LEN = 6;
    using typedata = char*;

    static char listCommands[8][MAX_CMD_LEN] = {
        "exit", //0
        "log", //1
        "reg", //2
        "look",//3
        "add", //4
        "vdest",//5
        "addfr",//6
        "vcomm"//7
    };
    static char command[MAX_STR_INPUT];
}