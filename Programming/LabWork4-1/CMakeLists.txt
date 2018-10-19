cmake_minimum_required(VERSION 3.9)
project(LabWork4_1)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)

pkg_check_modules(libxml REQUIRED /usr/local/Cellar/libxml++/2.40.1/lib/pkgconfig/libxml++-2.6.pc)
include_directories(${libxml_INCLUDE_DIRS})

add_executable(LabWork4_1 main.cpp myparser.h myparser.cpp)
target_link_libraries(LabWork4_1 -L/usr/local/Cellar/libxml++/2.40.1/lib -L/usr/local/Cellar/glibmm/2.56.0/lib -L/usr/local/Cellar/glib/2.56.1/lib -L/usr/local/opt/gettext/lib -L/usr/local/Cellar/libsigc++/2.10.0/lib -lxml++-2.6 -lxml2 -lglibmm-2.4 -lgobject-2.0 -lglib-2.0 -lintl -Wl,-framework -Wl,CoreFoundation -lsigc-2.0)