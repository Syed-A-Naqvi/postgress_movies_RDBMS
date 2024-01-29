-- a.
-- Listing the first and last names of all directors born in Canada
SELECT directors."firstname", directors."surname"
    FROM directors
    JOIN locations
    ON directors."birth_location" = locations."location_Id"
    WHERE locations."Country" = 'Canada';

-- b.
-- Listing all movie titles directed by director 'John Doe' 
SELECT title
    FROM directors
    JOIN director_work
    ON directors."id" = director_work."id_directors"
    JOIN movies
    ON director_work."movie_id_movies" = movies."movie_id"
    WHERE directors."firstname" = 'John'
        AND directors."surname" = 'Doe';

-- c.
    -- Movie costs above 1M in other currencies
    SELECT firstname, surname, title, 1.38 * budget AS cost_in_CAD, 150.32 * budget AS cost_in_JPY, 92.60 * budget AS cost_in_RUB, 0.94 * budget AS cost_in_EUR, 0.90 * budget AS cost_in_CHF
        FROM actors
        JOIN actor_work
        ON actors."id" = actor_work."id_actors"
        JOIN movies
        ON actor_work."movie_id_movies" = movies."movie_id"
        WHERE movies."budget">1000000;


-- d.
-- Listing all directors with surname beginning with A and D
SELECT firstname, surname
    FROM directors
    WHERE surname LIKE 'A%' OR surname LIKE 'D%';

-- e.
-- Finding all the comedy movies in which there is a playing actor
-- who is less than 40        
WITH
    under40Actors AS (
        SELECT "id"
        FROM actors
        WHERE (EXTRACT(YEAR FROM AGE(current_date, actors."date_of_birth"))) < 40
    ),

    comedyMovies AS (
        SELECT "movie_id"
        FROM movie_genres
        JOIN genres
        ON movie_genres."genre_id" = genres."genre_id"
        WHERE genres.genre = 'Comedy'
    )

    SELECT DISTINCT movies.title
        FROM movies
        JOIN comedyMovies ON comedyMovies."movie_id" = movies."movie_id"
        JOIN actor_work ON actor_work."movie_id_movies" = movies."movie_id"
        JOIN under40Actors ON under40Actors."id" = actor_work."id_actors";

--f.
SELECT a1.firstname, a2.firstname
    FROM actors AS a1
    JOIN actors AS a2
    ON a1.id != a2.id
    WHERE a1.eye_colour = 'Blue' AND a2.eye_colour = 'Blue'
    AND a1.firstname <= a2.firstname;