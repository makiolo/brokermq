#include <czmq.h>

int main (void)
{
    zsock_t *push = zsock_new_push ("tcp://localhost:5555");
    // zsock_t *pull = zsock_new_pull ("ipc://example");

    zstr_send (push, "Hello, World");

    /*
    char *string = zstr_recv (pull);
    puts (string);
    zstr_free (&string);
    */

    // zsock_destroy (&pull);
    zsock_destroy (&push);
    return 0;
}
