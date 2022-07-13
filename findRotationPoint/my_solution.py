import unittest
from typing import List


def find_rotation_point(words: List[str]) -> int:
    left = 0
    right = len(words) - 1

    while left <= right:
        mid = (right - left) // 2 + left
        if (mid <= 0 or words[mid] < words[mid - 1]) and \
                (mid >= len(words) - 1 or words[mid] < words[mid+1]):
            # Rotation point
            return mid

        if words[mid] < words[left]:
            # Move left
            right = mid - 1
        elif words[mid] > words[right]:
            # Move right
            left = mid + 1

    return -1


# Tests
class Test(unittest.TestCase):

    def test_small_list(self):
        actual = find_rotation_point(['cape', 'cake'])
        expected = 1
        self.assertEqual(actual, expected)

    def test_medium_list(self):
        actual = find_rotation_point(
            ['grape', 'orange', 'plum', 'radish', 'apple'])
        expected = 4
        self.assertEqual(actual, expected)

    def test_large_list(self):
        actual = find_rotation_point(['ptolemaic', 'retrograde', 'supplant',
                                      'undulate', 'xenoepist', 'asymptote',
                                      'babka', 'banoffee', 'engender',
                                      'karpatka', 'othellolagkage'])
        expected = 5
        self.assertEqual(actual, expected)


unittest.main(verbosity=2)
