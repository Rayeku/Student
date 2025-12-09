def all_thing_is_obj(object: any) -> int:
    if (type(object) is str):
        print(object + " is in the kitchen " + ":", type(object))
    elif (type(object) is int):
        print("Type not found")
    else:
        print(type(object).__name__.capitalize() + " :", type(object))
    return 42

# def all_thing_is_obj(object: any) -> int:
#     if (object == list):
#         print("List : <")
# Go fix
