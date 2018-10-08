# hackev_on_off_linetrace
In this repository, we are developing an educational program for LEGO Mindstorm using EV3RT.
The running body is assumed to be HackEV.

## Usage
In the workspace, type the following command.

```
docker run --rm -it -v $PWD:/home/hrp2/sdk/workspace/product korosuke613/etrobo-docker
```

An executable file named "app" is created.

```
ls
LICENSE      Makefile.inc README.md    app          app.cfg      app.cpp      app.h      apps
```

## Class Diagram
![クラス図](./class_diagram.png "クラス図")