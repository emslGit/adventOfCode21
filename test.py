def check_null(func):
    print("Checking null")
    return lambda a, b: func(a, b) if b > 0 else -1


@check_null
def div(a, b):
    return a / b


print(div(10, 0))
