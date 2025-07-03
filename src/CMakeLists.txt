include("${_build_cmake_local}")

add_library(PiSubmarine.Chipset.Api 
	"PiSubmarine/Chipset/Api/PacketOut.cpp" 
	"PiSubmarine/Chipset/Api/PacketShutdown.cpp" 
	"PiSubmarine/Chipset/Api/PacketSetTime.cpp")
target_include_directories(PiSubmarine.Chipset.Api PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../public")

target_compile_features(PiSubmarine.Chipset.Api PRIVATE cxx_std_23)

PiSubmarineAddDependency("https://github.com/PiSubmarine/RegUtils" "")
target_link_libraries(PiSubmarine.Chipset.Api PUBLIC PiSubmarine.RegUtils)