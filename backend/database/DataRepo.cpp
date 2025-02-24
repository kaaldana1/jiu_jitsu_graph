//DataRepository 
    //A separate class responsible for fetching and processing data from PostgreSQL.
    //Converts raw database results into structured objects (e.g., graph nodes and edges).
//=================================================================
//GraphBuilder 
    //uses the processed data from DataRepository to construct the graph.
    //Contains logic to apply weights, determine relationships, and dynamically structure the graph.

#include "DbConnect.h"

int main()
{

    ConnectDB conn;
    conn.establish_connection();

    return 0;


}