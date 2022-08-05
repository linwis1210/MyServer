if [ ! -d "build" ]; then
        mkdir -p build
fi

cd build
cmake ..
make
cd ../ && ./bin/MyWebServer