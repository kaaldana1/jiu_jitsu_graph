#include <iostream>
#include <stdlib.h>
#include <libpq-fe.h>

void load_env()
{
    FILE *file = fopen("env", "r");
    if (!file)
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

int main()
{
    char *dbname = getenv("PGDATABASE");
    char *user = getenv("PGUSER");
    char *password = getenv("PGPASSWORD");
    char *host = getenv("PGHOST");
    char *port = getenv("PGPORT");

    char conninfo[256];

    snprintf(conninfo, sizeof(conninfo), 
     "dbname=%s user=%s password=%s host=%s port=%s",
     dbname, user, password, host, port);

    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) == CONNECTION_OK)
    {
        printf("Connection successful");
        PQfinish(conn);
        return 0;
    }
    printf("Connection failed");
    PQfinish(conn);
    return 1;

    
}