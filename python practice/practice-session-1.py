# x = 6
# label = "even" if x%2==0 else "odd"
# print(label)


# x = 0
# y = 1
# if x and y:
#     print('both')
# if x or y:
#     print('at least one')


# status = 4
# match status:
#     case 2:
#         print('two')
#     case 4:
#         print('four')
#     case 6:
#         print('six')
#     case _:
#         print('unknown')

# match None:
#     case None:
#         print('none')


# capture patterns
value = 6
match value:
    case x:
        print(x)

data = [1,2,3]
match data:
    case [a,b,c]:
        total = a+b+c
print(total)


items = [1,2,3,4]
match items:
    case [first, *rest]:
        print(first, rest)


def describe(seq):
    match seq:
        case []:
            return "empty"
        case [a]:
            return f"one: {a}"
        case [a,b]:
            return f"two: {a},{b}"
        case [a,b,*rest]:
            return f"many: {a}, {b}, rest = {rest}"

print(describe([]))
print(describe([4]))
print(describe([3,6]))
print(describe([2,3,4,5]))

match value:
    case x if x>0:
        print('positive')
    case x if x<0:
        print('negative')
    case _:
        print('unknown')

s = "Python"
print(s[::-1])
print("".join(reversed("Python")))