-- -- a.
-- -- i am simply using the average function to find the average age of
-- -- all actors in the actors table, there are no duplicates in the actor table
-- SELECT AVG(EXTRACT(YEAR FROM AGE(current_date, actors."date_of_birth"))) AS avg_age
-- FROM actors;

-- -- b.
-- WITH
--     MovieAActorBirthLocations AS (
--         SELECT actors."birth_location"
--         FROM movies
--         JOIN actor_work
--         ON movies."movie_id" = actor_work."movie_id_movies"
--         JOIN actors
--         ON actors."id" = actor_work."id_actors"
--         WHERE movies."title" = 'Movie A'
--     )

-- SELECT COUNT(DISTINCT locations."Country") AS numDiffCountries
-- FROM MovieAActorBirthLocations
-- JOIN locations
-- ON locations."location_Id" = MovieAActorBirthLocations."birth_location";

-- -- c.
-- SELECT COUNT(actors."eye_colour")
-- FROM actors
-- WHERE actors."eye_colour" = 'Green';

-- -- d.
-- SELECT COUNT(actor_work."movie_id_movies")
-- FROM actors
-- JOIN actor_work
-- ON actors."id" = actor_work."id_actors"
-- WHERE actors."firstname" = 'Anna' AND actors."surname" = 'Davis';

-- -- e.
-- SELECT genres.genre, MIN(movies.budget), MAX(movies.budget), AVG(movies.budget)
-- FROM movies
-- JOIN movie_genres
-- ON movies."movie_id" = movie_genres."movie_id"
-- JOIN genres
-- ON movie_genres."genre_id" = genres."genre_id"
-- GROUP BY genres.genre;

-- -- f.
-- SELECT AVG(movies."rating") AS avgMovieRating
-- FROM actors
-- JOIN actor_work ON actors."id" = actor_work."id_actors"
-- JOIN movies ON movies."movie_id" = actor_work."movie_id_movies"
-- JOIN locations ON actors."birth_location" = locations."location_Id"
-- WHERE actors."eye_colour" = 'Blue' OR locations."City" = 'Toronto';

-- -- g.
-- SELECT movies."title"
-- FROM movies
-- JOIN actor_work ON movies."movie_id" = actor_work."movie_id_movies"
-- JOIN actors ON actor_work."id_actors" = actors."id"
-- JOIN locations ON actors."birth_location" = locations."location_Id"
-- GROUP BY movies.title
-- HAVING COUNT(DISTINCT locations."Country") >= 2;

-- h.
SELECT 
    movies.title AS "Movie Title", 
    COUNT(movie_awards.award_id) AS "Award Count"
FROM 
    movies
LEFT JOIN 
    movie_awards ON movies.movie_id = movie_awards.movie_id
GROUP BY 
    movies.title
ORDER BY 
    "Award Count" DESC;
