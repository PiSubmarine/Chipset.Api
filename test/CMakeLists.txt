cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(PiSubmarine.Chipset.Api.Test LANGUAGES CXX)

set(PiSubmarine.Chipset.Api.Test.Sources 
	"PiSubmarine/Chipset/Api/PacketOutTest.cpp" "PiSubmarine/Chipset/Api/PacketShutdownTest.cpp")

enable_testing()

# spdlog
find_package(spdlog)
find_package(gtest)

add_executable(PiSubmarine.Chipset.Api.Test ${PiSubmarine.Chipset.Api.Test.Sources} "PiSubmarine/Chipset/Api/PacketSetTimeTest.cpp")
target_compile_features(PiSubmarine.Chipset.Api.Test PRIVATE cxx_std_23)
target_link_libraries(PiSubmarine.Chipset.Api.Test PRIVATE PiSubmarine.Chipset.Api)
target_link_libraries(PiSubmarine.Chipset.Api.Test PRIVATE spdlog::spdlog)
target_link_libraries(PiSubmarine.Chipset.Api.Test PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(PiSubmarine.Chipset.Api.Test)