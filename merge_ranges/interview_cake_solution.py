# https://www.interviewcake.com/question/python3/merging-ranges?course=fc1&section=array-and-string-manipulation
def merge_range(meetings):

    # Sort by start time
    sorted_meetings = sorted(meetings)

    # Initialize merged_meetings with the earliest meeting
    merged_meetings = [sorted_meetings[0]]
    for current_meeting_start, current_meeting_end in sorted_meetings[1:]:
        last_merged_meeting_start, last_merged_meeting_end = merged_meetings[-1]

        # If the current meeting overlaps with the last merged meeting, use the later end
        # of the two
        if (current_meeting_start <= last_merged_meeting_end):
            merged_meetings[-1] = (last_merged_meeting_start,
                                   max(last_merged_meeting_end, current_meeting_end))
        else:
            # Add the current meeting since it doesn't overlap
            merged_meetings.append(
                (current_meeting_start, current_meeting_end))

    return merged_meetings


"""
Complexity: O(n lg n) time and O(n) space.
What we Learned:
  - This one arguably uses a greedy approach, except this time we have to sort the list first.
  - How did we figure that out?
  - We started off trying to solve the problem in one pass, and we noticed it wouldn't work. We
  then noticed the reason it wouldn't work: to see if a given meeting can be merged, we have to
  look at all the other meetings! That's because the order of the meetings is random.
  - That's what got us thinking: What we the list were sorted? we saw that then a greedy approach
  would work. We had to spend O(n lg n) time on sorting the list, but it was better than our
  initial brute force approach, which cost us O(n^2) time!
"""
