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
- `./CPP-AntsColony`
