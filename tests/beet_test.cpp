#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/beet.hpp"

TEST_CASE( "beet returns # as its symbol when it is tilled soil" ) {
    Beet beet;
    REQUIRE( beet.symbol() == "#" );
}

TEST_CASE( "beet returns # after one day (not yet sprouted)" ) {
    Beet beet;
    beet.end_day();
    REQUIRE( beet.symbol() == "#" );
}

TEST_CASE( "beet returns b when it is a seedling (day 2)" ) {
    Beet beet;
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.symbol() == "b" );
}

TEST_CASE( "beet returns b through day 6" ) {
    Beet beet;
    for(int i = 0; i < 6; i++) {
        beet.end_day();
    }
    REQUIRE( beet.symbol() == "b" );
}

TEST_CASE( "beet returns B when fully mature (day 7)" ) {
    Beet beet;
    for(int i = 0; i < 7; i++) {
        beet.end_day();
    }
    REQUIRE( beet.symbol() == "B" );
}

TEST_CASE( "beet is not mature on day zero" ) {
    Beet beet;
    REQUIRE( beet.is_mature() == false );
}

TEST_CASE( "beet is not mature after 6 days" ) {
    Beet beet;
    for(int i = 0; i < 6; i++) {
        beet.end_day();
    }
    REQUIRE( beet.is_mature() == false );
}

TEST_CASE( "beet is mature after 7 days" ) {
    Beet beet;
    for(int i = 0; i < 7; i++) {
        beet.end_day();
    }
    REQUIRE( beet.is_mature() == true );
}

TEST_CASE( "beet increases age by 2 when watered" ) {
    Beet beet;
    beet.water();
    beet.end_day();
    REQUIRE( beet.get_age() == 2 );
}

TEST_CASE( "watering beet more than once per day has no effect" ) {
    Beet beet;
    beet.water();
    beet.water();
    beet.end_day();
    REQUIRE( beet.get_age() == 2 );
}

TEST_CASE( "watering beet should not affect future days" ) {
    Beet beet;
    beet.water();
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.get_age() == 3 );
}

TEST_CASE( "beet can be matured early with watering" ) {
    Beet beet;
    for(int i = 0; i < 4; i++) {
        beet.water();
        beet.end_day();
    }
    REQUIRE( beet.is_mature() == true );
    REQUIRE( beet.get_age() == 8 );
}