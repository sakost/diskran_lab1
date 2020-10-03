import sys
import random

TEST_COUNT = 8


def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <test directory>")
        sys.exit(1)

    test_dir = sys.argv[1]

    lines = []
    lines.extend([10 ** i for i in range(TEST_COUNT)])

    for enum, test_count in enumerate(range(1, TEST_COUNT + 1)):
        test = []

        line_count = lines[enum]
        for _ in range(line_count):
            key = random.randint(0, 2**64 - 1)
            value = random.randint(0, 2**64 - 1)
            test.append((key, value))

        test_name = "{}/{:02d}".format(test_dir, test_count)
        with open(f'{test_name}.t', 'w') as ftest:
            for key, value in test:
                ftest.write(f'{key} {value}\n')

        answer = sorted(test, key=lambda x: x[0])
        with open(f'{test_name}.a', 'w') as ftest:
            for key, value in answer:
                ftest.write(f'{key} {value}\n')


main()
