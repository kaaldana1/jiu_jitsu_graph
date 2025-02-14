//DBConnect (Database Connection Layer)
//Responsible only for managing database connections and executing queries.
#include "DbConnect.h"


PGconn * ConnectDB::get_connection(){
    return conn;
}

void ConnectDB::load_env()
{
    FILE *file;

    if ((file = fopen("../../.env", "r")) == NULL)
    {
        printf("Error, unable to open file");
        exit(1);
    }

    char line[256];

    while(fgets(line, sizeof(line), file))
    {
        putenv(line);
    }
    fclose(file);
}

bool ConnectDB::establish_connection()
{
    load_env();

    char *dbname = getenv("PGDATABASE");
    char *user = getenv("PGUSER");
    char *password = getenv("PGPASSWORD");
    char *host = getenv("PGHOST");
    char *port = getenv("PGPORT");

    char conninfo[256];

    snprintf(conninfo, sizeof(conninfo), 
     "dbname=%s user=%s password=%s host=%s port=%s",
     dbname, user, password, host, port);

     printf(conninfo);

    conn = PQconnectdb(conninfo);
    if (PQstatus(conn) == CONNECTION_OK)
    {
        printf("Connection successful");
        PQfinish(conn);
        return true;
    }

    printf("Connection failed");
    PQfinish(conn);
    return false;

}

