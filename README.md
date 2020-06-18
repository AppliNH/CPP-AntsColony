# CPP-AntsColony

## What is it
It's about simulating the life of an ant colony.

Have a look at the [wiki](https://github.com/AppliNH/CPP-AntsColony/wiki) :)


## How do I run it

Once you cloned the repo, `cd` inside it and : 
### Docker
- `docker build -t antsdocker .`
- `docker run -it antsdocker`

### CMake
- `cmake .`
- `cmake --build . --target CPP-AntsColony -- -j 8`
- `./CPP-AntsColony`
