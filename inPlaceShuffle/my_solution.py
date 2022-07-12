# https://www.interviewcake.com/question/python3/shuffle
import random


def get_random(floor, ceiling):
    return random.randrange(floor, ceiling+1)


def shuffle(the_list):
    # Shuffle the input inplace
    for i in range(len(the_list)):
        random_index = get_random(i, len(the_list) - 1)
        the_list[i], the_list[random_index] = the_list[random_index], the_list[i]
