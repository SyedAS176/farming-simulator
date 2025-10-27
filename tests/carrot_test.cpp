#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE( "it returns a v as its when it is a seedling" ) {
    Carrot carrot;
    REQUIRE( carrot.symbol() == "v" );
    REQUIRE(!carrot.is_mature() == true); // It is true that the carrot is not mature

}

TEST_CASE( "Carrot matures after one day" ) {
    Carrot carrot;
    carrot.end_day(); // Age becomes 1
    REQUIRE(carrot.symbol() == "V");
    REQUIRE(carrot.is_mature() == true); // It is true that the carrot is mature now
}