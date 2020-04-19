project(openmp_tutorial C)

add_library(mpcs_hpc src/mpcs_hpc/tick.c src/mpcs_hpc/mat_types.c)
include_directories(include)

add_executable(dgemm_serial src/dgemm.c)
target_link_libraries(dgemm_serial PRIVATE mpcs_hpc)

find_package(OpenMP)

if(OpenMP_FOUND)
  add_executable(dgemm_omp src/dgemm.c)
  target_compile_options(dgemm_omp PRIVATE ${OpenMP_C_FLAGS})
  target_link_libraries(dgemm_omp PRIVATE mpcs_hpc ${OpenMP_C_FLAGS})
endif()

