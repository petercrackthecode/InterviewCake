import functools

meeting_blocks = [(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)]


def comparator(m1, m2):
    # if two meetings have different start times, whichever start earlier will go first
    if m1[0] != m2[0]:
        return m1[0] - m2[0]

    # if two meetings have the same start times, whichever end earlier will go first
    return m1[1] - m2[1]


def is_intercepted(m1, m2) -> bool:
    print("m1 = ", m1, ", m2 = ", m2)
    return (m1[0] <= m2[0] and m2[0] <= m1[1]) or (m2[0] <= m1[0] and m1[0] <= m2[1])


def merge_ranges(meetings):
    if len(meetings) <= 1:
        return meetings

    # Merge meeting ranges
    sorted_meetings = sorted(meetings, key=functools.cmp_to_key(comparator))
    print("sorted_meetings = ", sorted_meetings)

    ans = [sorted_meetings[0]]

    for i in range(1, len(sorted_meetings)):
        ans_length = len(ans)
        # two meeting blocks ain't intercepted. We're not merging.
        # Just add a new block to the end of the answer array
        try:
            if not is_intercepted(ans[ans_length - 1], sorted_meetings[i]):
                ans.append(sorted_meetings[i])
                continue
            new_start_time = min(ans[ans_length - 1][0], sorted_meetings[i][0])
            new_end_time = max(ans[ans_length - 1][1], sorted_meetings[i][1])
            ans[ans_length - 1] = (new_start_time, new_end_time)
        except:
            print(f"Failed at index {i}, ans = ", ans)

    return ans


print(merge_ranges(meeting_blocks))
