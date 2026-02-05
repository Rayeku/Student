def all_thing_is_obj(object: any) -> int:
    if isinstance(object, str):
        print(object + " is in the kitchen " + ":", type(object))
    elif isinstance(object, int):
        print("Type not found")
    else:
        print(type(object).__name__.capitalize() + " :", type(object))
    return 42

# def all_thing_is_obj(object: any) -> int:
#     if (object == list):
#         print("List : <")
# Go fix
