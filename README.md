# CPP-AntsColony

## What is it
It's about simulating the life of an ant colony.

Have a look at the [wiki](https://github.com/AppliNH/CPP-AntsColony/wiki) :)


## How do I run it


### Docker

- `docker pull docker.pkg.github.com/applinh/cpp-antscolony/antscolony:latest`
- `docker run -it docker.pkg.github.com/applinh/cpp-antscolony/antscolony:latest`

### CMake
Once you cloned the repo, `cd` inside it and : 

- `cmake .`
- `cmake --build . --target CPP-AntsColony -- -j 8`

There you can execute the `./CPP-AntsColony` binary.

And you can also pass some arguments :

| Argument     | Description       | Default |
|---------------|-------------------|-------------------|
|`--width`|Grid's width |30|
|`--height`|Grid's height|15|
|`-s`,`--speed`|Refresh rate (μm)|1,000,000 (=1s)|
|`-o`,`--obstacles`|Quantity of obstacles|30|
|`-f`,`--foods`|Quantity of food|50|
|`-q`,`--quiet`|Run without any logs|false|
|`-h`,`--help`|Show help| |