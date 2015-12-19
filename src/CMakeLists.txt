aux_source_directory(. DIR_SRCS)

add_library(maxiaoda ${DIR_SRCS})

add_executable(client ./sudoku/client.cc ./sudoku/sudoku.pb.cc)
target_link_libraries(client muduo_base muduo_net protobuf maxiaoda pthread)

add_executable(server ./sudoku/server.cc ./sudoku/sudoku.pb.cc)
target_link_libraries(server muduo_base muduo_net protobuf maxiaoda pthread)
