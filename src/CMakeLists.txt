include("${_build_cmake_local}")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(PiSubmarine.Chipset.Api
	"../public/PiSubmarine/Chipset/Api/Register.h"
	"../public/PiSubmarine/Chipset/Api/Command.h"
	"../public/PiSubmarine/Chipset/Api/Convert.h"
		PiSubmarine/Chipset/Api/Convert.cpp
)
PiSubmarineInitTarget(PiSubmarine.Chipset.Api)
target_include_directories(PiSubmarine.Chipset.Api PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../public")

PiSubmarineAddDependency("https://github.com/PiSubmarine/RegUtils" "")
target_link_libraries(PiSubmarine.Chipset.Api PUBLIC PiSubmarine.RegUtils)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Units" "")
target_link_libraries(PiSubmarine.Chipset.Api PUBLIC PiSubmarine.Units)