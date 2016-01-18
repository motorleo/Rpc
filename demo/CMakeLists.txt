
add_executable(client ./client.cc ./demo.pb.cc)
target_link_libraries(client ${muduo_net})
target_link_libraries(client ${muduo_base})
target_link_libraries(client maxiaoda pthread protobuf)

add_executable(server ./server.cc ./demo.pb.cc)
target_link_libraries(server ${muduo_net})
target_link_libraries(server ${muduo_base})
target_link_libraries(server maxiaoda pthread protobuf)
