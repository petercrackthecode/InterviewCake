// link: https://www.interviewcake.com/question/cpp/inflight-entertainment?course=fc1&section=hashing-and-hash-tables
bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // determine if two movies add up to the flight length
    std::map<int, int> moviesMap;
    
    for (int movie : movieLengths) {
        ++moviesMap[movie];
    }
    
    for (auto movie : moviesMap) {
        if (moviesMap.count(flightLength - movie.first) != 0) {
            if (flightLength - movie.first == movie.first) {
                if (moviesMap[flightLength - movie.first] > 1) {
                    return true;
                }
            }
            else return true;
        }
    }

    return false;
}