def NULL_not_found(object: any) -> int:
    if isinstance(object, str) and object:
        print("Type not Found")
        return 1
    object_type = ""
    if object is None:
        object_type = "Nothing"
    elif isinstance(object, float):
        object_type = "Cheese"
    elif isinstance(object, bool) and object is False:
        object_type = "Fake"
    elif isinstance(object, int) and object == 0:
        object_type = "Zero"
    elif isinstance(object, str) and object == "":
        object_type = "Empty"
    print(object_type, end=": ")
    if object != "":
        print(object, end=" ")
    print(type(object))
    return 0
