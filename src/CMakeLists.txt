include("${_build_cmake_local}")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(PiSubmarine.Chipset.Api 
	"PiSubmarine/Chipset/Api/PacketOut.cpp" 
	"PiSubmarine/Chipset/Api/PacketShutdown.cpp" 
	"PiSubmarine/Chipset/Api/PacketSetTime.cpp")
target_include_directories(PiSubmarine.Chipset.Api PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../public")

PiSubmarineAddDependency("https://github.com/PiSubmarine/RegUtils" "")
target_link_libraries(PiSubmarine.Chipset.Api PUBLIC PiSubmarine.RegUtils)