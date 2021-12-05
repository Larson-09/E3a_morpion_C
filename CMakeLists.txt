cmake_minimum_required(VERSION 3.20)
project(morpion_project_c C)

set(CMAKE_C_STANDARD 11)

include_directories(etape1
                    test_tictactoe)

# To build a CMake :
# 1) Right click on CMakeLIsts.txt and select "Load CMake Project"
# 2) GO in cmake-build-debug and use the command "make"
# 3) launch ./morpion_project_c

# Run the mock version
#add_executable(morpion_project_c
#        etape1/board.c
#        etape1/board.h
#        etape1/board_view.h
#        etape1/board_view_text.c
#        etape1/game.c
#        etape1/game.h
#        etape1/main.c
#        etape1/player_manager.h
#        etape1/player_manager_mock.c
#        etape1/tictactoe_errors.h
#        etape1/tictactoe_erros.c)#Comment to run unit test

# Run the scanf version
add_executable(morpion_project_c
        etape1/board.c
        etape1/board.h
        etape1/board_view.h
        etape1/board_view_text.c
        etape1/game.c
        etape1/game.h
        etape1/main.c
        etape1/player_manager.h
        etape1/player_manager_scanf.c
        etape1/tictactoe_errors.h
        etape1/tictactoe_erros.c)#Comment to run unit test


#Uncomment to run unit test

#add_executable(morpion_project_c
#               etape1/board.c
#               test_tictactoe/main.c
#               test_tictactoe/test_CheckEndOfGame.c
#               test_tictactoe/test_CheckEndOfGame.h)
