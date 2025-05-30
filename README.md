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
#include <stdio.h>
#include <stdlib.h>
```

Now let's use it

```c
static const char *example =
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin nec metus "
    "non orci convallis tincidunt. Vivamus consectetur purus et velit "
    "vestibulum, ac eleifend magna fringilla. Sed quis velit quis orci "
    "vulputate dapibus. Suspendisse potenti. Curabitur volutpat quam ut ipsum "
    "malesuada, ac elementum lorem scelerisque. Phasellus vehicula bibendum "
    "tortor, sed sagittis est lobortis in. Integer euismod, mauris quis congue "
    "tincidunt, velit orci efficitur sem, a sagittis erat turpis vel turpis. "
    "Nam lacinia, libero at condimentum fermentum, urna mi fringilla nisl, id "
    "pretium ipsum dui a eros. Donec malesuada elit et libero varius, a "
    "scelerisque velit sodales. Aliquam erat volutpat. Duis consectetur libero "
    "sit amet vestibulum cursus. Mauris nec bibendum magna, eget congue odio. "
    "Suspendisse nec ligula nulla. Integer tincidunt risus at fermentum "
    "luctus. Pellentesque sit amet sollicitudin nulla. Phasellus gravida leo a "
    "nisl tincidunt mattis. Fusce non urna vitae libero mollis gravida. Sed "
    "varius nulla in enim dignissim, vitae maximus orci consectetur. "
    "Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere "
    "cubilia curae; Proin fringilla mi sit amet eros pharetra, at elementum "
    "odio fermentum. Etiam suscipit facilisis elit in tincidunt. Suspendisse "
    "sed ligula magna. Aliquam erat volutpat. Ut non massa ac nunc gravida "
    "bibendum ut ut lorem. Nulla facilisi. Quisque id erat id sem commodo "
    "volutpat a id lectus.";

int main() {
  const char *encode = base64Encode(example, strlen(example));
  const char *decode = base64Decode(encode, strlen(encode));

  printf("encode: %s\n", encode);
  printf("decode: %s\n", decode);

  free((char *)encode);
  free((char *)decode);

  return 0;
}
```

Full example

```c
#include "base64.h"
#include <stdio.h>
#include <stdlib.h>

static const char *example =
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin nec metus "
    "non orci convallis tincidunt. Vivamus consectetur purus et velit "
    "vestibulum, ac eleifend magna fringilla. Sed quis velit quis orci "
    "vulputate dapibus. Suspendisse potenti. Curabitur volutpat quam ut ipsum "
    "malesuada, ac elementum lorem scelerisque. Phasellus vehicula bibendum "
    "tortor, sed sagittis est lobortis in. Integer euismod, mauris quis congue "
    "tincidunt, velit orci efficitur sem, a sagittis erat turpis vel turpis. "
    "Nam lacinia, libero at condimentum fermentum, urna mi fringilla nisl, id "
    "pretium ipsum dui a eros. Donec malesuada elit et libero varius, a "
    "scelerisque velit sodales. Aliquam erat volutpat. Duis consectetur libero "
    "sit amet vestibulum cursus. Mauris nec bibendum magna, eget congue odio. "
    "Suspendisse nec ligula nulla. Integer tincidunt risus at fermentum "
    "luctus. Pellentesque sit amet sollicitudin nulla. Phasellus gravida leo a "
    "nisl tincidunt mattis. Fusce non urna vitae libero mollis gravida. Sed "
    "varius nulla in enim dignissim, vitae maximus orci consectetur. "
    "Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere "
    "cubilia curae; Proin fringilla mi sit amet eros pharetra, at elementum "
    "odio fermentum. Etiam suscipit facilisis elit in tincidunt. Suspendisse "
    "sed ligula magna. Aliquam erat volutpat. Ut non massa ac nunc gravida "
    "bibendum ut ut lorem. Nulla facilisi. Quisque id erat id sem commodo "
    "volutpat a id lectus.";

int main() {
  const char *encode = base64Encode(example, strlen(example));
  const char *decode = base64Decode(encode, strlen(encode));

  printf("encode: %s\n", encode);
  printf("decode: %s\n", decode);

  free((char *)encode);
  free((char *)decode);

  return 0;
}
```

If you see an error, don't hesitate to open an [issue](https://github.com/ZbrDeev/base64.c/issues)
