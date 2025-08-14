## How to run this project

Following these steps from the project root (the folder with `CMakeLists.txt`).

### 0) Checking if tools are available

```bash
c++ --version        # Clang or GCC
make --version       # GNU Make
cmake --version      # CMake ≥ 3.20
brew --version       # to install tools
```

**Install missing tools**

- Install:
    ```bash
    brew install cmake
    ```
- Verify:
    ```bash
    which cmake 
    cmake --version 
    ```
    
### 1) Configure (prepare the build)

```bash
cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
```
This creates a build/ folder and generates Makefiles there.

### 2) Build (compile + link)
```bash
cmake --build build --parallel
```

- Outputs:
    ```bash
    build/temp_app — the CLI program
    build/converter_tests — the test program
    ```
    
### 3) Run the app

```bash
./build/temp_app c2f 100    # 100.00 C = 212.00 F
./build/temp_app f2c 212    # 212.00 F = 100.00 C
```

### 4) Run tests

ctest --test-dir build --output-on-failure

### 5) (Optional) Release build (faster binary)

```bash
cmake -S . -B build-release -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build-release --parallel
./build-release/temp_app c2f 37 #37.00 C = 98.60 F
```

### 6) (Optional) Copying deliverables into `./install`

```bash
cmake --install build --prefix ./install
```

- Check what got installed:
    ```bash
    ls -R install
    ```

After install:
- There are these folders:
    `install/bin` # your executable(s) like temp_app
    `install/lib` # libraries (if any) like .a 
    `install/include` # public headers (from include/)
    
- Running the program (example):
    ```bash
    ./build/temp_app c2f 100
    # or
    ./build/temp_app f2c 212
    ```

### 7) Cleaning up

```bash
rm -rf build build-release install
```

## Note: 

If you want to RUN the compiler yourself (no CMake):

### Build the app
```bash
c++ -std=c++20 -Iinclude src/convert.cpp src/main.cpp -o temp_app
./temp_app c2f 100
```

### Build the test
```bash
c++ -std=c++20 -Iinclude test/run_tests.cpp src/convert.cpp -o converter_tests
./converter_tests
```

What this does is:
- Compile each .cpp to .o (object)
    ```bash
    clang++ -std=c++20 -Iinclude -c src/main.cpp -o main.o
    ```

- Link the .o files to final program
    ```bash
    clang++ main.o convert.o -o temp_app
    ```
    
CMake/Make automate these steps.
