cmake_minimum_required(VERSION 3.5)
project(basic_agent_ST)

set(CMAKE_CXX_STANDARD 11)
# If you are on mac x86
#set(CMAKE_OSX_ARCHITECTURES x86_64)

include(lib/basic.cmake)

include_directories(
        matlab/
        matlab/codegen/lib/primitives/
        lib
        log
)

link_directories(
        lib
)

# ------------------------------- basic agent ------------------------------------
add_executable(basic_agent
        matlab/codegen/lib/primitives/rt_nonfinite.c
        matlab/codegen/lib/primitives/primitives.c
        log/screen_print.c
        log/logvars.cc
        starting_point.cc
    )


target_link_libraries(basic_agent agent_lib ${lib_ws32})

target_compile_options(basic_agent
        PUBLIC -DNOT_INLINED -DSERVER
        )

set_target_properties(basic_agent PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${AGENT_FOLDER})
# ------------------------------------------------------------------------------------

# --------------------------------Test Pass Primitive---------------------------------
add_executable(test_primitive_pass
    matlab/codegen/lib/primitives/rt_nonfinite.c
    matlab/codegen/lib/primitives/primitives.c

    log/screen_print.c
    log/logvars.cc
    preliminary_works/test_pass/test_primitive_pass.cc
)

target_link_libraries(test_primitive_pass agent_lib ${lib_ws32})

target_compile_options(test_primitive_pass
    PUBLIC -DNOT_INLINED -DSERVER
)

set_target_properties(test_primitive_pass PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${AGENT_FOLDER})

# --------------------------------Test Stop Primitive---------------------------------
add_executable(test_primitive_stop
    matlab/codegen/lib/primitives/rt_nonfinite.c
    matlab/codegen/lib/primitives/primitives.c

    log/screen_print.c
    log/logvars.cc
    preliminary_works/test_pass/test_primitive_stop.cc
)

target_link_libraries(test_primitive_stop agent_lib ${lib_ws32})

target_compile_options(test_primitive_stop
    PUBLIC -DNOT_INLINED -DSERVER
)

set_target_properties(test_primitive_stop PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${AGENT_FOLDER})