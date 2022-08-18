sort_false_points README
========================

## Problem

There is a set of points and a set of planes. 
The points located on one side of the planes are good and on the other side are bad. 
It is necessary to divide the points by planes.

## Example

points.txt, planes.txt </b>
309453 points, 2 planes, sorted in 2.47 sec

![example_1](https://user-images.githubusercontent.com/30512240/185460025-924423de-308a-4852-be44-aad1d4a834ce.png)
![example_2](https://user-images.githubusercontent.com/30512240/185460028-16e3d725-375d-42e5-9f22-d1caf075eece.png)


## Building

```
$ cmake -S . -B out/build/
$ cd out/build/
$ make
```

## Run

Program takes two files from the resources directory for points and planes coordinates.

```
coordinates data format: 
x1 y1 z1 
x2 y2 z2
...
```

The output of the program are two files with sorted points: 
*init_file_name*_good.txt and *init_file_name*_wrong.txt.

place "points.txt" and "planes.txt" files into resources folder and run

```
$ ./sort_false_points
```

## Visualizer

You can visualize the result by python script.

following packages must be installed:

* [numpy](https://numpy.org/)
* [plotly](https://plotly.com/python/graph-objects/)

```
$ python main.py
```

========================
