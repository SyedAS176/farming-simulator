#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/brussels_sprouts.hpp"

TEST_CASE( "brussels sprouts returns # as its symbol when it is tilled soil" ) {
    BrusselsSprouts sprouts;
    REQUIRE( sprouts.symbol() == "#" );
}

TEST_CASE( "brussels sprouts returns # for days 1-4 (not yet sprouted)" ) {
    BrusselsSprouts sprouts;
    for(int i = 0; i < 4; i++) {
        sprouts.end_day();
    }
    REQUIRE( sprouts.symbol() == "#" );
}

TEST_CASE( "brussels sprouts returns bs when it is a seedling (day 5)" ) {
    BrusselsSprouts sprouts;
    for(int i = 0; i < 5; i++) {
        sprouts.end_day();
    }
    REQUIRE( sprouts.symbol() == "bs" );
}

TEST_CASE( "brussels sprouts returns bs through day 14" ) {
    BrusselsSprouts sprouts;
    for(int i = 0; i < 14; i++) {
        sprouts.end_day();
    }
    REQUIRE( sprouts.symbol() == "bs" );
}

TEST_CASE( "brussels sprouts returns BS when fully mature (day 15)" ) {
    BrusselsSprouts sprouts;
    for(int i = 0; i < 15; i++) {
        sprouts.end_day();
    }
    REQUIRE( sprouts.symbol() == "BS" );
}

TEST_CASE( "brussels sprouts is not mature on day zero" ) {
    BrusselsSprouts sprouts;
    REQUIRE( sprouts.is_mature() == false );
}

TEST_CASE( "brussels sprouts is not mature after 14 days" ) {
    BrusselsSprouts sprouts;
    for(int i = 0; i < 14; i++) {
        sprouts.end_day();
    }
    REQUIRE( sprouts.is_mature() == false );
}

TEST_CASE( "brussels sprouts is mature after 15 days" ) {
    BrusselsSprouts sprouts;
    for(int i = 0; i < 15; i++) {
        sprouts.end_day();
    }
    REQUIRE( sprouts.is_mature() == true );
}

TEST_CASE( "brussels sprouts increases age by 2 when watered" ) {
    BrusselsSprouts sprouts;
    sprouts.water();
    sprouts.end_day();
    REQUIRE( sprouts.get_age() == 2 );
}

TEST_CASE( "watering brussels sprouts more than once per day has no effect" ) {
    BrusselsSprouts sprouts;
    sprouts.water();
    sprouts.water();
    sprouts.end_day();
    REQUIRE( sprouts.get_age() == 2 );
}

TEST_CASE( "watering brussels sprouts should not affect future days" ) {
    BrusselsSprouts sprouts;
    sprouts.water();
    sprouts.end_day();
    sprouts.end_day();
    REQUIRE( sprouts.get_age() == 3 );
}

TEST_CASE( "brussels sprouts can be matured early with watering" ) {
    BrusselsSprouts sprouts;
    for(int i = 0; i < 8; i++) {
        sprouts.water();
        sprouts.end_day();
    }
    REQUIRE( sprouts.is_mature() == true );
    REQUIRE( sprouts.get_age() == 16 );
}