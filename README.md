# base64.c
#### A simple way to use base64 faster

**base64.c** is a base64 library for C and C++.

## Badges
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/ZbrDeev/base64.c/blob/main/LICENSE)

# Table of contents

1. [Requirement](#requirement)
2. [Installation](#installation)
3. [Setup](#setup)
4. [Example](#example)


# Requirement

For **base64.c** to work perfectly, you just need to install a C compiler like gcc or clang and cmake.

# Installation

Clone the repository
```sh
git clone https://github.com/ZbrDeev/base64.c
```

Go to the folder
```sh
cd base64.c
```

Create build folder
```sh
mkdir build
```

Go to the build folder
```sh
cd build
```

Configure cmake
```sh
cmake ..
```

Build the project
```sh
cmake --build .
```

Install the project
```sh
sudo cmake --install .
```

# Example

Let's start by including the library
```c
#include <base64.h>
```

Now let's use it 
```c
int main(){
    const char *encode = base64Encode("hello");
    printf("Encode result: %s", encode);

    const char *decode = base64Decode("TWE=");
    printf("Decode result: %s", decode);
}
```

Full example
```c
#include <stdio.h>
#include <base64.h>

int main(){
    const char *encode = base64Encode("hello");
    printf("Encode result: %s", encode);

    const char *decode = base64Decode("TWE=");
    printf("Decode result: %s", decode);
}
```

If you see an error, don't hesitate to open an [issue](https://github.com/ZbrDeev/base64.c/issues)

