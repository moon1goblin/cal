#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main() {
    try {
        // Create a MySQL driver instance
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;

        // Connect to the database
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "paul", "1337");

        // Select a database
        con->setSchema("test_db");  // Replace with your DB name

        // Execute a query
        sql::Statement *stmt = con->createStatement();
        stmt->execute("INSERT INTO main VALUES (2, 2, 'bday');");

        // Clean up
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cerr << "MySQL Error: " << e.what() << endl;
        cerr << "Error code: " << e.getErrorCode() << endl;
    }

    return 0;
}
