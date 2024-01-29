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

        // --------------------------------- CREATING PREPARED STATES THAT WILL ACCEPT PARAMETERS ------------------
        C.prepare("insert_location", "INSERT INTO locations (\"City\", \"State\", \"Country\", \"location_Id\") VALUES ($1, $2, $3, $4)");
        C.prepare("insert_university", "INSERT INTO universities (\"number_of_students\", \"description\", \"university_name\", \"public\", \"color\", \"location\") VALUES ($1, $2, $3, $4, $5, $6)");
        C.prepare("insert_university_department", "INSERT INTO university_departments (\"number_of_students\", \"description\", \"department_name\", \"university_id\") VALUES ($1, $2, $3, $4)");
        C.prepare("insert_movie", "INSERT INTO movies (\"title\", \"release_date\", \"rating\", \"budget\", \"gross\", \"movie_id\", \"duration\") VALUES ($1, $2, $3, $4, $5, $6, $7)");
        C.prepare("insert_director", "INSERT INTO directors (\"firstname\", \"surname\", \"birth_year\", \"birth_location\", \"university-department_id\") VALUES ($1, $2, $3, $4, $5)");
        C.prepare("insert_actor", "INSERT INTO actors (\"firstname\", \"surname\", \"date_of_birth\", \"eye_colour\", \"birth_location\", \"university-department_id\") VALUES ($1, $2, $3, $4, $5, $6)");
        C.prepare("insert_genre", "INSERT INTO genres (\"genre\", \"description\", \"genre_id\") VALUES ($1, $2, $3)");
        C.prepare("insert_movie_genre", "INSERT INTO movie_genres (\"movie_id\", \"genre_id\") VALUES ($1, $2)");
        C.prepare("insert_cinema", "INSERT INTO cinemas (\"cinema_id\", \"location\", \"cinema_name\") VALUES ($1, $2, $3)");
        C.prepare("insert_showtime", "INSERT INTO showtimes (\"showtime_id\", \"showtime\", \"movie_id\", \"ticket_price\", \"cinema_id\", \"hall_type\") VALUES ($1, $2, $3, $4, $5, $6)");
        C.prepare("insert_award", "INSERT INTO awards (\"award_id\", \"award_name\", \"award_category\") VALUES ($1, $2, $3)");
        C.prepare("insert_movie_award", "INSERT INTO movie_awards (\"movie_id\", \"award_id\") VALUES ($1, $2)");
        C.prepare("insert_actor_work", "INSERT INTO actor_work (\"id_actors\", \"movie_id_movies\") VALUES ($1, $2)");
        C.prepare("insert_director_work", "INSERT INTO director_work (\"id_directors\", \"movie_id_movies\") VALUES ($1, $2)");

        

        // Create a transactional object
        pqxx::work W(C);
        
        // ----------------------DEFINING VARIABLES TO INSERT INTO DATABASE----------------------------------------
        // Variables for "insert_location"
        std::string city = "Fictionville";
        std::string state = "Imaginaria";
        std::string country = "Utopia";
        int location_id = 6;

        // Variables for "insert_university"
        int number_of_students_uni = 5000;
        std::string description_uni = "A prestigious university known for its advanced research facilities.";
        std::string university_name = "Fictionville University";
        bool is_public = true;
        std::string color = "Blue and White";
        int location_uni = 4;

        // Variables for "insert_university_department"
        int number_of_students_dept = 1000;
        std::string description_dept = "Department focusing on film studies and cinematography.";
        std::string department_name = "Film and Media Studies";
        int university_id = 6;

        // Variables for "insert_movie"
        std::string title = "The Imaginary Quest";
        std::string release_date = "2023-06-01";
        int rating = 8;
        int budget = 10000000;
        int gross = 15000000;
        int movie_id = 6;
        std::string duration = "02:00:00";

        // Variables for "insert_director"
        std::string firstname_director = "Jesse";
        std::string surname_director = "Lee";
        int birth_year_director = 1975;
        int birth_location_director = 1;
        int university_department_id_director = 4;

        // Variables for "insert_actor"
        std::string firstname_actor = "Jane";
        std::string surname_actor = "Smith";
        std::string dob_actor = "1990-04-15";
        std::string eye_colour_actor = "blue";
        int birth_location_actor = 1;
        int university_department_id_actor = 6;

        // Variables for "insert_genre"
        std::string genre = "Adventure";
        std::string genre_description = "A genre involving exciting undertakings and exploratory experiences.";
        int genre_id = 6;

        // Variables for "insert_movie_genre"
        // movie_id and genre_id already defined

        // Variables for "insert_cinema"
        int cinema_id = 6;
        // location already defined
        std::string cinema_name = "Fictionville Multiplex";

        // Variables for "insert_showtime"
        int showtime_id = 6;
        std::string showtime = "2023-07-01 20:00:00";
        // movie_id already defined
        double ticket_price = 12.50;
        // cinema_id already defined
        std::string hall_type = "IMAX";

        // Variables for "insert_award"
        int award_id = 6;
        std::string award_name = "Global Film Awards";
        std::string award_category = "Best Picture";

        // Variables for "insert_movie_award"
        // movie_id and award_id already defined

        // Variables for "insert_actor_work"
        int id_actors = 6;
        int movie_id_movies_actor = 3;

        // Variables for "insert_director_work"
        int id_directors = 6;
        // movie_id_movies already defined

        // --------------------------------- EXECUTING PREPARED INSERT STATEMENTS USING VARIABLES ---------------------------------
        W.prepared("insert_location")(city)(state)(country)(location_id).exec();
        W.prepared("insert_university")(number_of_students_uni)(description_uni)(university_name)(is_public)(color)(location_uni).exec();
        W.prepared("insert_university_department")(number_of_students_dept)(description_dept)(department_name)(university_id).exec();
        W.prepared("insert_movie")(title)(release_date)(rating)(budget)(gross)(movie_id)(duration).exec();
        W.prepared("insert_director")(firstname_director)(surname_director)(birth_year_director)(birth_location_director)(university_department_id_director).exec();
        W.prepared("insert_actor")(firstname_actor)(surname_actor)(dob_actor)(eye_colour_actor)(birth_location_actor)(university_department_id_actor).exec();
        W.prepared("insert_genre")(genre)(genre_description)(genre_id).exec();
        W.prepared("insert_movie_genre")(movie_id)(genre_id).exec();
        W.prepared("insert_cinema")(cinema_id)(location_id)(cinema_name).exec();
        W.prepared("insert_showtime")(showtime_id)(showtime)(movie_id)(ticket_price)(cinema_id)(hall_type).exec();
        W.prepared("insert_award")(award_id)(award_name)(award_category).exec();
        W.prepared("insert_movie_award")(movie_id)(award_id).exec();
        W.prepared("insert_actor_work")(id_actors)(movie_id_movies_actor).exec();
        W.prepared("insert_director_work")(id_directors)(movie_id).exec();
        
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