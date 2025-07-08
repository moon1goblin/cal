#include <mysqlx/xdevapi.h>  // Header remains the same
#include <iostream>

int main() {
    try {
        // Connect using X Protocol (default port: 33060)
        mysqlx::Session sess(
            mysqlx::SessionOption::HOST, "127.0.0.1",
            mysqlx::SessionOption::PORT, MYSQL_PORT,
            mysqlx::SessionOption::USER, MYSQL_USER,
            mysqlx::SessionOption::PWD, MYSQL_PASSWORD,
            mysqlx::SessionOption::DB, MYSQL_DATABASE
        );

        std::cout << "Connection to database " << "test_db" << " successfull" << std::endl;

    } catch (const mysqlx::Error &e) {
        std::cerr << "X DevAPI Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
