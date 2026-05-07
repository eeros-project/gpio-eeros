cmake_minimum_required(VERSION 3.14)

include(cmake/git.cmake)

version_from_git(GIT_VERSION)
message("git version: ${GIT_VERSION}")

project(gpio-eeros LANGUAGES CXX VERSION ${GIT_VERSION})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library("${PROJECT_NAME}_gpio" SHARED)
add_library("${PROJECT_NAME}::gpio" ALIAS "${PROJECT_NAME}_gpio")
set_target_properties("${PROJECT_NAME}_gpio" PROPERTIES VERSION ${GIT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR} OUTPUT_NAME gpioeeros EXPORT_NAME bbblueeeros)

find_package(EEROS 1.4 REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(libgpiodcxx REQUIRED IMPORTED_TARGET GLOBAL libgpiodcxx)

add_subdirectory(lib)
target_link_libraries("${PROJECT_NAME}_gpio" PUBLIC EEROS::eeros PRIVATE PkgConfig::libgpiodcxx)

target_include_directories("${PROJECT_NAME}_gpio" PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>)

target_compile_features("${PROJECT_NAME}_gpio" PRIVATE cxx_std_14)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(TARGETS "${PROJECT_NAME}_gpio"
  EXPORT gpioeeros
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT gpioeeros NAMESPACE ${PROJECT_NAME}:: DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})
