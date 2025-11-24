#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lettuce.hpp"

TEST_CASE( "lettuce returns # as its symbol when it is tilled soil" ) {
    Lettuce lettuce;
    REQUIRE( lettuce.symbol() == "#" );
}

TEST_CASE( "lettuce returns # after one day (not yet sprouted)" ) {
    Lettuce lettuce;
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "#" );
}

TEST_CASE( "lettuce returns l when it is a seedling (day 2)" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "l" );
}

TEST_CASE( "lettuce returns l on day 3" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "l" );
}

TEST_CASE( "lettuce returns L when fully mature (day 4)" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "L" );
}

TEST_CASE( "lettuce is not mature on day zero" ) {
    Lettuce lettuce;
    REQUIRE( lettuce.is_mature() == false );
}

TEST_CASE( "lettuce is not mature after 3 days" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.is_mature() == false );
}

TEST_CASE( "lettuce is mature after 4 days" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.is_mature() == true );
}

TEST_CASE( "lettuce increases age by 2 when watered" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 2 );
}

TEST_CASE( "watering lettuce more than once per day has no effect" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 2 );
}

TEST_CASE( "watering lettuce should not affect future days" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 3 );
}

TEST_CASE( "lettuce can be matured early with watering" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.is_mature() == true );
    REQUIRE( lettuce.get_age() == 4 );
}