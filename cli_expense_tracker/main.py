import json
import os
from datetime import datetime

DATA_FILE = "expenses.json"


# ====================== HELPER FUNCTIONS ======================

def load_expenses():
    """Load expenses from JSON file. Return empty list if file doesn't exist."""
    if not os.path.exists(DATA_FILE):
        return []
    
    try:
        with open(DATA_FILE, "r") as file:
            return json.load(file)
    except (json.JSONDecodeError, FileNotFoundError):
        return []


def save_expenses(expenses):
    """Save expenses list to JSON file."""
    with open(DATA_FILE, "w") as file:
        json.dump(expenses, file, indent=4)


def generate_id():
    """Generate a simple unique ID based on timestamp."""
    return int(datetime.now().timestamp())


# ====================== CORE FUNCTIONS ======================

def add_expense():
    """Add a new expense."""
    description = input("Enter expense description: ").strip()
    if not description:
        print("Description cannot be empty!")
        return
    
    try:
        amount = float(input("Enter amount: "))
        if amount <= 0:
            print("Amount must be positive!")
            return
    except ValueError:
        print("Invalid amount!")
        return
    
    category = input("Enter category (e.g., Food, Transport, Rent): ").strip()
    
    expense = {
        "id": generate_id(),
        "date": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
        "description": description,
        "amount": amount,
        "category": category or "Miscellaneous"
    }
    
    expenses = load_expenses()
    expenses.append(expense)
    save_expenses(expenses)
    
    print("Expense added successfully!")


def view_expenses():
    """Display all expenses."""
    expenses = load_expenses()
    
    if not expenses:
        print("No expenses found.")
        return
    
    print("\n" + "="*60)
    print("ALL EXPENSES")
    print("="*60)
    
    total = 0
    for exp in expenses:
        print(f"ID: {exp['id']}")
        print(f"Date: {exp['date']}")
        print(f"Description: {exp['description']}")
        print(f"Amount: ₹{exp['amount']:.2f}")
        print(f"Category: {exp['category']}")
        print("-" * 40)
        total += exp['amount']
    
    print(f"\nTotal Expenses: ₹{total:.2f}")
    print("="*60)


def delete_expense():
    """Delete an expense by ID."""
    try:
        expense_id = int(input("Enter Expense ID to delete: "))
    except ValueError:
        print("Invalid ID!")
        return
    
    expenses = load_expenses()
    initial_length = len(expenses)
    expenses = [exp for exp in expenses if exp["id"] != expense_id]
    
    if len(expenses) < initial_length:
        save_expenses(expenses)
        print("Expense deleted successfully!")
    else:
        print("Expense with that ID not found!")


# ====================== MAIN APPLICATION LOOP ======================

def main():
    print("Welcome to CLI Expense Tracker!")
    
    while True:
        print("\n" + "-"*40)
        print("Commands: add | view | delete | quit")
        command = input("Enter command: ").strip().lower()
        
        if command == "add":
            add_expense()
        elif command == "view":
            view_expenses()
        elif command == "delete":
            delete_expense()
        elif command == "quit":
            print("👋 Goodbye!")
            break
        else:
            print("Invalid command! Please try again.")


# Run the program
if __name__ == "__main__":
    main()