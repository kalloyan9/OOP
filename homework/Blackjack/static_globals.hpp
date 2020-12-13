#pragma once
namespace static_globals
{
    static const int MAX_SIZE_SERIAL_NUM = 16;
    static const int MAX_SIZE_DECK_NUM = 10;
    static const int MAX_COLORS = 9;
    static const int MAX_POWER = 3;
    static const char* powers[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    static const char* colors[] = { "Spatiq", "Karo", "Kupa", "Pika" };
    static const int MAX_PLAYERS  = 20;
    static const int MAX_STR  = 128;
}