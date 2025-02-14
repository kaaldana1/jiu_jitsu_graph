#include <iostream>
#include <stdlib.h>
#include <libpq-fe.h>

class ConnectDB {
    public:
        bool establish_connection();
        PGconn *get_connection();
        ~ConnectDB();
        ConnectDB();
    private:
        void load_env();
        PGconn* conn;
};

