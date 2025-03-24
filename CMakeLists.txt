set(MODULE_NAME PolyStokes)

cmake_minimum_required(VERSION 3.15)
project(${MODULE_NAME} LANGUAGES CXX)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find MPI
find_package(MPI REQUIRED)

# Find PETSc via pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(PETSC REQUIRED IMPORTED_TARGET petsc)

# Find Pybind11
find_package(pybind11 REQUIRED)

# Include directories
include_directories(
    ${PETSC_INCLUDE_DIRS}
    ${MPI_CXX_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

# Source files
set(SOURCES
    src/Stokes.cpp
    src/run.cpp
    src/init.cpp
    src/arrays.cpp
    src/check_dist.cpp
    src/multi_arrays_initialize.cpp
    src/mob.cpp
    src/rhs.cpp
    src/vel.cpp
    src/traj.cpp
    src/write_configuration.cpp
    src/quat.cpp
    src/pair_interaction.cpp
    src/cleanup.cpp
    src/bindings.cpp
)

# Define the Python module
pybind11_add_module(${MODULE_NAME} ${SOURCES})

# Link PETSc and MPI
target_link_libraries(PolyStokes
    PRIVATE
    PkgConfig::PETSC
    MPI::MPI_CXX
)

# Apply PETSc compile flags
target_compile_options(${MODULE_NAME} PRIVATE ${PETSC_CFLAGS_OTHER})
target_compile_definitions(${MODULE_NAME} PRIVATE ${PETSC_DEFINES})

# Ensure proper installation of the compiled Python module (.so)
include(GNUInstallDirs)

install(TARGETS ${MODULE_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

