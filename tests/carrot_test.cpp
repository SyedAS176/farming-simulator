#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE( "it returns # as its symbol when it is tilled soil" ) {
    Carrot carrot;
    REQUIRE( carrot.symbol() == "#" );
}

TEST_CASE( "it returns a c as its when it is a sproutling" ) {
    Carrot carrot;
    carrot.end_day();
    REQUIRE( carrot.symbol() == "c" );
}

TEST_CASE( "it returns a C when the carrot is mature" ) {
    Carrot carrot;
    carrot.end_day();
    carrot.end_day();
    REQUIRE( carrot.symbol() == "C" );
}

TEST_CASE( "it is not mature on day zero" ) {
    Carrot carrot;
    REQUIRE( carrot.is_mature() == false );
}

TEST_CASE( "it is mature after two days" ) {
    Carrot carrot;
    carrot.end_day();
    carrot.end_day();
    REQUIRE( carrot.is_mature() == true );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
    Carrot carrot;
    carrot.water();
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 3 );
}

TEST_CASE( "ages the carrot properly after many waterings on many days" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 4 );
}