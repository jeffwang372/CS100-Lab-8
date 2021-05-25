CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(unit_test
    unit_test.cpp
    iterator.cpp
)
ADD_EXECUTABLE(main
	main.cpp
	iterator.cpp
)

TARGET_LINK_LIBRARIES(unit_test gtest)
TARGET_COMPILE_DEFINITIONS(unit_test PRIVATE gtest_disable_pthreads=ON)
