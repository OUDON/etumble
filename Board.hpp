#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Ball.hpp"

enum Color {
    BLUE,
    RED,
};

enum Item {
    EMPTY,
    RAMP_GOING_LEFT,
    RAMP_GOING_RIGHT,
    BIT_POINTING_LEFT,
    BIT_POINTING_RIGHT,
    GEAR_BIT_POINTING_LEFT,
    GEAR_BIT_POINTING_RIGHT,
    GEAR,
    CROSS_OVER,
    INTER_CEPTER,
};

class Board {
    Ball *ball;
    std::vector<Ball> results;
    std::vector<std::vector<Item>> cells;

    const std::map<Item, char> item_to_symbol = {
        {EMPTY, ' '},
        {RAMP_GOING_LEFT, '<'},
        {RAMP_GOING_RIGHT, '>'},
        {BIT_POINTING_LEFT, '('},
        {BIT_POINTING_RIGHT, ')'},
        {GEAR_BIT_POINTING_LEFT, '{'},
        {GEAR_BIT_POINTING_RIGHT, '}'},
        {GEAR, '*'},
        {CROSS_OVER, 'x'},
        {INTER_CEPTER, '_'}
    };

    const std::map<char, Item> symbol_to_item = {
        {' ', EMPTY},
        {'.', EMPTY},
        {'<', RAMP_GOING_LEFT},
        {'>', RAMP_GOING_RIGHT},
        {'(', BIT_POINTING_LEFT},
        {')', BIT_POINTING_RIGHT},
        {'{', GEAR_BIT_POINTING_LEFT},
        {'}', GEAR_BIT_POINTING_RIGHT},
        {'*', GEAR},
        {'x', CROSS_OVER},
        {'_', INTER_CEPTER}
    };

    void flip_gears_dfs(int x, int y, std::set<std::pair<int, int>> visited);
    void flip_gears(int x, int y);
    std::vector<std::string> remove_comments(std::vector<std::string> board_str);
    
public:
    int width, height;

    Board(int _width, int _height);
    Board(std::vector<std::string> board_str);
    void set_item(int x, int y, Item item);
    void set_items_from_strings(std::vector<std::string> board_str);
    
    bool add_ball(int x, int y, Color color);
    bool is_runnning();
    void step();
    void print() const;
    std::string get_results() const;
};
