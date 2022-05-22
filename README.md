# test-task

Project is based on CMake, so follow next steps to build it.
1. Clone the repository:
``` 
git clone https://github.com/siryione/test-task
```
2. Create and navigate to the build directory 
```
mkdir test-task/build && cd test-task/build 
```
3. Configure the project
```
cmake ..
```
4. Compile the project
```
cmake --build .
```
5. Run parent executable
```
cd bin/
./parent
```

## Cmd options
* `--help` -- produce help message;
* `--period` -- set counter increase period.

`./parent` _will run with default=1000ms period value_
