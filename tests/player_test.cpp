#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
/*
 * IMPORTANT NOTE
 * THESE UNIT TESTS DO NOT TEST OUT OF BOUNDS MOVEMENT
 * THAT IS HANDLED BY THE FARM CLASS ITSELF
 * THESE UNIT TESTS SIMPLY TEST BASIC MOVEMENT
 */
TEST_CASE( "it starts the player in row zero, column zero" ) {
    Player player;
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player to the right" ) {
    Player player;
    player.move_right();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 1 );
}

TEST_CASE( "it moves the player to the left" ) {
    Player player;
    player.move_right(); // First move right to have some space
    player.move_left();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player up" ) {
    Player player;
    player.move_down(); // First move down to have some space
    player.move_up();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player down" ) {
    Player player;
    player.move_down();
    REQUIRE( player.row() == 1 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player in multiple directions" ) {
    Player player;
    player.move_right();
    player.move_down();
    player.move_left();
    player.move_up();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 0 );
}