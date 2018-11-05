set( sources main.cc NumberCalculator.cc NumberCalculatorState.cc NumberCalculatorStateActive.cc NumberCalculatorStateInactive.cc )
add_executable (main.bin ${sources})
target_compile_options(main.bin PUBLIC -std=c++11 -Wall -Wfloat-conversion)
target_include_directories (main.bin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../interface)

