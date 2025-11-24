#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/spinach.hpp"

TEST_CASE( "spinach returns # as its symbol when it is tilled soil" ) {
    Spinach spinach;
    REQUIRE( spinach.symbol() == "#" );
}

TEST_CASE( "spinach returns # after one day (not yet sprouted)" ) {
    Spinach spinach;
    spinach.end_day();
    REQUIRE( spinach.symbol() == "#" );
}

TEST_CASE( "spinach returns s when it is a seedling (day 2)" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "s" );
}

TEST_CASE( "spinach returns s on days 3 and 4" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "s" );
    spinach.end_day();
    REQUIRE( spinach.symbol() == "s" );
}

TEST_CASE( "spinach returns S when fully mature (day 5)" ) {
    Spinach spinach;
    for(int i = 0; i < 5; i++) {
        spinach.end_day();
    }
    REQUIRE( spinach.symbol() == "S" );
}

TEST_CASE( "spinach is not mature on day zero" ) {
    Spinach spinach;
    REQUIRE( spinach.is_mature() == false );
}

TEST_CASE( "spinach is not mature after 4 days" ) {
    Spinach spinach;
    for(int i = 0; i < 4; i++) {
        spinach.end_day();
    }
    REQUIRE( spinach.is_mature() == false );
}

TEST_CASE( "spinach is mature after 5 days" ) {
    Spinach spinach;
    for(int i = 0; i < 5; i++) {
        spinach.end_day();
    }
    REQUIRE( spinach.is_mature() == true );
}

TEST_CASE( "spinach increases age by 2 when watered" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.get_age() == 2 );
}

TEST_CASE( "watering spinach more than once per day has no effect" ) {
    Spinach spinach;
    spinach.water();
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.get_age() == 2 );
}

TEST_CASE( "watering spinach should not affect future days" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.get_age() == 3 );
}

TEST_CASE( "spinach can be matured early with watering" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    spinach.water();
    spinach.end_day();
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.is_mature() == true );
    REQUIRE( spinach.get_age() == 6 );
}