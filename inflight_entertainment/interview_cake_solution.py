# https://www.interviewcake.com/question/python3/inflight-entertainment?course=fc1&section=hashing-and-hash-tables
"""
We make one pass through movie_lengths, treating each item as the first_movie_length.
At each iteration, we:
  1. See if there's a matching_second_movie_length we've seen already (stored in our
  movie_lengths_seen set) that is equal to flight_length - first_movie_length. If there is,
  we short-circuit and return True.
  2. Keep our movie_lengths_seen set up to date by throwing in the current first_movie_length.
  
  We know users won't watch the same movie twice because we check movie_lengths_seen
  for matching_second_movie_length before we've put first_movie_length in it!
"""


def can_two_movies_fill_flight(movie_lengths, flight_length):
    # Movie lenghts we've seen so far
    movie_lengths_seen = set()

    for first_movie_length in movie_lengths:
        matching_second_movie_length = flight_length - first_movie_length
        if matching_second_movie_length in movie_lengths_seen:
            return True
        movie_lengths_seen.add(first_movie_length)

    # We never found a match, so return False
    return False
