def continuous_sub_array_sum(list_of_number, sum):
    first_index = 0
    second_index = 0
    temporal_sum = 0
    while (second_index >= first_index):
        if temporal_sum < sum:
            temporal_sum += list_of_number[second_index]
            second_index += 1
        elif temporal_sum > sum:
            temporal_sum -= list_of_number[first_index]
            first_index += 1

        if temporal_sum == sum:
            break

    return first_index + 1, second_index


if __name__ == '__main__':
    print(*continuous_sub_array_sum([1, 2, 3, 7, 5], 12))
    print(*continuous_sub_array_sum([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 15))
