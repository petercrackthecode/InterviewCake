# https://www.interviewcake.com/question/python3/inflight-entertainment?course=fc1&section=hashing-and-hash-tables

def can_two_movies_fill_flight(movie_lengths, flight_length):

    # Determine if two movie runtimes add up to the flight length
    """
    flight_length: the sum of the length of two possible movies.
    Detect whether there is a pair of two distinctive numbers in movie_lengths that has the
    sum that is equal to flight_length
    """
    # Get the element with the smallest index in the array that has the movie length x
    movie_length_to_index = dict()

    for i, movie_length in enumerate(movie_lengths):
        if not movie_length in movie_length_to_index:
            movie_length_to_index[movie_length] = i

    for i, movie_length in enumerate(movie_lengths):
        other_movie_length = flight_length - movie_length
        if other_movie_length in movie_length_to_index and movie_length_to_index[other_movie_length] != i:
            return True

    return False
