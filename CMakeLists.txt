# --------------------------------------------------------------------------- #
#    Main CMake file for SMS++ MILPSolver                                     #
#                                                                             #
#    This file allows one to build the library using CMake.                   #
#    To do so, you can use the following commands:                            #
#                                                                             #
#        $ cmake -S <source-path> -B <build-path>                             #
#        $ cmake --build <build-path>                                         #
#                                                                             #
#    The following command also installs the library in the system:           #
#                                                                             #
#        $ cmake --build <build-path> --target install                        #
#                                                                             #
#    Note: this file tries to respect the principles of Modern CMake,         #
#          keep it in mind when editing it.                                   #
#                                                                             #
#                              Niccolo' Iardella                              #
#                                Donato Meoli                                 #
#                         Dipartimento di Informatica                         #
#                             Universita' di Pisa                             #
# --------------------------------------------------------------------------- #
cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.12)
project(MILPSolver
        VERSION 0.7.1
        DESCRIPTION "SMS++ MILPSolver module"
        HOMEPAGE_URL https://gitlab.com/smspp/milpsolver
        LANGUAGES C CXX)

# These variables make the code harder to read but easier to change.
set(modName ${PROJECT_NAME})
set(modNamespace "SMS++")

# Find out if it's being called by the umbrella.
get_directory_property(hasParent PARENT_DIRECTORY)

# This adds the cmake directory to the module search paths,
# allowing us to use our modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# ----- Settings ------------------------------------------------------------ #
# This creates an ENABLE_TESTING option (default: ON) and enables the testing
# using the ctest executable.
# See: https://cmake.org/cmake/help/latest/manual/ctest.1.html
include(CTest)

# Sets the default build type (if none was specified).
# See: https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html
include(BuildType)

# An option is an ON/OFF user-settable cache variable
option(MILPSolver_USE_CPLEX "Whether MILPSolver will use CPLEX or not." ON)
option(MILPSolver_USE_SCIP "Whether MILPSolver will use SCIP or not." ON)
option(MILPSolver_USE_GUROBI "Whether MILPSolver will use GUROBI or not." ON)
option(MILPSolver_USE_HiGHS "Whether MILPSolver will use HiGHS or not." ON)

# A lot of debug prints
#if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
#    add_compile_definitions(MILPSOLVER_DEBUG)
#endif ()

# ----- Policies ----------------------------------------------------------- #
# Introduced in 3.19 to handle arbitrary characters in test names
# See: https://cmake.org/cmake/help/latest/policy/CMP0110.html
if (POLICY CMP0110)
    cmake_policy(SET CMP0110 NEW)
endif ()

# ----- Requirements -------------------------------------------------------- #
# If it's not being called by the umbrella, we need to
# look for the system-installed libraries.
if (NOT hasParent)
    find_package(SMS++ REQUIRED)
endif ()

if (MILPSolver_USE_CPLEX)
    # Needed for CPXMILPSolver
    find_package(CPLEX 12.8.0)
    if (NOT CPLEX_FOUND)
        set(MILPSolver_USE_CPLEX OFF)
    endif ()
endif ()

if (MILPSolver_USE_SCIP)
    # Needed for SCIPMILPSolver
    find_package(SCIP 7.0.0)
    if (NOT SCIP_FOUND)
        set(MILPSolver_USE_SCIP OFF)
    endif ()
endif ()

if (MILPSolver_USE_GUROBI)
    # Needed for GUROBIMILPSolver
    find_package(GUROBI 10.0.0)
    if (NOT GUROBI_FOUND)
        set(MILPSolver_USE_GUROBI OFF)
    endif ()
endif ()

if (MILPSolver_USE_HiGHS)
    # Needed for HiGHSMILPSolver
    find_package(HiGHS 1.5.3)
    if (NOT HiGHS_FOUND)
        set(MILPSolver_USE_HiGHS OFF)
    endif ()
endif ()

# ----- Configuration header ------------------------------------------------ #
# This will generate a *Config.h header in the build directory.
configure_file(cmake/${modName}Config.h.in ${modName}Config.h)

# ----- Library ------------------------------------------------------------- #
# With the BUILD_SHARED_LIBS variable we can specify if the library will
# be STATIC or SHARED, so no reason to do it now.
add_library(${modName})
target_compile_features(${modName} PUBLIC cxx_std_17)

# When adding source files with target_sources(), PRIVATE means that the files
# should only be added to this library, whereas PUBLIC means they should be
# added to this library and to any target that links to it.
# INTERFACE can be used for sources that should not be added to this library
# but should be added to anything that links to it.
# Note: do not GLOB files here.
target_sources(${modName} PRIVATE src/MILPSolver.cpp)

# When using target_include_directories(), PUBLIC means that any targets
# that link to this target also need that include directory.
# Other options are PRIVATE (only affect the current target, not dependencies),
# and INTERFACE (only needed for dependencies).

# Different INSTALL_INTERFACE and BUILD_INTERFACE paths are used when
# generating the target import file (***Targets.cmake).
# This means that if a target finds this library in its build directory
# will look into the BUILD_INTERFACE path for its headers, if it finds it
# installed in the system will look into the INSTALL_INTERFACE path.
target_include_directories(
        ${modName} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/${modNamespace}>)

# When linking other targets to the library with target_link_libraries(),
# PRIVATE means that the libraries will be linked only to this library,
# PUBLIC means they will be linked also to the targets that depend on this
# library, INTERFACE means they will be linked only to the targets that depend
# on this library.
target_link_libraries(${modName} PUBLIC ${modNamespace}::SMS++)

