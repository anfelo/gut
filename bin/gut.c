#include "dbg.h"

int parse_args(int *argc, char **argv[])
{
    (*argc)--;
    (*argv)++;

    if(strcmp((*argv)[0], "init") == 0) {
        (*argc)--;
        (*argv)++;

        check(*argc > 1, "The 'init' command does not take additional arguments.");

        log_info("Initializing gut repo.");
    } else {
        sentinel("Command '%s' not supported.", (*argv)[0]);
    }

    return 0;
error:
    return -1;
}

int main(int argc, char *argv[]) {
    // TODO: Print usage message
    check(argc > 1, "USAGE: here goes the usage message");
    check(parse_args(&argc, &argv) == 0, "USAGE: here goes the usage message");
error:
    return 1;
}
