# project name
PROJECT(SimpleWebServer)
# requirement of cmake version
cmake_minimum_required(VERSION 3.5)

# set the directory of executable files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleWebServer_SOURCE_DIR}/bin)

# find required opencv
find_package(OpenCV REQUIRED)
# directory of opencv headers
include_directories(${OpenCV_INCLUDE_DIRS})

#onnxruntime
# set(ONNXRUNTIME_ROOT_PATH /home/linwis/Project/onnxruntime-linux-x64-1.11.1/)
# set(ONNXRUNTIME_INCLUDE_DIRS ${ONNXRUNTIME_ROOT_PATH}include/)
# set(ONNXRUNTIME_LIB ${ONNXRUNTIME_ROOT_PATH}lib/libonnxruntime.so)

include_directories(${ONNXRUNTIME_INCLUDE_DIRS})
# name of executable file and path of source file
add_executable(SimpleWebServer 
    code/buffer/buffer.cpp
    code/http/httpconnect.cpp
    code/http/httprequest.cpp
    code/http/httpresponse.cpp
    code/onnx/infer.cpp
    code/log/log.cpp
    code/server/epoller.cpp
    code/server/webserver.cpp
    code/sqlconnpool/sql_conn_pool.cpp
    code/timer/heaptimer.cpp
    code/main.cpp
)
# directory of opencv library
link_directories(${OpenCV_LIBRARY_DIRS})

# opencv libraries
target_link_libraries(SimpleWebServer jsoncpp)
target_link_libraries(SimpleWebServer mysqlclient)
target_link_libraries(SimpleWebServer pthread)

target_link_libraries(SimpleWebServer ${OpenCV_LIBS})
# target_link_libraries(SimpleWebServer ${ONNXRUNTIME_LIB})

