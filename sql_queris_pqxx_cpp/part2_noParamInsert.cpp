#include <iostream>
#include <pqxx/pqxx>

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

        // Create a transactional object
        pqxx::work W(C);
        
        // Execute SQL query
        W.exec("INSERT INTO locations (\"City\", \"State\", \"Country\", \"location_Id\") VALUES ('Fictionville', 'Imaginaria', 'Utopia', 6);");
        W.exec("INSERT INTO universities (\"number_of_students\", \"description\", \"university_name\", \"public\", \"color\", \"location\") VALUES (5000, 'A prestigious university known for its advanced research facilities.', 'Fictionville University', true, 'Blue and White', 4);");
        W.exec("INSERT INTO university_departments (\"number_of_students\", \"description\", \"department_name\", \"university_id\") VALUES (1000, 'Department focusing on film studies and cinematography.', 'Film and Media Studies', 6);");
        W.exec("INSERT INTO movies (\"title\", \"release_date\", \"rating\", \"budget\", \"gross\", \"movie_id\", \"duration\") VALUES ('The Imaginary Quest', '2023-06-01', 8, 10000000, 15000000, 6, '02:00:00');");
        W.exec("INSERT INTO directors (\"firstname\", \"surname\", \"birth_year\", \"birth_location\", \"university-department_id\") VALUES ('Jesse', 'Lee', 1975, 1, 4);");
        W.exec("INSERT INTO actors (\"firstname\", \"surname\", \"date_of_birth\", \"eye_colour\", \"birth_location\", \"university-department_id\") VALUES ('Jane', 'Smith', '1990-04-15', 'blue', 1, 6);");
        W.exec("INSERT INTO genres (\"genre\", \"description\", \"genre_id\") VALUES ('Adventure', 'A genre involving exciting undertakings and exploratory experiences.', 6);");
        W.exec("INSERT INTO movie_genres (\"movie_id\", \"genre_id\") VALUES (6, 6);");
        W.exec("INSERT INTO cinemas (\"cinema_id\", \"location\", \"cinema_name\") VALUES (6, 6, 'Fictionville Multiplex');");
        W.exec("INSERT INTO showtimes (\"showtime_id\", \"showtime\", \"movie_id\", \"ticket_price\", \"cinema_id\", \"hall_type\") VALUES (6, '2023-07-01 20:00:00', 6, 12.50, 6, 'IMAX');");
        W.exec("INSERT INTO awards (\"award_id\", \"award_name\", \"award_category\") VALUES (6, 'Global Film Awards', 'Best Picture');");
        W.exec("INSERT INTO movie_awards (\"movie_id\", \"award_id\") VALUES (6, 6);");
        W.exec("INSERT INTO actor_work (\"id_actors\", \"movie_id_movies\") VALUES (6, 3);");
        W.exec("INSERT INTO director_work (\"id_directors\", \"movie_id_movies\") VALUES (6, 6);");
        
        // Commit the transaction
        W.commit();
        std::cout << "All queries in transaction executed successfully!" << std::endl;
        
        // Close the database connection
        C.disconnect();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
