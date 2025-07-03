include("${_build_cmake_local}")

add_library(PiSubmarine.Chipset.Api INTERFACE)
target_include_directories(PiSubmarine.Chipset.Api INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../public")

PiSubmarineAddDependency("https://github.com/PiSubmarine/RegUtils" "")
target_link_libraries(PiSubmarine.Chipset.Api INTERFACE PiSubmarine.RegUtils)