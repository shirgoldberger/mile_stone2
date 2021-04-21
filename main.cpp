#include "Boot.h"
using namespace Boot;

int main(int argc, char* argv[]) {
    Main* m = new Main();
    if (argc < 2) {
        m->main(5600);
    } else {
        m->main(atoi(argv[1]));
    }
    return 0;
}
