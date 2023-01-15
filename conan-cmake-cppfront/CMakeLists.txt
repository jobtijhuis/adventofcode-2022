cmake_minimum_required(VERSION 3.23)
project(cppfront LANGUAGES CXX)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/source/cppfront.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Add header to public package
target_include_directories(${PROJECT_NAME} INTERFACE include)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/cpp2util.h)

install(TARGETS ${PROJECT_NAME} 
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION include)

# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION lib
#   LIBRARY DESTINATION lib
#   RUNTIME DESTINATION bin
#   PUBLIC_HEADER DESTINATION include)
