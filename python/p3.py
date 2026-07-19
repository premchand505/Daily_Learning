class BankAcc:

    def __init__(self,owner, balance=0):
        self.owner = owner
        self.balance = balance
    def deposit(self,amount):
        self.balance += amount
        return self.balance

class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author

    def read(self):
        return f"Now reading: {self.title} by {self.author}"
    
book = Book("The Hobbit", "J.R.R. Tolkien")
print(book.read())  

account = BankAcc("Prem")
print(account.deposit(500))  
print(account.deposit(250))  