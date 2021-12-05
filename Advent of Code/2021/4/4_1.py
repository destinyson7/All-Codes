first = True

# matrices = []
# cnt = 0
# ind = 0
# cur_matrix = []

# where = []

# with open("in.txt") as f:
#     for line in f:
#         if line.split():
#             if first:
#                 nums = map(int, line.split(","))
#                 first = False

#             else:
#                 row = map(int, line.split(" "))
#                 cur_matrix.append(row)

#                 for i, cur in enumerate(row):
#                     where[cur].append({cnt, i})

#                 cnt += 1

#                 if cnt == 5:
#                     cnt = 0
#                     ind += 1
#                     matrices.append(cur_matrix)
#                     cur_matrix = []

# print(where)


with open("in.txt", "r") as f:
    for line in f:
        line = line.strip(" ")
        if line.strip():
            if first:
                first = False
                nums = map(int, line.split(","))

                for i in nums:
                    print(i)

                print(-1)

            else:
                row = line.strip("\n").split(" ")

                for i in row:
                    if i.strip():
                        print(i.strip())