if (MILPSolver_USE_CPLEX)
    message(STATUS "MILPSolver: CPLEX found, configuring CPXMILPSolver")
    target_include_directories(${modName} PUBLIC ${CPLEX_INCLUDE_DIRS}) 
    target_sources(${modName} PRIVATE src/CPXMILPSolver.cpp)
    target_link_libraries(${modName} PUBLIC CPLEX::Cplex)
endif ()

if (MILPSolver_USE_SCIP)
    message(STATUS "MILPSolver: SCIP found, configuring SCIPMILPSolver")
    target_include_directories(${modName} PRIVATE ${SCIP_INCLUDE_DIRS})
    target_sources(${modName} PRIVATE src/SCIPMILPSolver.cpp)
    target_link_libraries(${modName} PUBLIC SCIP::SCIP)
endif ()

if (MILPSolver_USE_GUROBI)
    message(STATUS "MILPSolver: GUROBI found, configuring GRBMILPSolver")
    target_include_directories(${modName} PUBLIC ${GUROBI_INCLUDE_DIRS}) 
    target_sources(${modName} PRIVATE src/GRBMILPSolver.cpp)
    target_link_libraries(${modName} PUBLIC GUROBI::Gurobi)
endif ()

if (MILPSolver_USE_HiGHS)
    message(STATUS "MILPSolver: HiGHS found, configuring HiGHSMILPSolver")
    target_include_directories(${modName} PUBLIC ${HiGHS_INCLUDE_DIRS}) 
    target_sources(${modName} PRIVATE src/HiGHSMILPSolver.cpp)
    target_link_libraries(${modName} PUBLIC HiGHS::HiGHS)
endif ()

# This alias is defined so that executables in this same project can use
# the library with this notation.
add_library(${modNamespace}::${modName} ALIAS ${modName})

# ----- Subdirectories ------------------------------------------------------ #
#add_subdirectory(tools)

if (BUILD_TESTING)
    add_subdirectory(test_dual)
    add_subdirectory(test_dynamic)
endif ()

# ----- Install instructions ------------------------------------------------ #
# The following commands are used when installing the library
# and its CMake configuration files on the system.
# They are not required for local builds (see below).

include(GNUInstallDirs)

# Install the library
install(TARGETS ${modName}
        EXPORT ${modName}Targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Install the headers
install(FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MILPSolver.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${modNamespace})

if (MILPSolver_USE_CPLEX)
    install(DIRECTORY include
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${modNamespace}
            FILES_MATCHING PATTERN "CPX*")
endif ()

if (MILPSolver_USE_SCIP)
    install(DIRECTORY include
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${modNamespace}
            FILES_MATCHING PATTERN "SCIP*")
endif ()

if (MILPSolver_USE_GUROBI)
    install(DIRECTORY include
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${modNamespace}
            FILES_MATCHING PATTERN "GRB*")
endif ()

if (MILPSolver_USE_HiGHS)
    install(DIRECTORY include
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${modNamespace}
            FILES_MATCHING PATTERN "HiGHS*")
endif ()

# Install the auto-generated configuration header (see above).
install(FILES ${PROJECT_BINARY_DIR}/${modName}Config.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${modNamespace})

# (Generate and) install the target import file, that allows other
# CMake projects to import the target.
install(EXPORT ${modName}Targets
        NAMESPACE ${modNamespace}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${modName})

# Generate the package version file, that allows other
# CMake projects to know the version.
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${modName}ConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion)

# Generate the package configuration file, that allows other
# CMake projects to find the library with find_package().
configure_package_config_file(
        ${CMAKE_CURRENT_LIST_DIR}/cmake/${modName}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${modName}Config.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${modName})

# Install the package version and configuration files.
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${modName}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${modName}ConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${modName})

# Shipping custom find modules should not be encouraged because third
# party developers should provide for them.
file(GLOB findMods ${CMAKE_CURRENT_LIST_DIR}/cmake/Find*)
install(FILES ${findMods}
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${modName})

# Install the README and LICENSE files.
install(FILES
        ${CMAKE_CURRENT_LIST_DIR}/README.md
        ${CMAKE_CURRENT_LIST_DIR}/LICENSE
        DESTINATION ${CMAKE_INSTALL_DATADIR}/${modName})

# ----- Add the build tree to RPATH------------------------------------------ #
# Add the binary directory to RPATH, so executables that use
# dynamic loading will look into it.
if (hasParent)
    set(SMSPP_BUILD_RPATH
        "${SMSPP_BUILD_RPATH};${CMAKE_CURRENT_BINARY_DIR}"
        PARENT_SCOPE)
endif ()

# ----- Packaging support --------------------------------------------------- #
# The following commands allow one to build a proper package using CPack.
# See: https://cmake.org/cmake/help/latest/manual/cpack.1.html

# Using this with the umbrella project is too messy.
if (NOT hasParent)
    set(CPACK_PACKAGE_VENDOR "SMS++ Team")
    set(CPACK_PACKAGE_CONTACT "Niccolo' Iardella")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_DESCRIPTION})
    set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_LIST_DIR}/LICENSE")
    set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_LIST_DIR}/README.md")
    set(CPACK_SOURCE_IGNORE_FILES
        \\\\.git/
        \\\\.gitignore$
        \\\\.gitattributes$)
    include(CPack)
endif ()

# --------------------------------------------------------------------------- #
# Remove from the search paths the cmake directory we added at the beginning.
list(REMOVE_AT CMAKE_MODULE_PATH -1)

# --------------------------------------------------------------------------- #
