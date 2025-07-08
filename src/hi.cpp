#include <mysqlx/devapi/result.h>
#include <mysqlx/devapi/row.h>
#include <mysqlx/xdevapi.h>  // Header remains the same
#include <iostream>
#include <ostream>
#include <string>

// Debugging functions
void show_tables(mysqlx::Session& sess) {
    std::cout << "Tables in database '" << MYSQL_DATABASE << "':" << std::endl;
    // No need in USE database; because we specifically connect to database
    mysqlx::SqlResult result = sess.sql("SHOW TABLES;").execute();
    // Fetch and display results
    for (mysqlx::Row row : result.fetchAll()) {
        // Each row contains one column (Database name)
        std::cout << row[0] << std::endl;
    }
}

void show_column_names(mysqlx::Session& sess, std::string tablename) {
    std::cout << "Column names in table '" << tablename << "' from database '" << MYSQL_DATABASE << "':" << std::endl;
    mysqlx::SqlResult res = sess.sql("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = ?").bind(tablename).execute();
    for (mysqlx::Row row : res.fetchAll()) {
        std::cout << row[0] << std::endl;
    }
}

int main() {
    try {
        // Connect using X Protocol (default port: 33060)
        mysqlx::Session sess(
            mysqlx::SessionOption::HOST, "127.0.0.1",
            mysqlx::SessionOption::PORT, MYSQL_HOST_PORT,
            mysqlx::SessionOption::USER, MYSQL_USER,
            mysqlx::SessionOption::PWD, MYSQL_PASSWORD,
            mysqlx::SessionOption::DB, MYSQL_DATABASE
        );

        std::cout << "Connection to database '" << MYSQL_DATABASE << "' successfull." << std::endl;

        // sess.sql("CREATE TABLE main(eventid INT, userid INT, eventname CHAR(100), datetimebegin DATETIME, datetimeend DATETIME, isfullday BOOL, groupid INT);").execute();
        // sess.sql("DROP TABLE main;").execute();
        
        show_tables(sess);
        show_column_names(sess, "main");
        

    } catch (const mysqlx::Error &e) {
        std::cerr << "X DevAPI Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
