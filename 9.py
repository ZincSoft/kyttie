import random

rng_min = 0
rng_max = 9
try_to_find = 9
in_a_row_target = 6
sample_size = 10
results = []

for i in range(0, sample_size):
    tries = 0
    in_a_row = 0

    while True:
        if random.randint(rng_min, rng_max) == try_to_find:
            in_a_row += 1
        else:
            in_a_row = 0

        tries += 1

        if in_a_row == in_a_row_target:
            results.append(tries)
            print("\r[" + str(i) + "/" + str(sample_size) + "]", end="")

            break

print("\rTook an average of " + str(sum(results) / len(results)) + " tries per iteration.")

