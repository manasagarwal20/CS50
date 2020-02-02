SELECT title from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where name = "Helena Bonham Carter"
intersect
SELECT title from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where name = "Johnny Depp";