def NULL_not_found(object: any) -> int:
    object_type = ""
    if (type(object) is str and object):
        print("Type not Found")
        return 1
    elif (object is None):
        object_type = "Nothing"
    elif (type(object) is float):
        object_type = "Cheese"
    elif (type(object) is int and object == 0):
        object_type = "Zero"
    elif (type(object) is str and object == ""):
        object_type = "Empty"
    elif (type(object) is bool and object is False):
        object_type = "Fake"
    print(object_type, end=": ")
    if (object != ""):
        print(object, end=" ")
    print(type(object))
    return 0
