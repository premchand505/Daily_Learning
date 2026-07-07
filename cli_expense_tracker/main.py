import json 
import os
from datetime import datetime

Data_File = "expenses.json"


def main():
    print("welcome to expense tracker")

    while True:
        print("\n" + "-"*40)
        print("Commands : add | view | delete | quit")
        command = input("Enter command: ").strip().lower()

        if command == "add":
            add_expenses()
        elif command == "view":
            view_expenses()
        elif command == "delete":
            delete_expenses()
        elif command =="quit":
            print("Bye")
            break
        else:
            print("invalid command please try again")




# def add_expenses():

# def view_expenses():

# def delete_expenses():
