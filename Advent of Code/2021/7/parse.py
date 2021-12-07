with open("in.txt", "r") as f:
    for line in f:
        line = line.split(",")

        for num in line:
            print(int(num.strip()))
