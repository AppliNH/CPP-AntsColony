#include "game/Game.h"

static void show_usage(const std::string &name) {
    std::cerr << "Usage: " << name << " <option(s)>\n"
              << "Options:\n"
              << "\t--width\t\t\tWidth of the grid (default: 30)\n"
              << "\t--height\t\tHeight of the grid (default: 15)\n"
              << "\t-s,--speed\t\tSet the refresh rate in ms (1s = 1000000ms / default: 1000000)\n"
              << "\t-o,--obstacles\t\tSet the obstacle count (default: 30)\n"
              << "\t-f,--foods\t\tSet the food count (default: 50)\n"
              << "\t-q,--quiet\t\tRun program without any logs (default: false)\n"
              << "\t-h,--help\t\tShow this help message\n"
              << std::endl;
}

int main(int argc, char *argv[]) {
    std::string name = argv[0];
    bool quiet = false;
    int foodCount = 50;
    int obstacleCount = 30;
    int width = 30;
    int height = 15;
    int speed = 1000000;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            show_usage(name);
            return 0;
        } else if ((arg == "-q") || (arg == "--quiet")) {
            quiet = true;
        } else if ((arg == "-o") || (arg == "--obstacles")) {
            obstacleCount = atoi(argv[i + 1]);
        } else if ((arg == "-f") || (arg == "--foods")) {
            foodCount = atoi(argv[i + 1]);
        } else if ((arg == "-s") || (arg == "--speed")) {
            speed = atoi(argv[i + 1]);
        } else if ((arg == "--width")) {
            width = atoi(argv[i + 1]);
        } else if ((arg == "--height")) {
            height = atoi(argv[i + 1]);
        }
    }
    Game myGame = Game(speed, quiet, 5, width, height, foodCount, obstacleCount);
    myGame.start();
    return 0;
}
