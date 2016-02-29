
add_executable(testClient ./client_test.cc ./test.pb.cc)
target_link_libraries(testClient ${muduo_net})
target_link_libraries(testClient ${muduo_base})
target_link_libraries(testClient maxiaoda pthread protobuf)

add_executable(testServer ./server_test.cc ./test.pb.cc)
target_link_libraries(testServer ${muduo_net})
target_link_libraries(testServer ${muduo_base})
target_link_libraries(testServer maxiaoda pthread protobuf)
