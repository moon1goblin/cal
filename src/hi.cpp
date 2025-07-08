#include <mysqlx/xdevapi.h>  // Header remains the same
#include <iostream>

int main() {
    try {
        // Connect using X Protocol (default port: 33060)
        mysqlx::Session sess(
            mysqlx::SessionOption::HOST, "localhost",
            mysqlx::SessionOption::PORT, 33060,
            mysqlx::SessionOption::USER, "user",
            mysqlx::SessionOption::PWD, "password",
            mysqlx::SessionOption::DB, "database"
        );

        std::cout << "Connection to database " << "test_db" << " successfull" << std::endl;

    } catch (const mysqlx::Error &e) {
        std::cerr << "X DevAPI Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
