#include <iostream>
#include <pqxx/pqxx>

void printQueryResult(pqxx::result R){
    
    for (auto row = R.begin(); row != R.end(); ++row) {
            for (auto field = row->begin(); field != row->end(); ++field) {
                std::cout << "Attribute: " << field->name() << ", Value: " << field->c_str() << std::endl;
            }
    }

}

int main() {
    try {
        // Establish a connection to the database
        // Parameters: "dbname=yourdbname user=yourusername password=yourpassword hostaddr=yourhost port=yourport"
        pqxx::connection C("dbname=Lab6&7 user=postgres password=password hostaddr=127.0.0.1 port=5432");
        if (C.is_open()) {
            std::cout << "Opened database successfully: " << C.dbname() << std::endl;
        } else {
            std::cout << "Can't open database" << std::endl;
            return 1;
        }
        
        // ------------------------------------------- Queries from lab 6--------------------------------------------
        // a
        //Listing the first and last names of all directors born in Canada - pass country as parameter
        C.prepare("query_a", "SELECT directors.\"firstname\", directors.\"surname\" FROM directors JOIN locations ON directors.\"birth_location\" = locations.\"location_Id\" WHERE locations.\"Country\" = $1 ;");
        // b
        //Listing all movie titles directed by director 'John Doe' - pass fname and lname as params
        C.prepare("query_b", "SELECT title FROM directors JOIN director_work ON directors.\"id\" = director_work.\"id_directors\" JOIN movies ON director_work.\"movie_id_movies\" = movies.\"movie_id\" WHERE directors.\"firstname\" = $1 AND directors.\"surname\" = $2 ;");
        //d.
        //Listing all directors with surname beginning with A and D - pass A% and D% as string params
        C.prepare("query_d", "SELECT firstname, surname FROM directors WHERE surname LIKE $1 OR surname LIKE $2 ;");
        
        // Create a transactional object
        pqxx::work W(C);


        // ----------------------DEFINING VARIABLES TO INSERT INTO DATABASE----------------------------------------

        std::string country = "Canada";
        std::string D_fname = "John";
        std::string D_lname = "Doe";
        std::string l1 = "A%";
        std::string l2 = "D%";


        // --------------------------------- EXECUTING PREPARED STATEMENTS USING VARIABLES ---------------------------------
       
        pqxx::result R6a = W.prepared("query_a")(country).exec();
        std::cout << "\nPrinting results of query 6 a:" << std::endl;
        printQueryResult(R6a);
        
        pqxx::result R6b = W.prepared("query_b")(D_fname)(D_lname).exec();
        std::cout << "\nPrinting results of query 6 b:" << std::endl;
        printQueryResult(R6b);
        
        pqxx::result R6d = W.prepared("query_d")(l1)(l2).exec();
        std::cout << "\nPrinting results of query 6 d:" << std::endl;
        printQueryResult(R6d);


        // --------------------------------- LAB 6 QUERY f. WITHOUT PARAMETERS AS VARIABLES ---------------------------------

        pqxx::result R6f = W.exec("SELECT a1.firstname, a2.firstname FROM actors AS a1 JOIN actors AS a2 ON a1.id != a2.id WHERE a1.eye_colour = 'Blue' AND a2.eye_colour = 'Blue' AND a1.firstname <= a2.firstname;");
        std::cout << "\nPrinting results of query 6 f:" << std::endl;
        printQueryResult(R6f);


        // Commit the transaction
        W.commit();
        std::cout << "\nAll queries in transaction executed successfully!" << std::endl;
        
        // Close the database connection
        C.disconnect();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}