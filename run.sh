# NOTE: this first line is a dumb hack mean to produce
# compile flags for my lsp to ignore things handled by CMake
cmake -S . -G "Unix Makefiles" -B build
# compile the project
cmake --build build 
# exec final binary 
build/l-systems
