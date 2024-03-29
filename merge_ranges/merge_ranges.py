# https://www.interviewcake.com/question/python3/merging-ranges?course=fc1&section=array-and-string-manipulation
import functools

meeting_blocks = [(1, 10), (2, 6), (3, 5), (7, 9)]


def comparator(m1, m2):
    # if two meetings have different start times, whichever start earlier will go first
    if m1[0] != m2[0]:
        return m1[0] - m2[0]

    # if two meetings have the same start times, whichever end earlier will go first
    return m1[1] - m2[1]


def is_intercepted(m1, m2) -> bool:
    return (m1[0] <= m2[0] and m2[0] <= m1[1]) or (m2[0] <= m1[0] and m1[0] <= m2[1])


def merge_ranges(meetings):
    if len(meetings) <= 1:
        return meetings

    # Merge meeting ranges
    sorted_meetings = sorted(meetings, key=functools.cmp_to_key(comparator))

    ans = [sorted_meetings[0]]

    for i in range(1, len(sorted_meetings)):
        ans_length = len(ans)
        # two meeting blocks ain't intercepted. We're not merging.
        # Just add a new block to the end of the answer array
        if not is_intercepted(ans[ans_length - 1], sorted_meetings[i]):
            ans.append(sorted_meetings[i])
            continue
        new_start_time = min(ans[ans_length - 1][0], sorted_meetings[i][0])
        new_end_time = max(ans[ans_length - 1][1], sorted_meetings[i][1])
        ans[ans_length - 1] = (new_start_time, new_end_time)

    return ans


print(merge_ranges(meeting_blocks))
