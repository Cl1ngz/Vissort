# Vissort

Simple sorting algorithm visualizer made with C. Made for collage project.

Works great on linux with kitty terminal, shloud work on windows too i think.

## Preview:

![My Image](images/p1.png)
![My Image](images/p2.png)

### How to clone:

```bash
$ git clone https://github.com/Cl1ngz/Vissort.git
```

### How to build:

```bash
$ cd Vissort
$ make
```

### To run use the following command:

```bash
$ ./build/visualizer
```

## Structure of the project:

```
├──  assets
├──  build
├──  include
│   ├──  algorithms
│   │   ├──  bubble_sort.h
│   │   ├──  counting_sort.h
│   │   ├──  insertion_sort.h
│   │   ├──  quick_sort.h
│   │   └──  selection_sort.h
│   └──  utils
│       ├──  array_utils.h
│       ├──  file_utils.h
│       └──  linked_list.h
├──  LICENSE
├──  Makefile
├──  numbers.txt
├── 󰂺 README.md
└──  src
    ├──  algorithms
    │   ├──  bubble_sort.c
    │   ├──  counting_sort.c
    │   ├──  insertion_sort.c
    │   ├──  quick_sort.c
    │   └──  selection_sort.c
    ├──  main.c
    └──  utils
        ├──  array_utils.c
        ├──  file_utils.c
        └──  linked_list.c
```

## LICENSE

GNU General Public License v3.0
