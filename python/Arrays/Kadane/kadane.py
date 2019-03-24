def kadane(list_of_number):
    max_sum = 0
    temporal_sum = 0
    for element in list_of_number:
        temporal_sum += element

        if temporal_sum < 0:
            temporal_sum = 0

        elif max_sum < temporal_sum:
            max_sum = temporal_sum

    return max_sum


def string_to_int_list(string):
    return [int(x) for x in string.split()]


if __name__ == '__main__':
    print(kadane(string_to_int_list('1 2 3 -2 5')))
    print(kadane(string_to_int_list('-1 -2 -3 -4')))

    a = [-2, -3, 4, -1, -2, 1, 5, -3]
    print(kadane(a))
