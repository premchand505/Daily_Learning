import json

def save_user(username, age):
    content ={
        "username" : username,
        "age" : age,
    }
    with open("user_data.json" ,"w") as file:
        json.dump(content,file)
    print(f"User data saved successfully for {username}")

def load_user():
    try:
        with open("user_data.json" , "r") as file:
            loaded_content = json.load(file)
            return loaded_content
    except FileNotFoundError:
        print(" No saved user data found. Returning empty profile")
        return {}
    finally:
        print("this is finnaly")