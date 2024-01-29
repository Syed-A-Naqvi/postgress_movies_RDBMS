--MOVIES
INSERT INTO public."Movie" (title, run_time, release_date, rating, budget, gross) VALUES 
('The Shawshank Redemption', '02:22:00', '1994-10-14', 9.3, 25000000, 28884716), --1
('The Dark Knight', '02:32:00', '2008-07-18', 9.0, 185000000, 1007257536), --2
('Inception', '02:28:00', '2010-07-16', 8.8, 160000000, 839030630), --3
('Interstellar', '02:49:00', '2014-11-07', 8.7, 165000000, 703170837), --4
('Se7en', '02:07:00', '1995-09-22', 8.6, 33000000, 327333559); --5

-- ACTORS BIRTH LOCATIONS
INSERT INTO public."BirthLocation" (city, state, country) VALUES 
('West Covina', 'California', 'USA'), --1
('Haverfordwest', 'Pembrokeshire', 'UK'), --2
('Perth', 'Western Australia', 'Australia'), --3
('Memphis', 'Tennessee', 'USA'), --4
('Los Angeles', 'California', 'USA'), --5
('Douglas', 'County Cork', 'Ireland'), --6
('Uvalde', 'Texas', 'USA'), --7
('Brooklyn', 'New York', 'USA'), --8
('Montbéliard', 'Doubs', 'France'), --9
('Denver', 'Colorado', 'USA'), --10
('Knoxville', 'Tennessee', 'USA'), --11
('Houston', 'Texas', 'USA'), --12
('Trois-Rivières', 'Quebec', 'Canada'); --13

--ACTORS
INSERT INTO public."Actor" (first_name, surname, year_of_birth, "id_BirthLocation", eye_color) VALUES 
('Tim', 'Robbins', 1958, 1, 'Blue'), --1
('Christian', 'Bale', 1974, 2, 'Hazel'), --2
('Heath', 'Ledger', 1979, 3, 'Brown'), --3
('Morgan', 'Freeman', 1937, 4, 'Brown'), --4
('Leonardo', 'DiCaprio', 1974, 5, 'Blue'), --5
('Joseph', 'Gordon-Levitt', 1981, 5, 'Brown'), --6
('Cillian', 'Murphy', 1976, 6, 'Blue'), --7
('Matthew', 'McConaughey', 1969, 7, 'Green'), --8
('Anne', 'Hathaway', 1982, 8, 'Brown'); --9

--UNIVERSITIES
INSERT INTO public."University" (uni_name, is_private, color) VALUES 
('University of Texas at Austin', FALSE, 'Burnt Orange'), --1
('Université du Québec à Montréal', FALSE, 'Red'), --2
('Harvard University', TRUE, 'Crimson'), --3
('University of California, Los Angeles', FALSE, 'Blue and Gold'), --4
('University of Oxford', FALSE, 'Navy Blue'); --5

--DIRECTORS
INSERT INTO public."Director" (first_name, surname, year_of_birth, "id_BirthLocation", "id_Movie", "id_University") VALUES 
('Frank', 'Darabont', 1959, 9, 1, NULL), --1
('David', 'Fincher', 1962, 10, 5, NULL), --2
('Quentin', 'Tarantino', 1963, 11, NULL, NULL), --3
('Wes', 'Anderson', 1969, 12, NULL, 1), --4
('Denis', 'Villeneuve', 1967, 13, NULL, 2); --4

--DEPARTMENTS FOR EACH UNIVERSITY
INSERT INTO public."Department" ("id_University", name) VALUES 
(1, 'Radio-Television-Film'), --1
(2, 'Theatre Arts'), --2
(3, 'Visual and Environmental Studies'), --3
(4, 'School of Theater, Film and Television'), --4
(5, 'Film Aesthetics'); --5

--MOVIE ACTORS
INSERT INTO public."MovieActor" ("id_Movie", "id_Actor") VALUES 
(1, 1), -- The Shawshank Redemption, Tim Robbins
(1, 4), -- The Shawshank Redemption, Morgan Freeman
(2, 2), -- The Dark Knight, Christian Bale
(2, 3), -- The Dark Knight, Heath Ledger
(2, 7), -- The Dark Knight, Cillian Murphy
(3, 5), -- Inception, Leonardo DiCaprio
(3, 6), -- Inception, Joseph Gordon-Levitt
(3, 7), -- Inception, Cillian Murphy
(4, 8), -- Interstellar, Matthew McConaughey
(4, 9), -- Interstellar, Anne Hathaway
(5, 4); -- Se7en, Morgan Freeman


--GENRES
INSERT INTO public."Genre" (type) VALUES 
    ('Drama'), --1
    ('Action'), --2
    ('Crime'), --3
    ('Thriller'), --4
    ('Sci-Fi'), --5
    ('Adventure'), --6
    ('Mystery'), --7
    ('Fantasy'), --8
    ('Horror'), --9
    ('Romance'); --10


--MOVIE GENRES
INSERT INTO public."MovieGenre" ("id_Movie", "id_Genre") VALUES 
    (1, 1), -- The Shawshank Redemption, Drama
    (2, 2), -- The Dark Knight, Action
    (2, 3), -- The Dark Knight, Crime
    (2, 4), -- The Dark Knight, Thriller
    (3, 2), -- Inception, Action
    (3, 5), -- Inception, Sci-Fi
    (3, 6), -- Inception, Adventure
    (4, 1), -- Interstellar, Drama
    (4, 5), -- Interstellar, Sci-Fi
    (5, 3), -- Se7en, Crime
    (5, 4), -- Se7en, Thriller
    (5, 7); -- Se7en, Mystery


INSERT INTO public."Cinema"(cinema_name, location, type) VALUES
    ('Cineplex', 'Ajax', 'regular'), --1
    ('IMAX', 'Scarborough', 'large'), --2
    ('Silvercity', 'Pickering', 'small'), --3
    ('Cineplex', 'Oshawa', 'Large'), --4
    ('Cineplex', 'Bowmanville', 'Extralarge'); --5


INSERT INTO public."Ticket" (price, "id_Cinema") VALUES 
    ( 8.00,  1), --1
    (16.00,  2), --2
    ( 6.00,  3), --3
    (16.00,  4), --4
    (18.00,  5); --5


INSERT INTO public."ShowTime" (show_name, show_time, show_duration, "id_Cinema_Ticket", "id_Movie") VALUES
    ('The Shawshank Redemption', '09:00:00', '02:22:00', 2, 1),
    ('The Dark Knight', '11:00:00', '02:32:00', 1, 2),
    ('Inception', '11:30:00', '02:28:00', 3, 3),
    ('Interstellar', '03:00:00', '02:49:00', 5, 4),
    ('Se7en', '05:00:00', '02:07:00', 4, 5);


INSERT INTO public."Award" (award_name, "id_Movie") VALUES 
('National Board of Review: Top Ten Films', 1),   -- The Shawshank Redemption
('Academy Award (Oscar)', 2),  -- The Dark Knight (for Heath Ledger)
('Academy Award (Oscar)', 3),    -- Inception
('Academy Award (Oscar)', 4),    -- Interstellar
('MTV Movie Award', 5);         -- Se7en


INSERT INTO public."Category" (category_name, "award_id_Award") VALUES
    ('Best Film', 1),
    ('Best Supporting Actor', 2),
    ('Best Visual Effects', 3),
    ('Best Visual Effects', 4),
    ('Best Villan', 5);