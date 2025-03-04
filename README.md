# Vissort

Simple sorting algorithm visualizer made with C (Cli app).

Works great on most linux distribution with modern terminal such as kitty.

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
│   │   ├──  merge_sort.h
│   │   ├──  quick_sort.h
│   │   └──  selection_sort.h
│   └──  utils
│       └──  array_utils.h
├──  LICENSE
├──  Makefile
├── 󰂺 README.md
└──  src
    ├──  algorithms
    │   ├──  bubble_sort.c
    │   ├──  counting_sort.c
    │   ├──  insertion_sort.c
    │   ├──  merge_sort.c
    │   ├──  quick_sort.c
    │   └──  selection_sort.c
    ├──  main.c
    └──  utils
        └──  array_utils.c
```

## LICENSE

MIT License
