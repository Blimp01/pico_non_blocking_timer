# Non Blocking timer for the Raspberry Pi Pico C/C++ 

- Configures the Systick clock to count 1ms
- Further user functions provided to create user timers  

## Including in project 
- Copy non_blocking_timer.c and non_blocking_timer.h into your project folder.
- include a Path to non_blocking_timer.c in add_executable() in  CMakeLists.c 


## Making Example.c
```sh
cd pico_non_blocking_timer/example 
mkdir build
cd build
export PICO_SDK_PATH=../../../pico-sdk (insert your SDK path)
cmake ..
make
```
- Copy the example.uf2 to your Raspberry pi pico 

## License

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

